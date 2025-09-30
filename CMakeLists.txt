cmake_minimum_required(VERSION 4.0)
project(Lection1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lection1 main.c
        domain.c
        domain.h
        collection.c)
