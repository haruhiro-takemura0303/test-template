#!/bin/bash

# Exit immediately if a command exits with a non-zero status
set -e

# Create build directory if it doesn't exist
if [ ! -d "build" ]; then
    mkdir build
fi

# Navigate to build directory
cd build

# Run CMake to configure the project
cmake ..

# Navigate back to the parent directory
cd ..

# Compile the project
make -C build

# Output message
echo "Build complete! Run the tests with ./build/test"

# Exec Test
echo "==============Start Test==================="
./build/test
