cmake_minimum_required(VERSION 3.17)
project(assembler C)

set(CMAKE_C_STANDARD 90)

add_executable(assembler main.c generalUtils.c generalUtils.h opDef.c opDef.h wordId.c wordId.h wordTrans.c wordTrans.h labUtils.c labUtils.h sWordSetters.c sWordSetters.h parseLineUtils.c parseLineUtils.h parseLine.c parseLine.h numsData.c numsData.h strData.c strData.h opUtils.c opUtils.h firstParse.c firstParse.h secParse.c secParse.h outputUtils.c outputUtils.h uWordSetters.c uWordSetters.h opWordGetSet.c opWordGetSet.h sWordListUtils.c sWordListUtils.h sWordGetters.c sWordGetters.h uWordGetters.c uWordGetters.h labGetters.c labGetters.h labSetters.c labSetters.h labLstUtils.c labLstUtils.h fileUtils.c fileUtils.h sWordUtils.c sWordUtils.h uWordUtils.c uWordUtils.h assembler.c assembler.h globalVars.c rawWordLstUtils.c rawWordLstUtils.h rawWordUtils.c rawWordUtils.h errFuncs.c errFuncs.h globalVars.h)