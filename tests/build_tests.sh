#!/bin/bash
set -e

# Navigate to the script's directory (tests/)
cd "$(dirname "$0")"

# Create build directory if it doesn't exist
mkdir -p build
cd build

# Configure and build
cmake ..
make

# Run tests
./drone_controller_tests 