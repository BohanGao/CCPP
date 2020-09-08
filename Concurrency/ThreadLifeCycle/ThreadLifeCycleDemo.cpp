//
// Created by Bohan Gao on 9/8/20.
//

#include <thread>
#include <chrono>

#include "ThreadLifeCycleDemo.h"

void ThreadLifeCycleDemo::test() {
    printf("Thomas requests Ashley's help.\n");

    std::thread ashley(cut_sausage);

    printf("Ashely thread is joinable? %s\n",
           ashley.joinable() ? "true" : "false");

    printf("Thomas continues cooking soup.\n");

    std::this_thread::sleep_for(std::chrono::seconds(1));

    //std::thread::joinable() function checks if the calling thread is alive
    printf("Ashely thread is joinable? %s\n",
           ashley.joinable() ? "true" : "false");

    printf("Thomas patiently waits for Ashley to finish and join...\n");

    ashley.join();
    //The main thread will sleep until the ashley finish.
    //If remove ashley.join(), the main thread may finish and return before ashley thread,
    //and will cause the program crash.
    //At the end of main function, destructors of ashley is invoked,
    //and the destructor of std::thread will check if this thread is joinable.
    //If the thread is not detached and still active, it is joinable.
    //If the thread is joinable, the destructor will invoke std::terminate(),
    //cause the program crashes.

    printf("Ashely thread is joinable? %s\n",
           ashley.joinable() ? "true" : "false");

    printf("Thomas and Ashley are both done.\n");
}

void ThreadLifeCycleDemo::cut_sausage() {
    printf("Ashley started and waiting for sausage to thaw...\n");

    std::this_thread::sleep_for(std::chrono::seconds(3));

    printf("Ashley is done cutting sausage.\n");
}
