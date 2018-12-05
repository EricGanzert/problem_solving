cmake_minimum_required(VERSION 2.8)
project(ch_12)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -O0")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES main.cpp
				 projectTests.cpp
				 digitalTime.cpp
				 digitalTime2.cpp
				 user.cpp
				 password.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
