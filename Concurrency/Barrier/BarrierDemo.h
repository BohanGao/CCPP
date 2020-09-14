//
// Created by Bohan Gao on 9/13/20.
//

#ifndef CONCURRENCY_BARRIERDEMO_H
#define CONCURRENCY_BARRIERDEMO_H

#include <mutex>
#include <boost/thread/thread.hpp>
#include <boost/thread/barrier.hpp>

class BarrierDemo {
public:
    static void test();

private:
    static void cpu_work(int units);

    static void dubble();

    static void increase();

    static int count;
    static std::mutex calculator;
    static boost::barrier stop;
    //Barrier prevents a group of threads from proceeding
    //until enough threads have reached the barrier.
};


#endif //CONCURRENCY_BARRIERDEMO_H
