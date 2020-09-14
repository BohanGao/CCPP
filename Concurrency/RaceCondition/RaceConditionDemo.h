//
// Created by Bohan Gao on 9/13/20.
//

#ifndef CONCURRENCY_RACECONDITIONDEMO_H
#define CONCURRENCY_RACECONDITIONDEMO_H

#include <mutex>

class RaceConditionDemo {
public:
    static void test();

private:
    static void cpu_work(int units);

    static void dubble();

    static void increase();

    static int count;
    static std::mutex calculator;
};


#endif //CONCURRENCY_RACECONDITIONDEMO_H
