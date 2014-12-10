cmake_minimum_required(VERSION 2.8.4)
project(Nirs)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp
ConfigINI.h
ConfigINI.cpp
CountSign.cpp
CountSign.h
SObject.cpp
SObject.h
Point.cpp
Point.h
RLS.cpp
RLS.h
Mosh.cpp
Mosh.h)
add_executable(Nirs ${SOURCE_FILES})