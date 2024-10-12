#ifndef TRIE_H
#define TRIE_H

#include "table_hashage.h"

#ifdef MATRICE
    struct _trie {
    int maxNode; /* Nombre maximal de noeuds du trie */
    int nextNode; /* Indice du prochain noeud disponible */
    int **transition; /* matrice de transition */
    char *finite; /* etats terminaux */
    };

#elif defined(HACHAGE)
    struct _trie {
        int maxNode;        /* Nombre maximal de noeuds du trie */
        int nextNode;       /* Indice du prochain noeud disponible */
        List *transition;   /* listes d’adjacence */
        char *finite;       /* etats terminaux */
    };

#endif
typedef struct _trie *Trie ; // ceci est un pointeur vers la structure de donnée trie

/**
 * Cette prémitive permet de créer un trie qui sera vide initialement
 * Elle prend en paramétre un entier maxNode qui représente le nombre maximum 
 * de noeuds que notre trie aura 
 * */
Trie createTrie(int maxNode);

/**
 * Cette prémitive permet d'insérer le mot w dans le trie si il n'est pas dejà présent.
 * Elle prend en entrée le trie ainsi que le mot w  
 * */
void insertInTrie(Trie trie, unsigned char *w);

/**
 * Cette prémitive retourne 1 si le mot w existe dans le trie, sinon elle retourne 0.
 * */

int isInTrie(Trie trie, unsigned char *w);

// _____________________________________Exercice2_____________________________________________


/**
 * Cette prémitive permet d'inserer successivement les prefixes d'un mot.
* */

void insertPrefixInTrie(Trie trie, unsigned char *w);

void insertSuffixInTrie(Trie trie, unsigned char *w);

void insertFactInTrie(Trie trie, unsigned char *w);






#endif