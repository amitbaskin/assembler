#include "generalUtils.h"
#include "wordId.h"
#ifndef ASSEMBLER_PARSE_OP_H
#define ASSEMBLER_PARSE_OP_H
result validateOperation(int opIndex, int opsAmount, char **line, char **firstOp, char **secOp, labelLst *labLst,
                         label **lab, sWordLst *instLst);
#endif
