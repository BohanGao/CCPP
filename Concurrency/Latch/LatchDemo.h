//
// Created by Bohan Gao on 9/13/20.
//

#ifndef CONCURRENCY_LATCHDEMO_H
#define CONCURRENCY_LATCHDEMO_H

#include <mutex>
#include <boost/thread/latch.hpp>

class LatchDemo {
public:
    static void test();

private:
    static void cpu_work(int units);

    static void dubble();

    static void increase();

    static int count;
    static std::mutex calculator;
    static boost::latch latch;
};

//Barrier releases when certain number of threads are waiting.
//Latch releases when count_down function gets called enough times so that count value reduces to zero.
//Latch's wait function will wait for 0 to proceed, count_down function will decrease the count by 1.
//After count_down is called, the calling thread will still proceed (count_down!=wait).

//One way that latches are commonly used is with an initial count value of one to serve as a simple gate.
//Any number of threads can wait at the gate until another controlling thread executes the count_down function just once,
//which releases the waiting threads to continue on.
//
//Initializing the count to some other value N can be used to make one thread wait
//until N other threads have completed some action and calling the count_down function,
//or for some action to be completed N times, perhaps by a single thread with a loop.

#endif //CONCURRENCY_LATCHDEMO_H
