cmake_minimum_required(VERSION 3.12)
project(listt C)

set(CMAKE_C_STANDARD 99)

add_executable(listt main.c biblioteca/list.c biblioteca/list.h)