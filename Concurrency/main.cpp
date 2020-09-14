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
#include "DeadLock/DeadLockDemo.h"
#include "AbandonedLock/AbandondedLockDemo.h"
#include "Starvation/StarvationDemo.h"
#include "LiveLock/LiveLockDemo.h"
#include "Condition/ConditionDemo.h"
#include "ProducerConsumer/ProducerConsumerDemo.h"
#include "Semaphore/SemaphoreDemo.h"

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
    //SharedMutexDemo::testWithSharedMutex();

    //DeadLockDemo::testDeadLock();
    //DeadLockDemo::testWithPriority();
    //DeadLockDemo::testWithScopeLock();

    //AbandondedLockDemo::testAbandonedLock();
    //AbandondedLockDemo::testScopedLock();

    //StarvationDemo::test();

    //LiveLockDemo::testWithoutYeild();
    //LiveLockDemo::testWithYeild();

    //ConditionDemo::testWithoutCondition();
    //ConditionDemo::testWithSignalOne();
    //ConditionDemo::testWithSignalMultiple();
    //ConditionDemo::testWithBroadcast();

    //ProducerConsumerDemo::test();

    SemaphoreDemo::test();

    return 0;
}
