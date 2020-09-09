//
// Created by Bohan Gao on 9/8/20.
//

#ifndef CONCURRENCY_ATOMICOBJECTDEMO_H
#define CONCURRENCY_ATOMICOBJECTDEMO_H

#include <atomic>

class AtomicObjectDemo {
public:
    static void test();

private:
    static void inc();

    static std::atomic<unsigned int> garlic_count;
};


#endif //CONCURRENCY_ATOMICOBJECTDEMO_H
