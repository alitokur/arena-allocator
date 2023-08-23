cmake_minimum_required(VERSION 3.13)
project(trading_system VERSION 1.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)
add_executable(exe 
    main.cpp
    src/default.cpp
    src/linear.cpp
    )

