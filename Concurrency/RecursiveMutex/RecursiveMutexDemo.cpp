//
// Created by Bohan Gao on 9/8/20.
//

#include <thread>

#include "RecursiveMutexDemo.h"

unsigned int RecursiveMutexDemo::garlic_count;
unsigned int RecursiveMutexDemo::potato_count;

std::mutex RecursiveMutexDemo::lock_mutex;
std::recursive_mutex RecursiveMutexDemo::lock_recursive_mutex;

void RecursiveMutexDemo::testWithoutRecursiveMutex() {
    std::thread ashley(shop_mutex);
    std::thread thomas(shop_mutex);
    ashley.join();
    thomas.join();
    printf("We should buy %u garlics.\n", garlic_count);
    printf("We should buy %u potatoes.\n", potato_count);
}

void RecursiveMutexDemo::testWithRecursiveMutex() {
    std::thread ashley(shop_recursive_mutex);
    std::thread thomas(shop_recursive_mutex);
    ashley.join();
    thomas.join();
    printf("We should buy %u garlics.\n", garlic_count);
    printf("We should buy %u potatoes.\n", potato_count);
}

void RecursiveMutexDemo::shop_mutex() {
    for (int i = 0; i < 10000; i++) {
        inc_garlic_and_potato_mutex();
        inc_potato_mutex();
    }
}

void RecursiveMutexDemo::shop_recursive_mutex() {
    for (int i = 0; i < 10000; i++) {
        inc_garlic_and_potato_recursive_mutex();
        inc_potato_recursive_mutex();
    }
}

void RecursiveMutexDemo::inc_garlic_and_potato_mutex() {
    lock_mutex.lock();
    garlic_count++;
    //same thread tries to lock again,
    //stuck in it.
    inc_garlic_and_potato_mutex();
    lock_mutex.unlock();
}

void RecursiveMutexDemo::inc_potato_mutex() {
    //same thread tries to lock again, stuck here.
    lock_mutex.lock();
    potato_count++;
    lock_mutex.unlock();
}

void RecursiveMutexDemo::inc_garlic_and_potato_recursive_mutex() {
    lock_recursive_mutex.lock();
    garlic_count++;
    //recursive mutex can be locked multiple times by the same thread,
    //will not stuck in it.
    inc_potato_recursive_mutex();
    lock_recursive_mutex.unlock();
}

void RecursiveMutexDemo::inc_potato_recursive_mutex() {
    //recursive mutex can be locked multiple times by the same thread,
    //will not stuck here.
    lock_recursive_mutex.lock();
    potato_count++;
    lock_recursive_mutex.unlock();
}