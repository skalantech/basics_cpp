#*****
#Root
#*****

# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.15)

# Project name
project(PileProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add the source directory
add_subdirectory(source)

# Add the usage directory
add_subdirectory(utilisation)

#mkdir build
#cd build
#cmake .. "MinGW Makefiles"
#cmake -DENABLE_TESTING=ON .. "MinGW Makefiles" # not needed if enable_testing()
#cmake --build .
#./usage/MyExecutable
#./source/Testeur.cpp

#********
#Library
#********

# Add the library target
add_library(PileStaticLibrary #SHARED #if dynamy library
    Pile.cpp
    ContratException.cpp
)

# Include directories
target_include_directories(PileStaticLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# If you want to link against GTest for testing (gtest must be in the project)
#add_subdirectory(googletest)
#include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

enable_testing()

# Add the test executable
add_executable(PileTesteur PileTesteur.cpp)
target_link_libraries(PileTesteur PileStaticLibrary gtest gtest_main pthread)

# If you want to run the tests automatically after build
include(GoogleTest)
gtest_discover_tests(PileTesteur)

#************
#Utilisation
#************

# Add the executable target
add_executable(MyExecutable utilisationPrincipalPile.cpp)

# Link against the library
target_link_libraries(MyExecutable PileStaticLibrary)

##########################################################
##########################################################

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)

# Externally provided libraries
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(hello_test  hello_test.cxx)

target_link_libraries(hello_test GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(hello_test)

############################################################
############################################################

# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.15)

# Project name
project(tests)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)

# Compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wfatal-errors")

# Include directories
set(GTEST_INCLUDE_PATH "D:/googletest/googletest/include/")
include_directories(${GTEST_INCLUDE_PATH})

# Source files
file(GLOB SRC_FILES 
    ./*.cpp    
)

# Executable name
set(OBJ_NAME tests)

# Add the executable target
add_executable(${OBJ_NAME} ${SRC_FILES})

# Link against GTEST library
set(GTEST_LIBRARY_PATH "D:/googletest/build/lib/libgtest.a")
set(GTEST_MAIN_LIBRARY_PATH "D:/googletest/build/lib/libgtest_main.a")
target_link_libraries(${OBJ_NAME} ${GTEST_LIBRARY_PATH} ${GTEST_MAIN_LIBRARY_PATH} pthread)

# Custom target for running the executable
add_custom_target(run
    COMMAND ${OBJ_NAME}
    DEPENDS ${OBJ_NAME}
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)

# Custom target for cleaning
add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_SOURCE_DIR}/libs/CMakeFiles
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/CMakeCache.txt
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/Makefile
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/cmake_install.cmake
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/install_manifest.txt
    COMMAND ${CMAKE_COMMAND} -E remove ${OBJ_NAME}
)

###########################################################
###########################################################

cmake_minimum_required(VERSION 3.15)

project(pile)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wfatal-errors")

include_directories()

file(GLOB SRC_FILES ./source/*.cpp ./utilisation/*.cpp)

set(OBJ_NAME pile)

enable_testing()

add_executable(${OBJ_NAME} ${SRC_FILES})

target_link_libraries(${OBJ_NAME} gtest_main gtest pthread)