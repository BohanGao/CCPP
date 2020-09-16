//
// Created by Bohan Gao on 9/15/20.
//

#include <thread>
#include <cmath>

#include "MatrixMultipleDemo.h"

void MatrixMultipleDemo::test() {
    const int NUM_EVAL_RUNS = 3;
    const int NUM_ROWS_A = 10;
    const int NUM_COLS_A = 10;
    const int NUM_ROWS_B = NUM_COLS_A;
    const int NUM_COLS_B = 10;

    long **A = (long **) malloc(NUM_ROWS_A * sizeof(long));
    long **B = (long **) malloc(NUM_ROWS_B * sizeof(long));
    for (int i = 0; i < NUM_ROWS_A; i++) {
        A[i] = (long *) malloc(NUM_COLS_A * sizeof(long));
        B[i] = (long *) malloc(NUM_COLS_B * sizeof(long));
        for (int j = 0; j < NUM_COLS_A; j++) {
            A[i][j] = rand() % 100 + 1;
            B[i][j] = rand() % 100 + 1;
        }
    }

    printf("Matrix A is:\n");
    for(int i=0;i<NUM_ROWS_A;i++){
        for(int j=0;j<NUM_COLS_B;j++){
            printf("%d ",A[i][j]);
        }
        printf(" \n");
    }
    printf("Matrix B is:\n");
    for(int i=0;i<NUM_ROWS_A;i++){
        for(int j=0;j<NUM_COLS_B;j++){
            printf("%d ",B[i][j]);
        }
        printf(" \n");
    }

    long **C = (long **) malloc(NUM_ROWS_A * sizeof(long));
    for (int i = 0; i < NUM_ROWS_A; i++) {
        C[i] = (long *) malloc(NUM_COLS_B * sizeof(long));
    }

    parallelMatrixMultiply(A, NUM_ROWS_A, NUM_COLS_A,
                           B, NUM_ROWS_B, NUM_COLS_B,
                           C);

    printf("Matrix C is:\n");
    for(int i=0;i<NUM_ROWS_A;i++){
        for(int j=0;j<NUM_COLS_B;j++){
            printf("%d ",C[i][j]);
        }
        printf(" \n");
    }

    delete A;
    A = NULL;
    delete B;
    B = NULL;
    delete C;
    C = NULL;
}

void MatrixMultipleDemo::parallelMatrixMultiply(long **A,
                                                int num_rows_a,
                                                int num_cols_a,
                                                long **B,
                                                int num_rows_b,
                                                int num_cols_b,
                                                long **C) {
    int num_workers = std::thread::hardware_concurrency();
    int chunk_size = ceil((float) num_rows_a / num_workers);

    std::thread workers[num_workers];
    for (int i = 0; i < num_workers; i++) {
        int start_row_c = std::min(i * chunk_size, num_rows_a);
        int end_row_c = std::min((i + 1) * chunk_size, num_rows_a);
        workers[i] = std::thread(calculate, A, num_rows_a, num_cols_a,
                                 B, num_rows_b, num_cols_b,
                                 C, start_row_c, end_row_c);
    }
    for (int i = 0; i < num_workers; i++) {
        workers[i].join();
    }
}

void MatrixMultipleDemo::calculate(long **A, int num_rows_a, int num_cols_a,
                                   long **B, int num_rows_b, int num_cols_b,
                                   long **C, int start_rows_c, int end_rows_c) {
    for (int i = start_rows_c; i < end_rows_c; i++) {
        for (int j = 0; j < num_cols_b; j++) {
            C[i][j] = 0;
            for (int k = 0; k < num_cols_a; k++) {
                C[i][j] += A[i][k] + B[k][j];
            }
        }
    }
}
