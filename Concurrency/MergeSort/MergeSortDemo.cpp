//
// Created by Bohan Gao on 9/15/20.
//

#include <thread>
#include <cmath>

#include "MergeSortDemo.h"

void MergeSortDemo::test() {
    const int N = 100; // number of elements to sort

    int arr[N];
    printf("original array:\n");
    for (int i=0; i<N; i++) {
        arr[i] = rand();
        printf("%d ", arr[i]);
    }
    printf("\n");

    parallelMergeSort(arr, 0, N-1, 0);

    printf("sorted array:\n");
    for(int i=0;i<N;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void MergeSortDemo::parallelMergeSort(int * array, unsigned int left, unsigned int right, unsigned int depth) {
    if (depth >= std::log(std::thread::hardware_concurrency())) {
        sequentialMergeSort(array, left, right);
    }
    else {
        unsigned int mid = (left + right) / 2;
        std::thread left_thread = std::thread(parallelMergeSort, array, left, mid, depth+1);
        parallelMergeSort(array, mid+1, right, depth+1);
        left_thread.join();
        merge(array, left, mid, right);
    }
}

void MergeSortDemo::sequentialMergeSort(int *array, unsigned int left, unsigned int right) {
    if (left < right) {
        unsigned int mid = (left + right) / 2; // find the middle point
        sequentialMergeSort(array, left, mid); // sort the left half
        sequentialMergeSort(array, mid+1, right); // sort the right half
        merge(array, left, mid, right); // merge the two sorted halves
    }
}

void MergeSortDemo::merge(int *array, unsigned int left, unsigned int mid, unsigned int right) {
    unsigned int num_left = mid - left + 1; // number of elements in left subarray
    unsigned int num_right = right - mid; // number of elements in right subarray

    // copy data into temporary left and right subarrays to be merged
    int array_left[num_left], array_right[num_right];
    std::copy(&array[left], &array[mid + 1], array_left);
    std::copy(&array[mid + 1], &array[right + 1], array_right);

    // initialize indices for array_left, array_right, and input subarrays
    unsigned int index_left = 0;    // index to get elements from array_left
    unsigned int index_right = 0;    // index to get elements from array_right
    unsigned int index_insert = left; // index to insert elements into input array

    // merge temporary subarrays into original input array
    while ((index_left < num_left) || (index_right < num_right)) {
        if ((index_left < num_left) && (index_right < num_right)) {
            if (array_left[index_left] <= array_right[index_right]) {
                array[index_insert] = array_left[index_left];
                index_left++;
            }
            else {
                array[index_insert] = array_right[index_right];
                index_right++;
            }
        }
            // copy any remain elements of array_left into array
        else if (index_left < num_left){
            array[index_insert] = array_left[index_left];
            index_left += 1;
        }
            // copy any remain elements of array_right into array
        else if (index_right < num_right) {
            array[index_insert] = array_right[index_right];
            index_right += 1;
        }
        index_insert++;
    }
}
