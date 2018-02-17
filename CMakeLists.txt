cmake_minimum_required(VERSION 3.9)
project(corewar C)

set(CMAKE_C_STANDARD 99)

add_executable(corewar
        main.c
        src/process.h
        src/op.h
        src/main.c src/vm_loop.c src/environment.h)