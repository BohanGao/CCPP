cmake_minimum_required(VERSION 3.17)
project(MinHeap C)

set(CMAKE_C_STANDARD 99)

add_executable(MinHeap run_gen_heapsort.c int_helpers.c int_helpers.h gen_heapsort.c gen_heapsort.h gen_heap.c gen_heap.h score.c score.h min_heap_int.c min_heap_int.h int_heapsort.c int_heapsort.h)