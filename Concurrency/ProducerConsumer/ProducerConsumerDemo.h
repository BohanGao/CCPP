//
// Created by Bohan Gao on 9/12/20.
//

#ifndef CONCURRENCY_PRODUCERCONSUMERDEMO_H
#define CONCURRENCY_PRODUCERCONSUMERDEMO_H

#include "FoodServingLine.h"

class ProducerConsumerDemo {
public:
    static void test();

private:
    static void produce();

    static void consume();

    static FoodServingLine foodServingLine;
};


#endif //CONCURRENCY_PRODUCERCONSUMERDEMO_H
