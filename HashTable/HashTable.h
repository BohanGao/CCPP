//
// Created by Bohan Gao on 8/6/20.
//

#ifndef HASHTABLE_H
#define HASHTABLE_H

typedef struct ValNode {
    char *val;
    struct ValNode *next;
} ValNode;

typedef struct EntryNode {
    char *key;
    ValNode *val;
    struct EntryNode *next;
} EntryNode;

typedef struct {
    EntryNode **buckets;
    int num_elements;
    int num_buckets;
    double load_factor;
} HashTable;

ValNode *CreateValNode(char *str);

void DestroyValNode(ValNode *word);

void DestroyValNodes(ValNode *head);

EntryNode *CreateEntryNode(char *key, ValNode *words);

void DestroyEntryNode(EntryNode *node);

void DestroyBucket(EntryNode *head);

HashTable *CreateHashTable(int num_buckets, double load_factor);

void DestroyHashTable(HashTable *ht);

int GetBucketIndex(char *key, int buckets);

void QuickSort(char *str, int start, int end);

char *GetSortedWord(char *str);

void Put(HashTable **ht, char *key, char *val);

ValNode *Get(HashTable *ht, char *key);

int ShouldIncreaseCapacity(HashTable *ht);

HashTable *Resize(HashTable *ht);

void PrintHashTable(HashTable *ht);

#endif  // HASHTABLE_H
