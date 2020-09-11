//
// Created by Bohan Gao on 9/10/20.
//

#ifndef CONCURRENCY_LIVELOCKDEMO_H
#define CONCURRENCY_LIVELOCKDEMO_H

#include <mutex>

class LiveLockDemo {
public:
    static void testWithYeild();

    static void testWithoutYeild();

private:
    static void eatWithYield(std::mutex & first_chopstick, std::mutex & second_chopstick);

    static void eatWithoutYield(std::mutex & first_chopstick, std::mutex & second_chopstick);

    static int sushi_count;
};


#endif //CONCURRENCY_LIVELOCKDEMO_H
