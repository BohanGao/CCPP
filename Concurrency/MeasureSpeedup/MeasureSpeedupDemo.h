//
// Created by Bohan Gao on 9/15/20.
//

#ifndef CONCURRENCY_MEASURESPEEDUPDEMO_H
#define CONCURRENCY_MEASURESPEEDUPDEMO_H


class MeasureSpeedupDemo {
public:
    static void test();

private:
    static unsigned long long sequentialSum(unsigned int low, unsigned int high);

    static unsigned long long parallelSum(unsigned int low, unsigned long high, int depth);
};


#endif //CONCURRENCY_MEASURESPEEDUPDEMO_H
