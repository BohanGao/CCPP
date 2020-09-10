//
// Created by Bohan Gao on 9/8/20.
//

#ifndef CONCURRENCY_SHAREDMUTEXDEMO_H
#define CONCURRENCY_SHAREDMUTEXDEMO_H

#include <string>
#include <mutex>
#include <shared_mutex>

class SharedMutexDemo {
public:
    static void testWithSharedMutex();

    static void testWithoutSharedMutex();

private:
    static void readCalendarWithSharedMutex(const int id);

    static void readCalendarWithoutSharedMutex(const int id);

    static void writeCalendarWithSharedMutex(const int id);

    static void writeCalendarWithoutSharedMutex(const int id);

    static std::string weekdays[];

    static int today;

    static std::mutex lock_mutex;

    static std::shared_mutex lock_shared_mutex;//example would be read-write lock
};


#endif //CONCURRENCY_SHAREDMUTEXDEMO_H
