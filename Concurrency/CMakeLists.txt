cmake_minimum_required(VERSION 3.17)
project(Concurrency)

set(CMAKE_CXX_STANDARD 14)

add_executable(Concurrency main.cpp ExecutionScheduling/execution_scheduling_demo.cpp ExecutionScheduling/execution_scheduling_demo.h)