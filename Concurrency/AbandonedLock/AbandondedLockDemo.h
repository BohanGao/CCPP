//
// Created by Bohan Gao on 9/9/20.
//

#ifndef CONCURRENCY_ABANDONDEDLOCKDEMO_H
#define CONCURRENCY_ABANDONDEDLOCKDEMO_H

#include <mutex>

class AbandondedLockDemo {
public:
    static void testAbandonedLock();

    static void testScopedLock();

private:
    static void eatWithoutScopedLock(std::mutex & chopsticks);

    static void eatWithScopedLock(std::mutex & chopsticks);

    static int sushi_count;
};


#endif //CONCURRENCY_ABANDONDEDLOCKDEMO_H
