//
// Created by Bohan Gao on 9/8/20.
//

#ifndef CONCURRENCY_MUTUALEXCLUSIONDEMO_H
#define CONCURRENCY_MUTUALEXCLUSIONDEMO_H

#include <mutex>

class MutualExclusionDemo {
public:
    static void test();

private:
    static void inc();

    static unsigned int garlic_count;
    static std::mutex lock_mutex;
};


#endif //CONCURRENCY_MUTUALEXCLUSIONDEMO_H
