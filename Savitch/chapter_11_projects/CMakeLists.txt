
cmake_minimum_required(VERSION 2.8)
project(ch_11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wno-psabi -g -O0")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES main.cpp 
				 money.cpp
				 pairs.cpp
				 projectTests.cpp
				 vectorDouble.cpp
				 percent.cpp
				 rational.cpp
				 complexNumbers.cpp
				 stringVar.cpp
				 text.cpp
				 polynomial.cpp
				 checkbook.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
