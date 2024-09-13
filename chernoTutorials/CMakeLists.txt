# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.15)

# Project name
project(chernoTutorials)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)

# Compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wfatal-errors")

# Include directories
#include_directories(libs)

# Source files
file(GLOB SRC_FILES ./any.cpp)

# Executable name
set(OBJ_NAME chernoTutorials)

# Add the executable target
add_executable(${OBJ_NAME} ${SRC_FILES})

# Link against Lua library
#set(LUA_LIBRARY_PATH "C:/mingw64/x86_64-w64-mingw32/lib/liblua54.a")
#target_link_libraries(${OBJ_NAME} ${LUA_LIBRARY_PATH})

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