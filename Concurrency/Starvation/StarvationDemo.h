//
// Created by Bohan Gao on 9/10/20.
//

#ifndef CONCURRENCY_STARVATIONDEMO_H
#define CONCURRENCY_STARVATIONDEMO_H

#include <mutex>

class StarvationDemo {//thread is perputually denied the resoursed it needs.
public:
    static void test();

private:
    static void eatWithScopedLock(std::mutex & chopsticks);

    static int sushi_count;
};


#endif //CONCURRENCY_STARVATIONDEMO_H
