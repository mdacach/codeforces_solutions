cmake_minimum_required(VERSION 3.21)
project(main)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -Wall -Wshadow -Wextra -Wformat=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -Wfatal-errors -Wno-unused-variable")

add_executable(main temp.cpp)
