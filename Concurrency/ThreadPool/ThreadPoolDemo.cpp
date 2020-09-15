//
// Created by Bohan Gao on 9/13/20.
//

#include <boost/asio.hpp>

#include "ThreadPoolDemo.h"

void ThreadPoolDemo::test() {
    boost::asio::thread_pool pool(4);
    for (int i = 0; i < 100; i++) {
        boost::asio::post(pool, [i]() { chopVegetable(i); });
    }
    pool.join();
}

void ThreadPoolDemo::chopVegetable(int vegetable_id) {
    printf("Thread %d chopped vegetable %d.\n",
           std::this_thread::get_id(),
           vegetable_id);
}
