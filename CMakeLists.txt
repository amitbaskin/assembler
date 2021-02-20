cmake_minimum_required(VERSION 3.17)
project(assembler C)

set(CMAKE_C_STANDARD 90)

add_executable(assembler main.c operationsDef.h operationsDef.c generalUtils.c generalUtils.h operationsApi.c operationsApi.h machineWordIdentifiers.c machineWordIdentifiers.h machineWordTranslation.c machineWordTranslation.h labelUtils.c labelUtils.h manageMachineWord.c manageMachineWord.h parseLineUtils.c parseLineUtils.h parseLine.c parseLine.h)