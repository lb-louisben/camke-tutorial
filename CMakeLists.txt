cmake_minimum_required(VERSION 3.0)

project(
    CALC
    LANGUAGES C
    VERSION 1.0.0
    DESCRIPTION "Simple calculator"
)

add_executable(calculator add.c div.c main.c mult.c sub.c)
