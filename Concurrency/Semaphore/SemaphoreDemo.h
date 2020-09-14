//
// Created by Bohan Gao on 9/13/20.
//

#ifndef CONCURRENCY_SEMAPHOREDEMO_H
#define CONCURRENCY_SEMAPHOREDEMO_H

#include "Semaphore.h"

class SemaphoreDemo {
public:
    static void test();

private:
    static void chargePhone(int phoneId);

    static Semaphore charger;
};


#endif //CONCURRENCY_SEMAPHOREDEMO_H
