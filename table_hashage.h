#ifndef HACHAGE_H
#define HACHAGE_H

struct _list {
    int startNode;       // État de départ de la transition
    int targetNode;      // Cible de la transition
    unsigned char letter; // Lettre de la transition
    struct _list *next;  // Maillon suivant dans la liste
};

typedef struct _list *List;


typedef struct _trie *Trie;


extern int fonctionDeHashage(unsigned char w, int maxNode);
/**
 * Retourne le prochain état de l'automate trie passant par l'étiquette w
 * à l'état state. Si la transition n'existe pas retourne -1. 
 */
extern int search(Trie trie, int state, unsigned char w);

/** Ajoute la transition à l'automate
 * (currrentState, w, trie->nextNode) à l'automate trie.
 * */
extern void updateState(Trie trie, int currentState, unsigned char w);

#endif