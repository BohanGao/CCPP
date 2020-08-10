#define PQ_SIZE 64

#ifndef GEN_HEAP_H
#define GEN_HEAP_H

typedef struct {
    void *data[PQ_SIZE];
    int num_elems;

    int (*compare)(void *, void *);
} HeapGen;

HeapGen *CreateHeapGen(void **data, int num_elems, int (*compare)(void *, void *));

void InsertGen(HeapGen *heap, void *new_data_val);

void *ExtractMinGen(HeapGen *heap);

void *DeleteGen(HeapGen *heap, int position);

void BubbleUpGen(HeapGen *heap, int p);

void BubbleDownGen(HeapGen *heap, int p);

void SwapGen(HeapGen *heap, int first_index, int second_index);

void DestroyHeapGen(HeapGen *heap);

int ParentIndexGen(int child_index);

int LeftChildIndexGen(int parent_index);

int RightChildIndexGen(int parent_index);

#endif //GEN_HEAP_H