cmake_minimum_required(VERSION 3.17)
project(HashTable C)

set(CMAKE_C_STANDARD 99)

#add_executable(HashTable Main.c HashTable.c HashTable.h Words.c Words.h TestUtils.c TestUtils.h)
add_executable(HashTableTest Test.c HashTable.c HashTable.h Words.c Words.h TestUtils.c TestUtils.h)