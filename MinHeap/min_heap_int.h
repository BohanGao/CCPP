#define PQ_SIZE 64

#ifndef MIN_HEAP_INT_H
#define MIN_HEAP_INT_H

typedef struct {
    int data[PQ_SIZE];
    int num_elems;
} HeapInt;

HeapInt *
CreateHeapInt(int *data, int num_elems);

void InsertInt(HeapInt *heap, int new_data_val);

int ExtractMinInt(HeapInt *heap);

int DeleteInt(HeapInt *heap, int position);

void BubbleUpInt(HeapInt *heap, int p);

void BubbleDownInt(HeapInt *heap, int p);

void SwapInt(HeapInt *heap, int first_index, int second_index);

void DestroyHeapInt(HeapInt *heap);

int ParentIndexInt(int child_index);

int LeftChildIndexInt(int parent_index);

int RightChildIndexInt(int parent_index);

int CompareIntVal(int first, int second);

#endif //MIN_HEAP_INT_H
