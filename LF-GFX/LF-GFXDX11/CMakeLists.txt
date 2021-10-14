cmake_minimum_required(VERSION 3.19.3)

#Set Project Name
project(LF-GFX)

#Specify C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED)
add_definitions(-DUNICODE)
add_definitions(-D_UNICODE)

add_subdirectory(Source)