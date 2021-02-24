cmake_minimum_required(VERSION 3.17)
project(assembler C)

set(CMAKE_C_STANDARD 90)

add_executable(assembler main.c operationsDef.h operationsDef.c generalUtils.c generalUtils.h operationsApi.c operationsApi.h machineWordIdentifiers.c machineWordIdentifiers.h machineWordTranslation.c machineWordTranslation.h labelApi.c labelApi.h manageMachineWord.c manageMachineWord.h parseLineUtils.c parseLineUtils.h parseLine.c parseLine.h numsData.c numsData.h strData.c strData.h parseLabel.c parseLabel.h)