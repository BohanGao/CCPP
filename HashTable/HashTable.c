//
// Created by Bohan Gao on 8/6/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "HashTable.h"

ValNode *CreateValNode(char *str) {
    ValNode *valNode = (ValNode *) malloc(sizeof(ValNode));
    valNode->val = str;
    valNode->next = NULL;
    return valNode;
}

void DestroyValNode(ValNode *valNode) {
    valNode->val = NULL;
    valNode->next = NULL;
    free(valNode);
    valNode = NULL;
}

void DestroyValNodes(ValNode *head) {
    while (head != NULL) {
        ValNode *next = head->next;
        DestroyValNode(head);
        head = next;
    }
}

EntryNode *CreateEntryNode(char *key, ValNode *valNode) {
    EntryNode *entryNode = (EntryNode *) malloc(sizeof(EntryNode));
    entryNode->next = NULL;
    entryNode->key = key;
    entryNode->val = valNode;
    return entryNode;
}

void DestroyEntryNode(EntryNode *entryNode) {
    entryNode->next = NULL;
    free(entryNode->key);
    entryNode->key = NULL;
    DestroyValNodes(entryNode->val);
    free(entryNode);
    entryNode = NULL;
}

void DestroyBucket(EntryNode *head) {
    while (head != NULL) {
        EntryNode *next = head->next;
        DestroyEntryNode(head);
        head = next;
    }
}

HashTable *CreateHashTable(int num_buckets, double load_factor) {
    HashTable *ht = (HashTable *) malloc(sizeof(HashTable));
    EntryNode *emptyNode = NULL;
    ht->buckets = malloc(sizeof(emptyNode) * num_buckets);
    int i;
    for (i = 0; i < num_buckets; i++) {
        ht->buckets[i] = NULL;
    }
    ht->num_buckets = num_buckets;
    ht->num_elements = 0;
    ht->load_factor = load_factor;
    return ht;
}

void DestroyHashTable(HashTable *ht) {
    int i;
    for (i = 0; i < ht->num_buckets; i++) {
        DestroyBucket(ht->buckets[i]);
    }
    free(ht->buckets);
    ht->buckets = NULL;
    ht->num_buckets = 0;
    ht->num_elements = 0;
    ht->load_factor = 0;
    free(ht);
}

int GetBucketIndex(char *key, int buckets) {
    size_t hash = 131;
    int len = strlen(key);
    int i;
    for (i = 0; i < len; i++) {
        hash = hash * i + key[i];
    }

    return hash % buckets;
}

void QuickSort(char *str, int start, int end) {
    if (start >= end) {
        return;
    }
    int mid = start + (end - start) / 2;
    char pivot = str[mid];
    int left = start;
    int right = end;
    while (left <= right) {
        while (left <= right && str[left] < pivot) {
            left++;
        }
        while (left <= right && pivot < str[right]) {
            right--;
        }
        if (left <= right) {
            char temp = str[left];
            str[left] = str[right];
            str[right] = temp;
            left++;
            right--;
        }
    }
    QuickSort(str, start, right);
    QuickSort(str, left, end);
}

char *GetSortedWord(char *str) {
    size_t len = strlen(str);
    char *sorted_str = NULL;
    char c;
    sorted_str = (char *) malloc(sizeof(c) * (len + 1));
    strncpy(sorted_str, str, (len + 1));
    sorted_str[len] = '\0';
    QuickSort(sorted_str, 0, len - 1);
    return sorted_str;
}

void Put(HashTable **ht, char *key, char *val) {
    if (ShouldIncreaseCapacity(*ht)) {
        *ht = Resize(*ht);
    }
    (*ht)->num_elements++;
    int len = strlen(key);
    char *copied_key = NULL;
    char c;
    copied_key = (char *) malloc(sizeof(c) * (len + 1));
    strncpy(copied_key, key, (len + 1));
    copied_key[len] = '\0';
    int index = GetBucketIndex(key, (*ht)->num_buckets);
    EntryNode *head = (*ht)->buckets[index];
    while (head != NULL) {
        if (strcmp(key, head->key) == 0) {
            ValNode *valNode = CreateValNode(val);
            valNode->next = head->val;
            head->val = valNode;
            free(copied_key);
            copied_key = NULL;
            return;
        }
        head = head->next;
    }
    ValNode *valNode = CreateValNode(val);
    EntryNode *entryNode = CreateEntryNode(copied_key, valNode);
    entryNode->next = (*ht)->buckets[index];
    (*ht)->buckets[index] = entryNode;
}

ValNode *Get(HashTable *ht, char *key) {
    int index = GetBucketIndex(key, ht->num_buckets);
    EntryNode *entryNode = ht->buckets[index];
    if (entryNode == NULL) {
        return NULL;
    }

    while (entryNode != NULL) {
        if (strcmp(entryNode->key, key) == 0) {
            return entryNode->val;
        }
        entryNode = entryNode->next;
    }

    return NULL;
}

int ShouldIncreaseCapacity(HashTable *ht) {
    double rate = ((double) ht->num_elements) / ht->num_buckets;
    if (rate >= ht->load_factor) {
        return 1;
    } else {
        return 0;
    }
}

HashTable *Resize(HashTable *ht) {
    HashTable *new_ht = CreateHashTable(ht->num_buckets * 2, ht->load_factor);

    int i;
    for (i = 0; i < ht->num_buckets; i++) {
        EntryNode *entryNode = ht->buckets[i];
        ht->buckets[i] = NULL;
        while (entryNode != NULL) {
            EntryNode *old_next_entry_node = entryNode->next;
            int new_bucket = GetBucketIndex(entryNode->key,
                                            new_ht->num_buckets);
            entryNode->next = new_ht->buckets[new_bucket];
            new_ht->buckets[new_bucket] = entryNode;

            entryNode = old_next_entry_node;
        }
    }
    new_ht->num_elements = ht->num_elements;

    DestroyHashTable(ht);

    return new_ht;
}

void PrintHashTable(HashTable *ht) {
    int i;
    for (i = 0; i < ht->num_buckets; i++) {
        EntryNode *entryNode = ht->buckets[i];
        while (entryNode != NULL) {
            printf("%s: ", entryNode->key);
            ValNode *valNode = entryNode->val;
            while (valNode != NULL) {
                printf("%s ", valNode->val);
                valNode = valNode->next;
            }
            printf("\n");
            entryNode = entryNode->next;
        }
    }
}
