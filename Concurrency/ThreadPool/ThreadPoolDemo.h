//
// Created by Bohan Gao on 9/13/20.
//

#ifndef CONCURRENCY_THREADPOOLDEMO_H
#define CONCURRENCY_THREADPOOLDEMO_H


class ThreadPoolDemo {
public:
    static void test();

private:
    static void chopVegetable(int vegetable_id);
};
//Spawning new thread has overhead.
//ThreadPool creates and maintains a collection of worker threads,
//and reuses existing thread to execute tasks.

#endif //CONCURRENCY_THREADPOOLDEMO_H
