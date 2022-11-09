cmake_minimum_required(VERSION 3.23)
project(compilers C)

set(CMAKE_C_STANDARD 11)

add_executable(compilers src/main.c src/tac.c src/tree.c src/list.c)
