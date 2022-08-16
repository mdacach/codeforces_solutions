cmake_minimum_required(VERSION 3.21)
project(d)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -O2 -Wall -Wshadow -Wextra -Wformat=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -Wfatal-errors -Wno-unused-variable")

set(CMAKE_CXX_STANDARD 14)

add_executable(d
        d.cpp)
