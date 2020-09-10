#include <iostream>

#include "ExecutionScheduling/ExecutionSchedulingDemo.h"
#include "ThreadLifeCycle/ThreadLifeCycleDemo.h"
#include "DetachedThread/DetachedThreadDemo.h"
#include "DataRace/DataRaceDemo.h"
#include "MutualExclusion/MutualExclusionDemo.h"
#include "AtomicObject/AtomicObjectDemo.h"
#include "RecursiveMutex/RecursiveMutexDemo.h"
#include "TryLock/TryLockDemo.h"
#include "SharedMutex/SharedMutexDemo.h"

int main() {
    //Execution_Scheduling_Demo::test();

    //ThreadLifeCycleDemo::test();

    //DetachedThreadDemo::testWithoutDetaching();
    //DetachedThreadDemo::testWithDetaching();

    //DataRaceDemo::test();

    //MutualExclusionDemo::test();

    //AtomicObjectDemo::test();

    //RecursiveMutexDemo::testWithRecursiveMutex();

    //TryLockDemo::testWithoutTryLock();
    //TryLockDemo::testWithTryLock();

    //SharedMutexDemo::testWithoutSharedMutex();
    SharedMutexDemo::testWithSharedMutex();

    return 0;
}
