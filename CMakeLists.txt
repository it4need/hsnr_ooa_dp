cmake_minimum_required(VERSION 3.7)
project(hsnr_ooa_dp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Strategy.h Observer.h Decorator.h Singleton.h State.h State/IGeldautomatState.h State/NoCard.h State/Geldautomat.h State/HasCard.h State/HasPin.h State/NoCash.h State/Geldautomat.cpp State/HasCard.cpp State/NoCard.cpp State/NoCash.cpp State/HasPin.cpp)
add_executable(hsnr_ooa_dp ${SOURCE_FILES})