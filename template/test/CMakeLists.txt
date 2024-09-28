cmake_minimum_required(VERSION 3.10)

# Define Project File
project(FIFOTest)

# Set Include Dir
include_directories(../inc)
include_directories(../src)

# Find Google Test Pkg & Set Include Path
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Compaile Test Code
add_executable(test test.cpp)

# Link Google Test
target_link_libraries(test ${GTEST_LIBRARIES} pthread)

