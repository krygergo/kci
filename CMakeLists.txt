cmake_minimum_required(VERSION 3.16)
project(kci C)

set(CMAKE_C_STANDARD 11)

find_package( Threads )

add_executable(kci source/main.c source/interpreter.c )

target_link_libraries( kci ${CMAKE_THREAD_LIBS_INIT} )