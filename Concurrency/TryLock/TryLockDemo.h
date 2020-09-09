//
// Created by Bohan Gao on 9/8/20.
//

#ifndef CONCURRENCY_TRYLOCKDEMO_H
#define CONCURRENCY_TRYLOCKDEMO_H

#include <mutex>

class TryLockDemo {
public:
    static void testWithTryLock();

    static void testWithoutTryLock();

private:
    static void searchAndUpdateWithTryLock(const char * name);

    static void searchAndUpdateWithoutTryLock(const char * name);

    static unsigned int items_on_list;
    static std::mutex lock_mutex;
};


#endif //CONCURRENCY_TRYLOCKDEMO_H
