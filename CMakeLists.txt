cmake_minimum_required(VERSION 4.0)
project(Pashaev_Mekhman_cw C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(Pashaev_Mekhman_cw
        src/commands.c
        src/commands.h
        src/main.c
        src/text.c
        src/text.h)
