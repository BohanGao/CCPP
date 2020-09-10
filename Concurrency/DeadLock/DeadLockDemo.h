//
// Created by Bohan Gao on 9/9/20.
//

#ifndef CONCURRENCY_DEADLOCKDEMO_H
#define CONCURRENCY_DEADLOCKDEMO_H

#include <mutex>

class DeadLockDemo {
public:
    static void testDeadLock();

    static void testWithPriority();

    static void testWithScopeLock();

private:
    static void eat(std::mutex & first_chopstick, std::mutex & second_chopstick);

    static void eatWithScopeLock(std::mutex & first_chopstick, std::mutex & second_chopstick);

    static int sushi_count;
};


#endif //CONCURRENCY_DEADLOCKDEMO_H
