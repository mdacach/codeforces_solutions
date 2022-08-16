#!/bin/bash
code_template='/home/crs/competitive_programming_library/template.cpp'
touch main.cpp
cp $code_template main.cpp
cmake_template='/home/crs/competitive_programming_library/CMakeLists.txt'
touch CMakeLists.txt
cp $cmake_template CMakeLists.txt
