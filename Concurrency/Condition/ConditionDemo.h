//
// Created by Bohan Gao on 9/10/20.
//

#ifndef CONCURRENCY_CONDITIONDEMO_H
#define CONCURRENCY_CONDITIONDEMO_H

#include <mutex>
#include <condition_variable>

class ConditionDemo {
public:
    static void testWithoutCondition();

    static void testWithSignalOne();

    static void testWithSignalMultiple();

    static void testWithBroadcast();

private:
    static void eatWithoutCondition(int id);

    static void eatWithSignalOne(int id);

    static void eatWithSignalMultiple(int id);

    static void eatWithBroadcast(int id);

    static int servings;

    static std::mutex pot_lid;

    static std::condition_variable food_taken;

};

//wait
//1. Automatically release lock on the mutex
//2. Go to sleep and enter waiting queue
//3. Reacquire lock when woken up

//signal
//1. Wake up one thread from condition variable queue
//2. Also called notify or wake

//broadcast
//1. Wake up all threads from condition variable queue
//2. Also called notify all or wake all

//If multiple threads is waiting for a condition var, and signal is called, the program might stuck depending in the condition of the while loop,
//if the signal is not sent to the thread who's scheduled to execute next.
//broadcast should be used instead.
//in the example where 5 eater take turn from id0 to id4 taking the food. since notify_one randomly picks one waitng thread,
//if thread 3 is waken up whereas it is not its turn yet, it will wait again to unlock the lock,
//only this time, all other threads are also waiting, making the program stuck.

//example - Shared Queue or Buffer
//1. Thread first acquire the mutex to make sure only one thread is able to modify the queue at a time
//2. If the thread is adding item to queue, and queue is full, it will then wait for Condition variable BufferNotFull
//3. If the thread is removing item from queue, and queue is empty, it will then wait for Condition variable BufferNotEmpty
//When wait is called, mutex is released automatically, and this thread would go to sleep.
//After the Condition variable is signaled to it, it will wake up and reacquire the mutex .

#endif //CONCURRENCY_CONDITIONDEMO_H
