#include "trie.h"
#include "trie_test.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, const char *argv[]) {
    Trie trie;

    // Choisir la version à utiliser en fonction de la macro définie
#ifdef MATRICE
    printf("Utilisation de la version MATRICE...\n");
    trie = createTrie(50);  // Créer un trie pour la version matrice
#elif defined(HACHAGE)
    printf("Utilisation de la version HACHAGE...\n");
    trie = createTrie(50);  // Créer un trie pour la version hachage
#endif

    if (testInsertInTrie(trie)) {
        printf("Le test d'insertion dans le trie a reussi.\n");
    } else {
        printf("Le test d'insertion dans le trie a echoue.\n");
    }

    if (testInsertPrefixTrie()) {
        printf("Le test d'insertion des prefixes a reussi.\n");
    } else {
        printf("Le test d'insertion des prefixes a echoue.\n");
    }

    if (testInsertSufixTrie()) {
        printf("Le test d'insertion des suffixes a reussi.\n");
    } else {
        printf("Le test d'insertion des suffixes a echoue.\n");
    }
    if (testInsertFactTrie()) {
        printf("Le test d'insertion des facteurs a reussi.\n");
    } else {
        printf("Le test d'insertion des facteurs a echoue.\n");
    }

    // Si des mots sont passés en arguments, les insérer dans le trie
    size_t wordsLength = 1;  // Pour compter les mots
    for (int i = 1; i < argc; i++) {
        wordsLength += strlen(argv[i]);
    }
    trie = createTrie((int) wordsLength);  // Créer un nouveau trie avec la longueur totale des mots

    // Insérer les mots dans le trie
    for (int i = 1; i < argc; i++) {
        printf("Insertion du mot : %s \n", argv[i]);
        insertInTrie(trie, (unsigned char *)argv[i]);
    }

    // Vérifier si les mots sont dans le trie
    for (int i = 1; i < argc; i++) {
        if (isInTrie(trie, (unsigned char *)argv[i])) {
            printf("Le mot '%s' est dans le trie.\n", argv[i]);
        } else {
            printf("Le mot '%s' n'est pas dans le trie.\n", argv[i]);
        }
    }


    return EXIT_SUCCESS;
}
