#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "int_heapsort.h"
#include "gen_heapsort.h"
#include "int_helpers.h"
#include "score.h"

void PrintIntArray(int *data, int num_elems) {
    int i = 0;
    printf("[");
    for (i = 0; i < num_elems; i++) {
        printf("%d ", data[i]);
    }
    printf("]\n");
}

void PrintArray(void **data, int num_elems, void (*Print)(void *)) {
    int i = 0;
    printf("[");
    for (i = 0; i < num_elems; i++) {
        Print(data[i]);
    }
    printf("]\n");
}

void DoIntHeapsortUsingHeapInt(int num_elems) {
    int *integers = (int *) malloc(sizeof(int) * num_elems);

    int i;
    for (i = 0; i < num_elems; i++) {
        integers[i] = rand() % 50;
    }

    PrintIntArray(integers, num_elems);
    HeapSortInt(integers, num_elems);
    PrintIntArray(integers, num_elems);

    free(integers);
}

void DoIntHeapsortUsingHeapGen(int num_elems) {
    // malloc an array to store random ints
    int *integers = (int *) malloc(sizeof(int) * num_elems);

    // Put random numbers in that array
    int i;
    for (i = 0; i < num_elems; i++) {
        integers[i] = rand() % 50;
    }

    // Create an array of pointers to those ints
    void **vals = malloc(sizeof(void *) * num_elems);
    for (i = 0; i < num_elems; i++) {
        vals[i] = &integers[i];
    }

    PrintArray((void **) vals, num_elems, PrintInt);
    HeapSortGen((void **) vals, num_elems, &CompareInt);
    PrintArray((void **) vals, num_elems, PrintInt);

    free(vals);
    free(integers);
}

void DoScoreHeapsortUsingHeapGen(int num_elems) {
    void **scores = CreateArray("names.txt", num_elems, &CreateScoreFromName);
    PrintArray(scores, num_elems, &PrintScore);
    HeapSortGen(scores, num_elems, &CompareScore);
    PrintArray(scores, num_elems, &PrintScore);
    DestroyArray(scores, num_elems, &DestroyScoreWrapper);
}

int main() {
    // Set up some stuff
    int num_elems = 16;
    time_t t;
    srand(42);//(unsigned) time(&t));

//    DoIntHeapsortUsingHeapInt(num_elems);
//
//    printf("\n\n\n\n");
//
//    DoIntHeapsortUsingHeapGen(num_elems);
//
//    printf("\n\n\n\n");

    DoScoreHeapsortUsingHeapGen(num_elems);
}
