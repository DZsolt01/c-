cmake_minimum_required(VERSION 3.20)
project(10_2)

set(CMAKE_CXX_STANDARD 20)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/names.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/math.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/romanian.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/hungarian.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

add_executable(10_2 Student.cpp Student.cpp Student.h GraduationExam.cpp GraduationExam.h Main.cpp GraduationInfo.cpp GraduationInfo.h IGraduation.h)
