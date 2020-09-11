//
// Created by Bohan Gao on 9/10/20.
//

#include <thread>
#include <array>

#include "ConditionDemo.h"

int ConditionDemo::servings = 10;
std::mutex ConditionDemo::pot_lid;
std::condition_variable ConditionDemo::food_taken;

void ConditionDemo::testWithoutCondition() {
    std::array<std::thread, 2> eaters;
    for(int i=0;i<2;i++){
        eaters[i] = std::thread(eatWithoutCondition, i);
    }
    for(auto & eater : eaters){
        eater.join();
    }
}

void ConditionDemo::testWithSignalOne() {
    std::array<std::thread, 2> eaters;
    for(int i=0;i<2;i++){
        eaters[i] = std::thread(eatWithSignalOne, i);
    }
    for(auto & eater : eaters){
        eater.join();
    }
}

void ConditionDemo::testWithSignalMultiple() {
    //might stuck with multiple threads waiting,
    //and the one which got waken up is not the one scheduled to execute next in condition var queue;
    std::array<std::thread, 5> eaters;
    for(int i=0;i<5;i++){
        eaters[i] = std::thread(eatWithSignalMultiple, i);
    }
    for(auto & eater : eaters){
        eater.join();
    }
}

void ConditionDemo::testWithBroadcast() {
    std::array<std::thread, 5> eaters;
    for(int i=0;i<5;i++){
        eaters[i] = std::thread(eatWithBroadcast, i);
    }
    for(auto & eater : eaters){
        eater.join();
    }
}

void ConditionDemo::eatWithoutCondition(int id) {
    int put_lid_back = 0;
    while (servings > 0) {
        std::unique_lock<std::mutex> lid_lock(pot_lid);
        if (id == servings % 2 && servings > 0) {
            servings--;
        } else {
            put_lid_back++;
        }
    }
    printf("Person %d put lid back %d times.\n", id, put_lid_back);
}

void ConditionDemo::eatWithSignalOne(int id) {
    int put_lid_back = 0;
    while (servings > 0) {
        std::unique_lock<std::mutex> lid_lock(pot_lid);//get lock
        while (id != servings % 2 && servings > 0) {//condition not met
            put_lid_back++;
            food_taken.wait(lid_lock);//wait for condition var being signaled
        }//use while as the pattern for wait. If is not enough, as sometimes condition var might have spurious wake up.
        if(servings>0){
            servings--;
            lid_lock.unlock();
            food_taken.notify_one();
        }
    }
    printf("Person %d put lid back %d times.\n", id, put_lid_back);
}

void ConditionDemo::eatWithSignalMultiple(int id) {
    int put_lid_back = 0;
    while (servings > 0) {
        std::unique_lock<std::mutex> lid_lock(pot_lid);//get lock
        while (id != servings % 5 && servings > 0) {//condition not met
            put_lid_back++;
            food_taken.wait(lid_lock);//wait for condition var being signaled
        }//use while as the pattern for wait. If is not enough, as sometimes condition var might have spurious wake up.
        if(servings>0){
            servings--;
            lid_lock.unlock();
            food_taken.notify_one();
        }
    }
    printf("Person %d put lid back %d times.\n", id, put_lid_back);
}

void ConditionDemo::eatWithBroadcast(int id) {
    int put_lid_back = 0;
    while (servings > 0) {
        std::unique_lock<std::mutex> lid_lock(pot_lid);//get lock
        while (id != servings % 5 && servings > 0) {//condition not met
            put_lid_back++;
            food_taken.wait(lid_lock);//wait for condition var being signaled
        }//use while as the pattern for wait. If is not enough, as sometimes condition var might have spurious wake up.
        if(servings>0){
            servings--;
            lid_lock.unlock();
            food_taken.notify_all();
        }
    }
    printf("Person %d put lid back %d times.\n", id, put_lid_back);
}
