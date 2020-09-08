//
// Created by Bohan Gao on 9/7/20.
//

#ifndef CONCURRENCY_EXECUTION_SCHEDULING_DEMO_H
#define CONCURRENCY_EXECUTION_SCHEDULING_DEMO_H

class Execution_Scheduling_Demo{
public:
    static void vegetable_chopper(const char *name);

    static int test();

private:
    static bool chopping;
};
#endif //CONCURRENCY_EXECUTION_SCHEDULING_DEMO_H
