//
// Created by Bohan Gao on 8/6/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Words.h"
#include "TestUtils.h"

#define assert(EXPRESSION) (                            \
    (EXPRESSION) ?                                      \
    _assert_pass(#EXPRESSION, __FILE__, __LINE__) :     \
    _assert_fail(#EXPRESSION, __FILE__, __LINE__))

void _assert_fail(const char *expression,
                  const char *file,
                  int line) {
    fprintf(stderr,
            "\n**** Assertion '%s' FAILED, file '%s' line '%d' *******.\n",
            expression,
            file,
            line);
}

void _assert_pass(const char *expression,
                  const char *file,
                  int line) {
    fprintf(stdout,
            "Assertion '%s' passed, file '%s' line '%d'.\n",
            expression,
            file,
            line);
}

void StartTest(const char *test) {
    static int count = 1;
    printf("Test #%d: %s\n\n", count++, test);
}

void EndTest() {
    printf("\n--------------------------------\n\n");
}

void TestCreateValNode() {
    StartTest("CreateValNode");

    char *str = "test";
    ValNode *valNode = CreateValNode(str);
    assert(strcmp(valNode->val, "test") == 0);
    assert(valNode->next == NULL);
    DestroyValNode(valNode);

    EndTest();
}

void TestCreateEntryNode() {
    StartTest("CreateEntryNode");

    char *val_str = "test";
    char *key_str = NULL;
    key_str = GetSortedWord(val_str);
    ValNode *valNode = CreateValNode(val_str);
    EntryNode *entryNode = NULL;
    entryNode = CreateEntryNode(key_str, valNode);
    assert(strcmp(entryNode->key, key_str) == 0);
    assert(strcmp(entryNode->val->val, val_str) == 0);
    assert(entryNode->next == NULL);
    DestroyEntryNode(entryNode);

    EndTest();
}

void TestCreateHashTable() {
    StartTest("CreateHashTable");

    HashTable *hashTable = CreateHashTable(INITIAL_NUM_BUCKETS,
                                           DEFAULT_LOAD_FACTOR);
    assert(hashTable->num_elements == 0);
    assert(hashTable->num_buckets == 16);
    int i;
    for (i = 0; i < 16; i++) {
        assert(hashTable->buckets[i] == NULL);
    }

    DestroyHashTable(hashTable);

    EndTest();
}

void TestGetBucketIndex() {
    StartTest("GetBucketIndex");

    unsigned int index = GetBucketIndex("test", 32);
    assert(index == 3);

    EndTest();
}

void TestGetSortedWord() {
    StartTest("GetSortedWord");

    char *sorted = GetSortedWord("test");
    assert(strcmp(sorted, "estt") == 0);
    free(sorted);
    sorted = NULL;

    EndTest();
}

void TestPut() {
    StartTest("Put");

    HashTable *hashTable = CreateHashTable(INITIAL_NUM_BUCKETS,
                                           DEFAULT_LOAD_FACTOR);

    char *str1 = "dcba";
    char *sorted_str1 = GetSortedWord(str1);
    Put(&hashTable, sorted_str1, str1);
    free(sorted_str1);
    sorted_str1 = NULL;

    char *str2 = "edcb";
    char *sorted_str2 = GetSortedWord(str2);
    Put(&hashTable, sorted_str2, str2);
    free(sorted_str2);
    sorted_str2 = NULL;

    char *str3 = "fedc";
    char *sorted_str3 = GetSortedWord(str3);
    Put(&hashTable, sorted_str3, str3);
    free(sorted_str3);
    sorted_str3 = NULL;

    char *str4 = "gfed";
    char *sorted_str4 = GetSortedWord(str4);
    Put(&hashTable, sorted_str4, str4);
    free(sorted_str4);
    sorted_str4 = NULL;

    assert(hashTable->num_elements == 4);

    DestroyHashTable(hashTable);

    EndTest();
}

void TestGet() {
    StartTest("Get");

    HashTable *hashTable = CreateHashTable(INITIAL_NUM_BUCKETS,
                                           DEFAULT_LOAD_FACTOR);

    char *str1 = "dcba";
    char *sorted_str1 = GetSortedWord(str1);
    Put(&hashTable, sorted_str1, str1);
    free(sorted_str1);
    sorted_str1 = NULL;

    char *str2 = "abcd";
    char *sorted_str2 = GetSortedWord(str2);
    Put(&hashTable, sorted_str2, str2);
    free(sorted_str2);
    sorted_str2 = NULL;

    ValNode *valNode = Get(hashTable, "abcd");

    assert(strcmp(valNode->val, "abcd") == 0);
    assert(strcmp(valNode->next->val, "dcba") == 0);
    assert(valNode->next->next == NULL);

    DestroyHashTable(hashTable);

    EndTest();
}

void TestResize() {
    StartTest("Resize");

    HashTable *hashTable = CreateHashTable(4,
                                           DEFAULT_LOAD_FACTOR);

    char *str1 = "dcba";
    char *sorted_str1 = GetSortedWord(str1);
    Put(&hashTable, sorted_str1, str1);
    free(sorted_str1);
    sorted_str1 = NULL;

    char *str2 = "edcb";
    char *sorted_str2 = GetSortedWord(str2);
    Put(&hashTable, sorted_str2, str2);
    free(sorted_str2);
    sorted_str2 = NULL;

    char *str3 = "fedc";
    char *sorted_str3 = GetSortedWord(str3);
    Put(&hashTable, sorted_str3, str3);
    free(sorted_str3);
    sorted_str3 = NULL;

    assert(ShouldIncreaseCapacity(hashTable) == 1);

    hashTable = Resize(hashTable);

    assert(hashTable->num_buckets == 8);
    assert(hashTable->num_elements == 3);

    DestroyHashTable(hashTable);

    EndTest();
}

void TestGetWords() {
    StartTest("GetWords");

    HashTable *hashTable = CreateHashTable(INITIAL_NUM_BUCKETS,
                                           DEFAULT_LOAD_FACTOR);
    char **words = GetWords("words.txt", 432334);

    int i;
    for (i = 0; i < 432334; i++) {
        char *key = GetSortedWord(words[i]);
        Put(&hashTable, key, words[i]);
        free(key);
        key = NULL;
    }

    assert(hashTable->num_elements == 432334);
    assert(hashTable->num_buckets == 1048576);

    DestroyHashTable(hashTable);
    DestroyWords(words, 432334);

    EndTest();
}

int main() {
    TestCreateValNode();
    TestCreateEntryNode();
    TestCreateHashTable();
    TestGetBucketIndex();
    TestGetSortedWord();
    TestPut();
    TestGet();
    TestResize();
    TestGetWords();

    return EXIT_SUCCESS;
}
