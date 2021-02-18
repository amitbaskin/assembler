cmake_minimum_required(VERSION 3.17)
project(assembler C)

set(CMAKE_C_STANDARD 90)

add_executable(assembler main.c operationsDef.h operationsDef.c utils.c utils.h operationsApi.c operationsApi.h machineWord.c machineWord.h)