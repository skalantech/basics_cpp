cmake_minimum_required(VERSION 3.14)
project(g_benchmark)
enable_testing()

include(FetchContent)

## Project-wide setup
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

# Externally provided libraries
FetchContent_Declare(googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.13.0)

FetchContent_Declare(googlebenchmark
        GIT_REPOSITORY https://github.com/google/benchmark.git
        GIT_TAG main) # need master for benchmark::benchmark

FetchContent_MakeAvailable(
        googletest
        googlebenchmark)

add_executable(g_benchmark my_bench1.cxx)
target_link_libraries(g_benchmark benchmark::benchmark)

#cmake -DCMAKE_BUILD_TYPE=Release ..\
#cmake --build . --config Release