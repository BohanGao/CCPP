//
// Created by Bohan Gao on 9/8/20.
//

#ifndef CONCURRENCY_DATARACEDEMO_H
#define CONCURRENCY_DATARACEDEMO_H


class DataRaceDemo {
public:
    static void test();

private:
    static void inc();

    static unsigned int garlic_count;
};


#endif //CONCURRENCY_DATARACEDEMO_H
