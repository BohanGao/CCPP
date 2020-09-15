//
// Created by Bohan Gao on 9/14/20.
//

#ifndef CONCURRENCY_DIVIDEANDCONQUERDEMO_H
#define CONCURRENCY_DIVIDEANDCONQUERDEMO_H


class DivideAndConquerDemo {
public:
    static void test();

private:
    static unsigned long long getSum(int low, int high, int depth);
};


#endif //CONCURRENCY_DIVIDEANDCONQUERDEMO_H
