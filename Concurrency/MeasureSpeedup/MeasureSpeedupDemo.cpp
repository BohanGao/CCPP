//
// Created by Bohan Gao on 9/15/20.
//

#include <future>

#include "MeasureSpeedupDemo.h"

void MeasureSpeedupDemo::test() {
    const int NUM_EVAL_RUNS = 10;
    const int SUM_VALUE = 1000000000;

    printf("Evaluating Sequential Implementation...\n"); // warm up run
    std::chrono::duration<double> sequential_time(0);
    auto sequential_result = sequentialSum(0, SUM_VALUE);
    for (int i = 0; i < NUM_EVAL_RUNS; i++) {
        auto start_time = std::chrono::high_resolution_clock::now();
        sequentialSum(0, SUM_VALUE);
        sequential_time +=
                std::chrono::high_resolution_clock::now() - start_time;
    }
    sequential_time /= NUM_EVAL_RUNS;

    printf("Evaluating Parallel Implementation...\n");
    std::chrono::duration<double> parallel_time(0);
    auto parallel_result = parallelSum(0, SUM_VALUE, 3); // warm up run
    for (int i = 0; i < NUM_EVAL_RUNS; i++) {
        auto start_time = std::chrono::high_resolution_clock::now();
        parallelSum(0, SUM_VALUE, 3);
        parallel_time += std::chrono::high_resolution_clock::now() - start_time;
    }
    parallel_time /= NUM_EVAL_RUNS;

    if (sequential_result != parallel_result) {
        printf("ERROR: Result mismatch!\n Sequential Result = %lld\n Parallel Result = %lld\n",
               sequential_result, parallel_result);
    }
    printf("Average Sequential Time: %.1f ms\n",
           sequential_time.count() * 1000);
    printf("Average Parallel Time: %.1f ms\n", parallel_time.count() * 1000);
    printf("Speedup: %2f\n", sequential_time / parallel_time);
    printf("Efficiency %.2f%%\n", 100 * (sequential_time / parallel_time) /
                                  std::thread::hardware_concurrency());
}

unsigned long long
MeasureSpeedupDemo::sequentialSum(unsigned int low, unsigned int high) {
    unsigned long long sum = 0;
    for (auto i = low; i <= high; i++) {
        sum += i;
    }
    return sum;
}

unsigned long long
MeasureSpeedupDemo::parallelSum(unsigned int low, unsigned long high,
                                int depth) {
    if (depth > 3) {
        unsigned long long sum = 0;
        for (auto i = low; i <= high; i++) {
            sum += i;
        }
        return sum;
    } else {
        auto mid = (low + high) / 2;
        auto left_sum = std::async(std::launch::async, parallelSum, low, mid,
                                   depth + 1);
        auto right_sum = parallelSum(mid + 1, high, depth + 1);
        return left_sum.get() + right_sum;
    }
}
