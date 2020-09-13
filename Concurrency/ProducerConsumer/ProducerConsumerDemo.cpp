//
// Created by Bohan Gao on 9/12/20.
//

#include <thread>
#include <array>

#include "ProducerConsumerDemo.h"

FoodServingLine ProducerConsumerDemo::foodServingLine = FoodServingLine();

void ProducerConsumerDemo::test() {
    std::thread producer(produce);
    std::array<std::thread, 100> consumers;
    for(int i=0;i<100;i++){
        consumers[i] = std::thread(consume);
    }
    producer.join();
    for(int i=0;i<100;i++){
        consumers[i].join();
    }
}

void ProducerConsumerDemo::produce() {
    for (int i = 0; i < 1000000; i++) {
        foodServingLine.serve_food(1);
    }
    foodServingLine.serve_food(-1);
    printf("Producer is done serving food.\n");
}

void ProducerConsumerDemo::consume() {
    int food_consumed = 0;
    while (true) {
        int bowl = foodServingLine.consume_food();
        if (bowl == -1) {
            printf("Consumer ate %d bowls of food.\n", food_consumed);
            foodServingLine.serve_food(-1);
            return;
        } else {
            food_consumed += bowl;
        }
    }
}
