cmake_minimum_required(VERSION 3.21)
project(stacks_and_queues)

set(CMAKE_CXX_STANDARD 17)

add_executable(stacks_and_queues main.cpp stack_impls/my_stack.h stack_impls/istack.h stack_impls/pairs_stack.h queues_impls/iqueue.h queues_impls/reducing_queue.h queues_impls/two_stacks_queue.h)
