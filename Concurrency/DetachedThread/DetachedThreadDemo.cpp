//
// Created by Bohan Gao on 9/8/20.
//

#include <thread>
#include <chrono>

#include "DetachedThreadDemo.h"

void DetachedThreadDemo::testWithoutDetaching() {
    std::thread ashley(clean_kitchen);

    for (int i = 0; i < 3; i++) {
        printf("Thomas is cooking...\n");
        std::this_thread::sleep_for(std::chrono::milliseconds(600));
    }

    printf("Thomas is done!\n");

    ashley.join();
    //ashley will never be able to join,
    //join means main thread would wait here until ashley finishes,
    //however, ashley will never finish.
    //Main thread would keep waiting then without proceeding to the next line.

    printf("Both Ashley and Thomas done!\n");
}

void DetachedThreadDemo::testWithDetaching() {
    std::thread ashley(clean_kitchen);
    ashley.detach();
    //detaching the ashley thread from the current main thread,
    //allows it to run independently in the background as a daemon thread,
    //hence ashley thread will not prevent main thread form terminating.

    for (int i = 0; i < 3; i++) {
        printf("Thomas is cooking...\n");
        std::this_thread::sleep_for(std::chrono::milliseconds(600));
    }

    printf("Thomas is done!\n");

    //ashley.join();
    //ashley thread is detached from the main thread, becomes non-joinable
}

void DetachedThreadDemo::clean_kitchen() {
    while (true) {//infinite loop, indicating ashley will never finish
        printf("Ashley is cleaning the kitchen.\n");
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}