cmake_minimum_required(VERSION 2.8)
project(ch_13)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall -O0")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES main.cpp
				 projectTests.cpp
				 list.cpp
				 node.cpp
				 stack.cpp
				 queue.cpp
				 polynomial.cpp
				 suitor.cpp
				 computerLab.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
