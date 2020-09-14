//
// Created by Bohan Gao on 9/13/20.
//

#ifndef CONCURRENCY_SEMAPHORE_H
#define CONCURRENCY_SEMAPHORE_H

#include <mutex>
#include <condition_variable>

class Semaphore {
public:
    Semaphore(unsigned int init_count){
        count = init_count;
    }

    void acquire();

    void release();

private:
    unsigned int count;
    std::mutex mutex;
    std::condition_variable unblocked;
};


#endif //CONCURRENCY_SEMAPHORE_H
