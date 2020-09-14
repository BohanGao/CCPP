cmake_minimum_required(VERSION 3.17)
project(Concurrency)

set(CMAKE_CXX_STANDARD 17)

find_package (Boost REQUIRED COMPONENTS thread system)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(Concurrency main.cpp ExecutionScheduling/ExecutionSchedulingDemo.cpp ExecutionScheduling/ExecutionSchedulingDemo.h ThreadLifeCycle/ThreadLifeCycleDemo.cpp ThreadLifeCycle/ThreadLifeCycleDemo.h DetachedThread/DetachedThreadDemo.cpp DetachedThread/DetachedThreadDemo.h DataRace/DataRaceDemo.cpp DataRace/DataRaceDemo.h MutualExclusion/MutualExclusionDemo.cpp MutualExclusion/MutualExclusionDemo.h AtomicObject/AtomicObjectDemo.cpp AtomicObject/AtomicObjectDemo.h RecursiveMutex/RecursiveMutexDemo.cpp RecursiveMutex/RecursiveMutexDemo.h TryLock/TryLockDemo.cpp TryLock/TryLockDemo.h SharedMutex/SharedMutexDemo.cpp SharedMutex/SharedMutexDemo.h DeadLock/DeadLockDemo.cpp DeadLock/DeadLockDemo.h AbandonedLock/AbandondedLockDemo.cpp AbandonedLock/AbandondedLockDemo.h Starvation/StarvationDemo.cpp Starvation/StarvationDemo.h LiveLock/LiveLockDemo.cpp LiveLock/LiveLockDemo.h Condition/ConditionDemo.cpp Condition/ConditionDemo.h ProducerConsumer/ProducerConsumerDemo.cpp ProducerConsumer/ProducerConsumerDemo.h ProducerConsumer/FoodServingLine.cpp ProducerConsumer/FoodServingLine.h Semaphore/SemaphoreDemo.cpp Semaphore/SemaphoreDemo.h Semaphore/Semaphore.cpp Semaphore/Semaphore.h RaceCondition/RaceConditionDemo.cpp RaceCondition/RaceConditionDemo.h Barrier/BarrierDemo.cpp Barrier/BarrierDemo.h)

target_link_libraries(
        ${PROJECT_NAME}
        Boost::thread
        Boost::system
)