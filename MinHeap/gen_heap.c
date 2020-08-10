#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "gen_heap.h"

HeapGen *CreateHeapGen(void **data, int num_elems, int (*compare)(void *, void *)) {
    HeapGen *heap = (HeapGen *) malloc(sizeof(HeapGen));
    heap->compare = compare;
    int i;
    for (i = 0; i < num_elems; i++) {
        InsertGen(heap, data[i]);
    }
    return heap;
}

void InsertGen(HeapGen *heap, void *new_data_val) {
    heap->num_elems++;
    heap->data[heap->num_elems - 1] = new_data_val;
    BubbleUpGen(heap, heap->num_elems - 1);
}

void *ExtractMinGen(HeapGen *heap) {
    if (heap->num_elems == 0) {
        printf("Should not call ExtractMinGen against empty heap.");
        DestroyHeapGen(heap);
        exit(1);
    }
    void *result = heap->data[0];
    if (heap->num_elems == 1) {
        heap->data[0] = NULL;
        heap->num_elems--;
    } else {
        heap->data[0] = heap->data[heap->num_elems - 1];
        heap->data[heap->num_elems - 1] = NULL;
        heap->num_elems--;
        BubbleDownGen(heap, 0);
    }

    return result;
}

void *DeleteGen(HeapGen *heap, int position) {
    if (position <= 0 || position > heap->num_elems) {
        printf("Could not delete heap element positioned at %d, "
               "which is out of bound of heap data array (1-%d).",
               position, heap->num_elems);
        DestroyHeapGen(heap);
        exit(1);
    }

    int index = position - 1;
    void *result = heap->data[index];
    heap->data[index] = heap->data[heap->num_elems - 1];
    heap->data[heap->num_elems - 1] = NULL;
    heap->num_elems--;
    BubbleDownGen(heap, index);
    return result;
}

void BubbleUpGen(HeapGen *heap, int p) {
    int parentIndex = ParentIndexGen(p);
    if (parentIndex == -1) {
        return;
    }
    if (heap->compare(heap->data[p], heap->data[parentIndex]) >= 0) {
        return;
    }
    SwapGen(heap, p, parentIndex);
    BubbleUpGen(heap, parentIndex);
}

void BubbleDownGen(HeapGen *heap, int p) {
    int leftChildIndex = LeftChildIndexGen(p);
    if (leftChildIndex >= heap->num_elems) {
        return;
    }
    int rightChildIndex = RightChildIndexGen(p);
    if (rightChildIndex >= heap->num_elems) { // only has left child
        if (heap->compare(heap->data[leftChildIndex], heap->data[p]) < 0) {
            SwapGen(heap, p, leftChildIndex);
        }
    } else { // has both left and right child
        int minChildIndex = heap->compare(heap->data[leftChildIndex],
                                          heap->data[rightChildIndex]) <= 0
                            ? leftChildIndex
                            : rightChildIndex;
        if (heap->compare(heap->data[minChildIndex], heap->data[p]) < 0) {
            SwapGen(heap, p, minChildIndex);
            BubbleDownGen(heap, minChildIndex);
        }
    }
}

void SwapGen(HeapGen *heap, int first_index, int second_index) {
    void *temp = heap->data[first_index];
    heap->data[first_index] = heap->data[second_index];
    heap->data[second_index] = temp;
}

void DestroyHeapGen(HeapGen *heap) {
    int i;
    for (i = 0; i < heap->num_elems; i++) {
        heap->data[i] = NULL;
    }
    heap->num_elems = 0;
    heap->compare = NULL;
    free(heap);
    heap = NULL;
}

int ParentIndexGen(int child_index) {
    if (child_index == 0)
        return (-1);
    else
        return ((int) (child_index - 1) / 2);
}

int LeftChildIndexGen(int parent_index) {
    return (2 * parent_index) + 1;
}

int RightChildIndexGen(int parent_index) {
    return (2 * parent_index) + 2;
}
