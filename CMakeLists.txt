cmake_minimum_required(VERSION 3.10)
project(ColorCodeManual)

set(CMAKE_CXX_STANDARD 17)

# Library for core logic
add_library(colorcoder src/ColorCoder.cpp)

# Executable for demo/manual print
add_executable(manual src/ManualPrinter.cpp)
target_link_libraries(manual colorcoder)

# Enable testing
enable_testing()
add_subdirectory(tests)
