//
// Created by Bohan Gao on 9/12/20.
//

#include "FoodServingLine.h"

void FoodServingLine::serve_food(int i) {
    std::unique_lock<std::mutex> ladle_lock(ladle);
    food_queue.push(i);
    ladle_lock.unlock();
    food_served.notify_one();
}

int FoodServingLine::consume_food() {
    std::unique_lock<std::mutex> ladle_lock(ladle);
    while(food_queue.empty()){
        food_served.wait(ladle_lock);
    }
    int food = food_queue.front();
    food_queue.pop();
    ladle_lock.unlock();
    return food;
}
