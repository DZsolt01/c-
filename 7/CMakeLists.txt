cmake_minimum_required(VERSION 3.20)
project(7)

set(CMAKE_CXX_STANDARD 14)

add_executable(7 customers.txt mainAccount.cpp Account.cpp Account.h Customer.cpp Customer.h Bank.cpp Bank.h)
