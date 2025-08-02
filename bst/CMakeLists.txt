cmake_minimum_required(VERSION 3.10)
project(BinarySearchTree C)

set(CMAKE_C_STANDARD 11)

# Указываем, где искать заголовочные файлы
include_directories(src)

# Основная библиотека
add_library(bst src/bst.c)

# Тесты
add_executable(test_bst test/test_bst.c)
target_link_libraries(test_bst bst)

# Установка для тестов
enable_testing()
add_test(NAME test_bst COMMAND test_bst)
