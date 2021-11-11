cmake_minimum_required(VERSION 3.20)
project(parcialis)

set(CMAKE_CXX_STANDARD 20)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/applications.csv
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
add_executable(parcialis Application.cpp Application.h AppStore.cpp AppStore.h main.cpp)
