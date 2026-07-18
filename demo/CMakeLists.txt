cmake_minimum_required(VERSION 3.15)

project(HelloWorldDemo C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(/utf-8)
endif()

add_executable(demo_app src/main.c)

find_package(raylib CONFIG REQUIRED)
target_link_libraries(demo_app PRIVATE raylib)
