cmake_minimum_required(VERSION 3.10)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(FFT VERSION 1.0)


include_directories(includes)

add_executable(run src/main.cpp)
add_executable(test tests/test.cpp)


        