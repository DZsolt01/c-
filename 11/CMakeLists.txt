cmake_minimum_required(VERSION 3.20)
project(11)

set(CMAKE_CXX_STANDARD 20)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/index.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
add_executable(11 Main.cpp TextIndexer.cpp TextIndexer.h)
