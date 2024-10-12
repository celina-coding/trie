#include "trie.h"
#include <stdio.h>

int testInsertInTrie(){
    Trie trie =createTrie(60);

    insertInTrie(trie,(unsigned char*) "acagt");
    insertInTrie(trie,(unsigned char*) "acgt");
    insertInTrie(trie,(unsigned char*) "cagt");
    printf("les mots inseres sont : acagt, acgt, cagt \n");
    printf("La fonction isInTrie =%d  alors les mots sont dans le trie .\n",
        isInTrie(trie, (unsigned char*) "acagt") &&
        isInTrie(trie, (unsigned char*) "acgt") &&
        isInTrie(trie, (unsigned char*) "cagt")
    );
    return isInTrie(trie, (unsigned char*) "acagt") &&
        isInTrie(trie, (unsigned char*) "acgt") &&
        isInTrie(trie, (unsigned char*) "cagt");
}


int testInsertPrefixTrie() {
  Trie trie_pref = createTrie(100);
printf(" on teste sur les prefixes du mot acagt\n");
insertPrefixInTrie(trie_pref, (unsigned char*) "acagt");
printf("insertPrefixInTrie =%d  alors l'un des  prefixes suivants:a,ac,ca,aca ne sont pas dans le trie_pref\n",
isInTrie(trie_pref, (unsigned char*) "a") &&
    isInTrie(trie_pref, (unsigned char*) "ac") &&
    isInTrie(trie_pref, (unsigned char*) "ca") &&
    isInTrie(trie_pref, (unsigned char*) "aca")

);
printf(" on teste sur les prefixes du mot informatique\n");
  insertPrefixInTrie(trie_pref, (unsigned char*) "informatique");
printf("insertPrefixInTrie =%d  alors les prefixes suivants:i,in,inf,info,infor,informatique sont dans le trie_pref\n",
isInTrie(trie_pref, (unsigned char*) "i") &&
    isInTrie(trie_pref, (unsigned char*) "in") &&
    isInTrie(trie_pref, (unsigned char*) "inf") &&
    isInTrie(trie_pref, (unsigned char*) "info") &&
    isInTrie(trie_pref, (unsigned char*) "infor") &&
    isInTrie(trie_pref, (unsigned char*) "informatique") 

);

  return isInTrie(trie_pref, (unsigned char*) "i") &&
    isInTrie(trie_pref, (unsigned char*) "in") &&
    isInTrie(trie_pref, (unsigned char*) "inf") &&
    isInTrie(trie_pref, (unsigned char*) "info") &&
    isInTrie(trie_pref, (unsigned char*) "infor") &&
    isInTrie(trie_pref, (unsigned char*) "informatique") ;
}

int testInsertSufixTrie() {
printf(" on teste sur les suffixes du mot algorithmique\n");
  Trie trie_suf = createTrie(100);
  insertSuffixInTrie(trie_suf, (unsigned char*) "algorithmique");
printf("insertSufixTrie =%d  alors les suffixes suivants:mique,e,ue,que,rithmique,algorithmique sont dans le trie_suf\n",
isInTrie(trie_suf, (unsigned char*) "mique") &&
    isInTrie(trie_suf, (unsigned char*) "e") &&
    isInTrie(trie_suf, (unsigned char*) "ue") &&
    isInTrie(trie_suf, (unsigned char*) "que") &&
    isInTrie(trie_suf, (unsigned char*) "rithmique") &&
    isInTrie(trie_suf, (unsigned char*) "algorithmique") 

);
  return isInTrie(trie_suf, (unsigned char*) "e") &&
    isInTrie(trie_suf, (unsigned char*) "ue") &&
    isInTrie(trie_suf, (unsigned char*) "que") &&
    isInTrie(trie_suf, (unsigned char*) "rithmique") &&
    isInTrie(trie_suf, (unsigned char*) "algorithmique");
}

int testInsertFactTrie() {
printf(" on teste sur les facteurs du mot informatique \n");
  Trie trie_fact = createTrie(100);
  insertFactInTrie(trie_fact, (unsigned char*) "informatique");
  printf("insertFactInTrie =%d  alors les facteurs suivants:e,ue,que,formatique,tique,algorithmique, i, in, inf, inform, informatique, o, orm, orma, tique sont dans le trie_fact\n",isInTrie(trie_fact, (unsigned char*) "e") &&
    isInTrie(trie_fact, (unsigned char*) "ue") &&
    isInTrie(trie_fact, (unsigned char*) "que") &&
    isInTrie(trie_fact, (unsigned char*) "formatique") &&
    isInTrie(trie_fact, (unsigned char*) "tique") &&
    isInTrie(trie_fact, (unsigned char*) "i") &&
    isInTrie(trie_fact, (unsigned char*) "in") &&
    isInTrie(trie_fact, (unsigned char*) "inf") &&
    isInTrie(trie_fact, (unsigned char*) "inform") &&
    isInTrie(trie_fact, (unsigned char*) "informatique") &&
    isInTrie(trie_fact, (unsigned char*) "o") &&
    isInTrie(trie_fact, (unsigned char*) "orm") &&
    isInTrie(trie_fact, (unsigned char*) "orma") &&
    isInTrie(trie_fact, (unsigned char*) "tique") );

    
  return isInTrie(trie_fact, (unsigned char*) "e") &&
    isInTrie(trie_fact, (unsigned char*) "ue") &&
    isInTrie(trie_fact, (unsigned char*) "que") &&
    isInTrie(trie_fact, (unsigned char*) "formatique") &&
    isInTrie(trie_fact, (unsigned char*) "tique") &&
    isInTrie(trie_fact, (unsigned char*) "i") &&
    isInTrie(trie_fact, (unsigned char*) "in") &&
    isInTrie(trie_fact, (unsigned char*) "inf") &&
    isInTrie(trie_fact, (unsigned char*) "inform") &&
    isInTrie(trie_fact, (unsigned char*) "informatique") &&
    isInTrie(trie_fact, (unsigned char*) "o") &&
    isInTrie(trie_fact, (unsigned char*) "orm") &&
    isInTrie(trie_fact, (unsigned char*) "orma") &&
    isInTrie(trie_fact, (unsigned char*) "tique");
}