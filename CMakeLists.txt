cmake_minimum_required(VERSION 3.21)
project(stacks_and_queues)

set(CMAKE_CXX_STANDARD 17)

add_executable(stacks_and_queues main.cpp my_stack.h stack_interface.h pairs_stack.h)
