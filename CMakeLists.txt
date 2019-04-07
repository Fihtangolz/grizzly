cmake_minimum_required(VERSION 3.9)
project(bear)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c parser.c parser.h types.h types.c ast_tree.h ast_tree.c)
add_executable(bear ${SOURCE_FILES} types.h ast_tree.h)