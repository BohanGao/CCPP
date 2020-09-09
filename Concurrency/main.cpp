#include <iostream>

#include "ExecutionScheduling/ExecutionSchedulingDemo.h"
#include "ThreadLifeCycle/ThreadLifeCycleDemo.h"
#include "DetachedThread/DetachedThreadDemo.h"
#include "DataRace/DataRaceDemo.h"
#include "MutualExclusion/MutualExclusionDemo.h"
#include "AtomicObject/AtomicObjectDemo.h"
#include "RecursiveMutex/RecursiveMutexDemo.h"

int main() {
    //Execution_Scheduling_Demo::test();

    //ThreadLifeCycleDemo::test();

    //DetachedThreadDemo::testWithoutDetaching();
    //DetachedThreadDemo::testWithDetaching();

    //DataRaceDemo::test();

    //MutualExclusionDemo::test();

    //AtomicObjectDemo::test();

    RecursiveMutexDemo::testWithRecursiveMutex();

    return 0;
}
