//
// Created by Bohan Gao on 9/8/20.
//

#include <thread>
#include <chrono>
#include <array>

#include "SharedMutexDemo.h"

std::string SharedMutexDemo::weekdays[7] = {"Sunday", "Monday", "Tuesday",
                                            "Wednesday", "Thursday", "Friday",
                                            "Saturday"};
int SharedMutexDemo::today = 0;
std::mutex SharedMutexDemo::lock_mutex;
std::shared_mutex SharedMutexDemo::lock_shared_mutex;

void SharedMutexDemo::testWithSharedMutex() {
    std::array<std::thread, 10> readers;
    for(int i=0;i<readers.size();i++){
        readers[i] = std::thread(readCalendarWithSharedMutex, i);
    }
    std::array<std::thread, 2> writers;
    for(int i=0;i<2;i++){
        writers[i] = std::thread(writeCalendarWithSharedMutex, i);
    }
    for(int i=0;i<readers.size();i++){
        readers[i].join();
    }
    for(int i=0;i<2;i++){
        writers[i].join();
    }
}

void SharedMutexDemo::testWithoutSharedMutex() {
    std::array<std::thread, 10> readers;
    for(int i=0;i<readers.size();i++){
        readers[i] = std::thread(readCalendarWithoutSharedMutex, i);
    }
    std::array<std::thread, 2> writers;
    for(int i=0;i<2;i++){
        writers[i] = std::thread(writeCalendarWithoutSharedMutex, i);
    }
    for(int i=0;i<readers.size();i++){
        readers[i].join();
    }
    for(int i=0;i<2;i++){
        writers[i].join();
    }
}

void SharedMutexDemo::readCalendarWithSharedMutex(const int id) {
    for (int i = 0; i < 7; i++) {
        lock_shared_mutex.lock_shared();//read lock can be shared
        printf("Reader-%d sees today is %s.\n", id, weekdays[i].c_str());
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        lock_shared_mutex.unlock_shared();
    }
}

void SharedMutexDemo::readCalendarWithoutSharedMutex(const int id) {
    for (int i = 0; i < 7; i++) {
        lock_mutex.lock();
        printf("Reader-%d sees today is %s.\n", id, weekdays[i].c_str());
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        lock_mutex.unlock();
    }
}

void SharedMutexDemo::writeCalendarWithSharedMutex(const int id) {
    for (int i = 0; i < 7; i++) {
        lock_shared_mutex.lock();//write lock should be mutual exclusive
        today = (today + 1) % 7;
        printf("Writer-%d updates today to %s.\n", id, weekdays[i].c_str());
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        lock_shared_mutex.unlock();
    }
}

void SharedMutexDemo::writeCalendarWithoutSharedMutex(const int id) {
    for (int i = 0; i < 7; i++) {
        lock_mutex.lock();
        today = (today + 1) % 7;
        printf("Writer-%d updates today to %s.\n", id, weekdays[i].c_str());
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        lock_mutex.unlock();
    }
}
