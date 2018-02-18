cmake_minimum_required(VERSION 3.9)
project(corewar C)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES
        src/process.h
        src/op.h
        src/main.c
        src/vm_loop.c
        src/environment.h
        src/moving.c
        src/check_live_exec.c
        src/loop_manager.h
        src/log.c src/operation_processing.c)

add_subdirectory(libft)

include_directories(libft/includes)

add_executable(corewar ${SOURCE_FILES})

target_link_libraries(corewar libft)