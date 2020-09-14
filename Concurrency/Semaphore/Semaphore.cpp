//
// Created by Bohan Gao on 9/13/20.
//

#include "Semaphore.h"

void Semaphore::acquire(){
    std::unique_lock<std::mutex> lock(mutex);
    while(count==0){
        unblocked.wait(lock);
    }
    count--;
}

void Semaphore::release() {
    std::unique_lock<std::mutex> lock(mutex);
    count++;
    lock.unlock();
    unblocked.notify_one();
}
