cmake_minimum_required(VERSION 3.24)
project(LibMat C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(LibMat
        include/libmat.h
        srcs/destroy.c
        srcs/init.c srcs/fill.c srcs/main.c srcs/draw.c srcs/multiplication.c srcs/addition.c srcs/negative.c srcs/substractio.c srcs/division.c srcs/transposition.c srcs/inversion.c)
