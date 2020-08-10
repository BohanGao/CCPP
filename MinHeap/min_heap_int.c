#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "min_heap_int.h"

HeapInt *CreateHeapInt(int *data, int num_elems) {
    HeapInt *heap = (HeapInt *) malloc(sizeof(HeapInt));
    int i;
    for (i = 0; i < num_elems; i++) {
        InsertInt(heap, data[i]);
    }
    heap->num_elems = num_elems;

    return heap;
}

void InsertInt(HeapInt *heap, int new_data_val) {
    heap->num_elems++;
    heap->data[heap->num_elems - 1] = new_data_val;
    BubbleUpInt(heap, heap->num_elems - 1);
}

int ExtractMinInt(HeapInt *heap) {
    if (heap->num_elems == 0) {
        printf("Should not call ExtractMinInt against empty heap.");
        DestroyHeapInt(heap);
        exit(1);
    }
    int result = heap->data[0];
    if (heap->num_elems == 1) {
        heap->data[0] = 0;
        heap->num_elems--;
    } else {
        heap->data[0] = heap->data[heap->num_elems - 1];
        heap->data[heap->num_elems - 1] = 0;
        heap->num_elems--;
        BubbleDownInt(heap, 0);
    }

    return result;
}

int DeleteInt(HeapInt *heap, int position) {
    if (position <= 0 || position > heap->num_elems) {
        printf("Could not delete heap element positioned at %d, "
               "which is out of bound of heap data array (1-%d).",
               position, heap->num_elems);
        DestroyHeapInt(heap);
        exit(1);
    }

    int index = position - 1;
    int result = heap->data[index];
    heap->data[index] = heap->data[heap->num_elems - 1];
    heap->data[heap->num_elems - 1] = 0;
    heap->num_elems--;
    BubbleDownInt(heap, index);
    return result;
}

void BubbleUpInt(HeapInt *heap, int p) {
    int parentIndex = ParentIndexInt(p);
    if (parentIndex == -1) {
        return;
    }
    if (CompareIntVal(heap->data[p], heap->data[parentIndex]) >= 0) {
        return;
    }
    SwapInt(heap, p, parentIndex);
    BubbleUpInt(heap, parentIndex);
}

void BubbleDownInt(HeapInt *heap, int p) {
    int leftChildIndex = LeftChildIndexInt(p);
    if (leftChildIndex >= heap->num_elems) {
        return;
    }
    int rightChildIndex = RightChildIndexInt(p);
    if (rightChildIndex >= heap->num_elems) { // only has left child
        if (CompareIntVal(heap->data[leftChildIndex], heap->data[p]) < 0) {
            SwapInt(heap, p, leftChildIndex);
        }
    } else { // has both left and right child
        int minChildIndex = CompareIntVal(heap->data[leftChildIndex],
                                          heap->data[rightChildIndex]) <= 0
                            ? leftChildIndex
                            : rightChildIndex;
        if (CompareIntVal(heap->data[minChildIndex], heap->data[p]) < 0) {
            SwapInt(heap, p, minChildIndex);
            BubbleDownInt(heap, minChildIndex);
        }
    }
}

void SwapInt(HeapInt *heap, int first_index, int second_index) {
    int temp = heap->data[first_index];
    heap->data[first_index] = heap->data[second_index];
    heap->data[second_index] = temp;
}

void DestroyHeapInt(HeapInt *heap) {
    heap->num_elems = 0;
    free(heap);
    heap = NULL;
}

int ParentIndexInt(int child_index) {
    if (child_index == 0)
        return (-1);
    else
        return ((int) (child_index - 1) / 2);
}

int LeftChildIndexInt(int parent_index) {
    return (2 * parent_index) + 1;
}

int RightChildIndexInt(int parent_index) {
    return (2 * parent_index) + 2;
}

int CompareIntVal(int first, int second) {
    return first - second;
}
