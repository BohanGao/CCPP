//
// Created by Bohan Gao on 9/8/20.
//

#ifndef CONCURRENCY_RECURSIVEMUTEXDEMO_H
#define CONCURRENCY_RECURSIVEMUTEXDEMO_H

#include <mutex>

class RecursiveMutexDemo {
public:
    static void testWithoutRecursiveMutex();

    static void testWithRecursiveMutex();

private:
    static void shop_mutex();

    static void shop_recursive_mutex();

    static void inc_garlic_and_potato_mutex();

    static void inc_potato_mutex();

    static void inc_garlic_and_potato_recursive_mutex();

    static void inc_potato_recursive_mutex();

    static unsigned int garlic_count;
    static unsigned int potato_count;

    static std::mutex lock_mutex;
    //mutex cannot be locked again after the same thread locked it the first time.

    static std::recursive_mutex lock_recursive_mutex;
    //also known as reentrant lock,
    //allows same thread to lock it for multiple times.
    //note the lock also needs to be unlocked the same times.
};


#endif //CONCURRENCY_RECURSIVEMUTEXDEMO_H
