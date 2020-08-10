#include "gen_heapsort.h"
#include "gen_heap.h"

void HeapSortGen(void** data, int num_elems, int (*Compare)(void*, void*)) {
    HeapGen * heap = CreateHeapGen(data, num_elems, Compare);
    int i;
    for(i=0;i<num_elems;i++){
        data[i] = ExtractMinGen(heap);
    }
    DestroyHeapGen(heap);
}
