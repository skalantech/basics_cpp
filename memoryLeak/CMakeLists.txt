cmake_minimum_required(VERSION 3.15)

project(memoryLeak)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wfatal-errors")

file(GLOB SRC_FILES ./*.cpp)

set(OBJ_NAME memoryLeak)

add_executable(${OBJ_NAME} ${SRC_FILES})

target_link_libraries(${OBJ_NAME})