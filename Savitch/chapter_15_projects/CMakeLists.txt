cmake_minimum_required(VERSION 2.8)
project(ch_15)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall -O0")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES main.cpp
				 projectTests.cpp
				 employee.cpp
				 hourlyEmployee.cpp
				 salariedEmployee.cpp
				 partFilledArray.cpp
				 partFilledArrayWMax.cpp
				 sale.cpp
				 discountSale.cpp
				 administrator.cpp
				 temporaryEmployee.cpp
				 permanentEmployee.cpp
				 doctor.cpp
				 person.cpp
				 vehicle.cpp
				 truck.cpp
				 car.cpp
				 sportsCar.cpp
				 patient.cpp
				 billing.cpp
				 figure.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
