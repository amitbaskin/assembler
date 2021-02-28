cmake_minimum_required(VERSION 3.17)
project(assembler C)

set(CMAKE_C_STANDARD 90)

add_executable(assembler main.c operationsDef.h operationsDef.c generalUtils.c generalUtils.h operationsApi.c operationsApi.h wordIdentifiers.c wordIdentifiers.h wordTrans.c wordTrans.h labelUtils.c labelUtils.h sWordSetters.c sWordSetters.h parseLineUtils.c parseLineUtils.h parseLine.c parseLine.h numsData.c numsData.h strData.c strData.h parseLabel.c parseLabel.h parseOp.c parseOp.h parseOpUtils.c parseOpUtils.h firstParse.c firstParse.h secondParse.c secondParse.h outputFilesUtils.c outputFilesUtils.h uWordUtils.c uWordUtils.h opWordUtils.c opWordUtils.h sWordListUtils.c sWordListUtils.h sWordGetters.c sWordGetters.h)