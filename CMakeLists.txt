cmake_minimum_required(VERSION 3.9)
project(zadanie4 C)

set(CMAKE_C_STANDARD 99)

add_executable(zadanie4 game.c helpers.h deployment_grid.c actions.c)