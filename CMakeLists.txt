cmake_minimum_required(VERSION 4.1)
project(PQ_Analyser C)

set(CMAKE_C_STANDARD 99)

add_executable(PQ_Analyser main.c
        io.h
        io.c
        waveform.h
        waveform.c)
