#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <limits.h> // Pour pouvoir utiliser UCHAR_MAX
#include "table_hashage.h"
#include "trie.h"

// Fonction pour créer un trie (matrice ou hachage)
Trie createTrie(int maxNode) {
    if (maxNode <= 0) { // Vérification de l'entrée maxNode.
        fprintf(stderr, "Erreur: maxNode doit être supérieur à 0.\n");
        exit(EXIT_FAILURE);
    }

    Trie trie = (Trie)malloc(sizeof(struct _trie));

    if (trie == NULL) { // Échec de l'allocation.
        fprintf(stderr, "Erreur: échec de l'allocation mémoire pour le trie.\n");
        exit(EXIT_FAILURE);
    }

    trie->maxNode = maxNode;
    trie->nextNode = 1; // Le prochain indice qui sera disponible dans le trie est 1.

#ifdef MATRICE
    trie->transition = (int **)malloc(sizeof(int *) * UCHAR_MAX); // Allocation dynamique de la matrice de transitions.

    if (trie->transition == NULL) { // Échec de l'allocation.
        fprintf(stderr, "Erreur: échec de l'allocation mémoire pour la matrice de transition.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < UCHAR_MAX; i++) { // Allocation de chaque ligne de la matrice.
        trie->transition[i] = (int *)malloc(sizeof(int) * maxNode);
        if (trie->transition[i] == NULL) {
            fprintf(stderr, "Erreur: allocation de mémoire échouée pour la ligne %d de la matrice de transitions.\n", i);
            exit(EXIT_FAILURE);
        }
    }

    // Initialisation de la matrice de transitions à -1 (aucune transition initialement)
    for (int j = 0; j < UCHAR_MAX; ++j) {
        for (int i = 0; i < maxNode; ++i) {
            trie->transition[j][i] = -1;
        }
    }
#else
    trie->transition = (List *)malloc(sizeof(List) * maxNode);
    if (trie->transition == NULL) {
        fprintf(stderr, "Erreur: échec de l'allocation mémoire pour les transitions.\n");
        exit(EXIT_FAILURE);
    }

    // Initialisation de la liste des transitions à NULL (aucune transition au départ)
    for (int i = 0; i < maxNode; i++) {
        trie->transition[i] = NULL;
    }
#endif

    trie->finite = (char *)calloc((size_t)maxNode, sizeof(char));
    if (trie->finite == NULL) {
        fprintf(stderr, "Erreur: échec de l'allocation mémoire pour les états terminaux.\n");
        exit(EXIT_FAILURE);
    }

    return trie;
}

// Insertion d'un mot dans le trie (matrice ou hachage)
void insertInTrie(Trie trie, unsigned char *w) {
    if (isInTrie(trie, w)) {
        return; // Si le mot existe déjà, ne rien faire
    }

    int currentState = 0;
    while (*w != '\0') {
        unsigned char letter = *w; // Récupérer le caractère actuel

#ifdef MATRICE
        // Si la transition existe, aller à l'état suivant
        if (trie->transition[letter][currentState] != -1) {
            currentState = trie->transition[letter][currentState];
        } else {
            // Ajouter une nouvelle transition
            if (trie->nextNode >= trie->maxNode) {
                fprintf(stderr, "Nombre maximal de nœuds atteint dans le trie\n");
                exit(EXIT_FAILURE);
            }
            trie->transition[letter][currentState] = trie->nextNode;
            currentState = trie->nextNode;
            trie->nextNode += 1;
        }
#else
        // Gestion de la table de hachage (chaînage séparé)
        int index = fonctionDeHashage(letter, trie->maxNode);
        List temp = trie->transition[index];
        int found = 0;

        // Chercher la transition
        while (temp != NULL) {
            if (temp->startNode == currentState && temp->letter == letter) {
                currentState = temp->targetNode;
                found = 1;
                break;
            }
            temp = temp->next;
        }

        if (!found) {
            updateState(trie, currentState, letter);  // Ajouter une nouvelle transition
            currentState = trie->nextNode - 1;
        }
#endif

        ++w;  // Passer au prochain caractère
    }

    // Marquer l'état final
    trie->finite[currentState] = 1;
}

// Recherche d'un mot dans le trie (matrice ou hachage)
int isInTrie(Trie trie, unsigned char *w) {
    int currentState = 0;
    while (*w != '\0') {
        unsigned char letter = *w; // Récupérer le caractère actuel

#ifdef MATRICE
        // Si la transition existe, aller au prochain état
        if (trie->transition[letter][currentState] != -1) {
            currentState = trie->transition[letter][currentState];
        } else {
            return 0;  // Mot non trouvé
        }
#else
        // Recherche dans la table de hachage (chaînage séparé)
        int index = fonctionDeHashage(letter, trie->maxNode);
        List temp = trie->transition[index];

        while (temp != NULL) {
            if (temp->startNode == currentState && temp->letter == letter) {
                currentState = temp->targetNode;
                break;
            }
            temp = temp->next;
        }

        if (temp == NULL) {
            return 0;  // Mot non trouvé
        }
#endif

        ++w;  // Passer au prochain caractère
    }

    return trie->finite[currentState];  // Retourner 1 si l'état final est terminal
}


void insertPrefixInTrie(Trie trie, unsigned char *w){
    unsigned char *word = (unsigned char *) calloc(strlen((const char *)w),
    sizeof(char));
    if (word == NULL) {
    return;
    }
    for (size_t i = 0; w[i] != '\0'; ++i) {
        word[i] = w[i];
        insertInTrie(trie, word);
    }
}

void insertSuffixInTrie(Trie trie, unsigned char *w){
    size_t lenWord = strlen((const char *)w);  // Calculer la longueur du mot

    // Boucle pour insérer chaque suffixe
    for (size_t i = 0; i < lenWord; ++i) {
        insertInTrie(trie, w + i); 
    }
}


void insertFactInTrie(Trie trie, unsigned char *w){

    insertSuffixInTrie(trie, w);// Insertion de tous les suffixes

    size_t lenWord = strlen((const char *) w);// Récupérer la longueur du mot

    // Pour chaque suffixe, insérer ses préfixes
    for (size_t i = 0; i < lenWord; ++i) {
        insertPrefixInTrie(trie, w + i);
    }
}


