cmake_minimum_required(VERSION 3.7)
project(hsnr_ooa_dp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Strategy.h Observer.h)
add_executable(hsnr_ooa_dp ${SOURCE_FILES})