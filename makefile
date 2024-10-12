CC = gcc
CFLAGS = -Wall -g -std=c99

# Fichiers objets communs
COMMON_OBJ = main.o trie_test.o

# Cible par défaut
all: matrice hachage

# Compilation avec matrice de transitions
matrice: CFLAGS += -DMATRICE
matrice: $(COMMON_OBJ) trie_matrice.o
	$(CC) $(CFLAGS) $(COMMON_OBJ) trie_matrice.o -o trie_matrice

# Compilation avec table de hachage
hachage: CFLAGS += -DHACHAGE
hachage: $(COMMON_OBJ) trie_hachage.o table_hashage.o
	$(CC) $(CFLAGS) $(COMMON_OBJ) trie_hachage.o table_hashage.o -o trie_hachage


# Fichiers objets spécifiques à chaque version
trie_matrice.o: trie.c trie.h
	$(CC) $(CFLAGS) -c trie.c -o trie_matrice.o

trie_hachage.o: trie.c trie.h
	$(CC) $(CFLAGS) -c trie.c -o trie_hachage.o

table_hashage.o: table_hashage.c table_hashage.h
	$(CC) $(CFLAGS) -c table_hashage.c -o table_hashage.o

# Compilation des fichiers communs
main.o: main.c trie.h trie_test.h
	$(CC) $(CFLAGS) -c main.c -o main.o

trie_test.o: trie_test.c trie_test.h trie.h
	$(CC) $(CFLAGS) -c trie_test.c -o trie_test.o

# Nettoyage des fichiers objets et exécutables
clean:
	rm -f *.o trie_matrice trie_hachage

# Archiver les fichiers pour soumission
tar: clean
	tar -zcf "TP1" main.c trie.c trie.h makefile trie_test.c trie_test.h \
	         "colors.h" "macro.h" "matrice.h" "hachage.h" "hachage.c"
