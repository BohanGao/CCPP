//
// Created by Bohan Gao on 8/6/20.
//
#include <stdio.h>
#include <stdlib.h>
#include "TestUtils.h"

void PrintAllAnagramGroups(char **words, int num_words) {
    HashTable *hashTable = CreateHashTable(INITIAL_NUM_BUCKETS,
                                           DEFAULT_LOAD_FACTOR);

    int i;
    for (i = 0; i < num_words; i++) {
        char *key = GetSortedWord(words[i]);
        Put(&hashTable, key, words[i]);
        free(key);
        key = NULL;
    }
    PrintHashTable(hashTable);

    DestroyHashTable(hashTable);
}

void PrintAllWords(char **words, int num_words) {
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
}
