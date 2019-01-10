cmake_minimum_required(VERSION 2.8)
project(ch_18)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wno-psabi -g -Wall -O0")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES main.cpp
				 projectTests.cpp
				 bookDatabase.cpp
				 permutations.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
