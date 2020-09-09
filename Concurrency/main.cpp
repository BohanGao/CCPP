#include <iostream>

#include "ExecutionScheduling/ExecutionSchedulingDemo.h"
#include "ThreadLifeCycle/ThreadLifeCycleDemo.h"
#include "DetachedThread/DetachedThreadDemo.h"
#include "DataRace/DataRaceDemo.h"
#include "MutualExclusion/MutualExclusionDemo.h"

int main() {
    //Execution_Scheduling_Demo::test();

    //ThreadLifeCycleDemo::test();

    //DetachedThreadDemo::testWithoutDetaching();
    //DetachedThreadDemo::testWithDetaching();

    //DataRaceDemo::test();

    MutualExclusionDemo::test();

    return 0;
}
