//
// Created by Bohan Gao on 9/15/20.
//

#ifndef CONCURRENCY_MATRIXMULTIPLEDEMO_H
#define CONCURRENCY_MATRIXMULTIPLEDEMO_H


class MatrixMultipleDemo {
public:
    static void test();

private:
    static void parallelMatrixMultiply(long ** A, int num_rows_a, int num_cols_a,
                                       long ** B, int num_rows_b, int num_cols_b,
                                       long ** C);

    static void calculate(long ** A, int num_rows_a, int num_cols_a,
                          long ** B, int num_rows_b, int num_cols_b,
                          long ** C, int start_rows_c, int end_rows_c);
};


#endif //CONCURRENCY_MATRIXMULTIPLEDEMO_H
