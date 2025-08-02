cmake_minimum_required(VERSION 3.10)
project(StackQueue C)

set(CMAKE_C_STANDARD 11)

add_library(stack_queue src/stack_queue.c)

add_executable(test_stack_queue test/test_stack_queue.c)
target_link_libraries(test_stack_queue stack_queue)

enable_testing()
add_test(NAME test_stack_queue COMMAND test_stack_queue)
