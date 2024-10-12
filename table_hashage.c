#include <stdio.h>
#include <stdlib.h>
#include "table_hashage.h"
#include "trie.h"


/**
 * La fonction de hachage nous permet de convertir le caractére w
 * en un indexe dans la table de transition 
 * Cet index sera compris entre 0 et maxNode-1
 */
int fonctionDeHashage(unsigned char w, int maxNode) {
    return w % maxNode;  // La fonction de hachage simple
}
/**
 * La fonction search nous permet de rechercher si une transition 
 * existe dans notre trie
 *  Faut d'abord voir si notre liste n'est pas vide
 * puis vérifier si notre element courant correspond bien a la lettre recherché
 * si oui on retourne le noeud cible
 * sinon notre fonction retourn -1 
 */
int search(Trie trie, int state, unsigned char w){
    int index = fonctionDeHashage(w,trie->maxNode);

    List currentElement = trie->transition[index]; //L'élément courant
    while (currentElement != NULL ){
        if(currentElement->letter == w){
            return currentElement->targetNode;
        }
        currentElement = currentElement->next;
    }

    return -1;
    

}

/**
 * La fonction updateState permet d'ajouter une transition a notre trie
 */
void updateState(Trie trie, int currentState, unsigned char w){
     int index = fonctionDeHashage(w,trie->maxNode);

      List cellule = (List)malloc(sizeof(struct _list));

     if(cellule == NULL){
        fprintf(stderr, "Échec de l'allocation mémoire pour la liste des transitions\n");
        exit(EXIT_FAILURE);
     }

     // Remplir les champs de la cellule (maillon de la liste)
     cellule->startNode = currentState;
     cellule->targetNode = trie->nextNode;
     cellule->letter = w;
     cellule->next = trie->transition[index];
     
     trie->transition[index] = cellule; // Mise à jour de la tête de la liste chaînée pour le nœud courant
     trie->nextNode++;// Incrémenter nextNode pour le prochain état à ajouter


}