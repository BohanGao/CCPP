//
// Created by Bohan Gao on 9/7/20.
//

#ifndef CONCURRENCY_EXECUTIONSCHEDULINGDEMO_H
#define CONCURRENCY_EXECUTIONSCHEDULINGDEMO_H

class Execution_Scheduling_Demo {
public:
    static void test();

private:
    static void vegetable_chopper(const char *name);

    static bool chopping;
};

#endif //CONCURRENCY_EXECUTIONSCHEDULINGDEMO_H
