//
// Created by Bohan Gao on 9/15/20.
//

#ifndef CONCURRENCY_MERGESORTDEMO_H
#define CONCURRENCY_MERGESORTDEMO_H


class MergeSortDemo {
public:
    static void test();

private:
    static void parallelMergeSort(int * array, unsigned int left, unsigned int right, unsigned int depth);

    static void sequentialMergeSort(int * array, unsigned int left, unsigned int right);

    static void merge(int * array, unsigned int left, unsigned int mid, unsigned int right);
};


#endif //CONCURRENCY_MERGESORTDEMO_H
