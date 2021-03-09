cmake_minimum_required(VERSION 3.17)
project(assembler C)

set(CMAKE_C_STANDARD 90)

add_executable(assembler main.c opDef.h opDef.c generalUtils.c generalUtils.h opDefGetters.c opDefGetters.h wordId.c wordId.h wordTrans.c wordTrans.h labUtils.c labUtils.h sWordSetters.c sWordSetters.h parseLineUtils.c parseLineUtils.h parseLine.c parseLine.h numsData.c numsData.h strData.c strData.h parseOp.c parseOp.h opUtils.c opUtils.h firstParse.c firstParse.h secParse.c secParse.h outputUtils.c outputUtils.h uWordSetters.c uWordSetters.h opWordGetters.c opWordGetters.h sWordListUtils.c sWordListUtils.h sWordGetters.c sWordGetters.h uWordGetters.c uWordGetters.h labGetters.c labGetters.h labSetters.c labSetters.h labLstUtils.c labLstUtils.h opWordSetters.c opWordSetters.h fileUtils.c fileUtils.h sWordUtils.c sWordUtils.h uWordUtils.c uWordUtils.h assembler.c assembler.h globalVars.c)