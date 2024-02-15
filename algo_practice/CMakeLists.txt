cmake_minimum_required(VERSION 3.15)

project(run)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wfatal-errors")

include_directories()

file(GLOB SRC_FILES ./linear_search.cpp)

set(OBJ_NAME run)

add_executable(${OBJ_NAME} ${SRC_FILES})

target_link_libraries(${OBJ_NAME})