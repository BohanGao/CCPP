//
// Created by Bohan Gao on 9/12/20.
//

#ifndef CONCURRENCY_FOODSERVINGLINE_H
#define CONCURRENCY_FOODSERVINGLINE_H

#include <mutex>
#include <condition_variable>
#include <queue>

class FoodServingLine {
public:
    void serve_food(int i);

    int consume_food();

private:
    std::mutex ladle;
    std::condition_variable food_served;
    std::queue<int> food_queue;
};


#endif //CONCURRENCY_FOODSERVINGLINE_H
