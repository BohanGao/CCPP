//
// Created by Bohan Gao on 7/31/20.
//

#include "min_heap_int.h"

#include "int_heapsort.h"

void HeapSortInt(int *data, int num_elems) {
    HeapInt *heap = CreateHeapInt(data, num_elems);
    int i;
    for (i = 0; i < num_elems; i++) {
        data[i] = ExtractMinInt(heap);
    }
    DestroyHeapInt(heap);
}
