#include "wordId.h"
#include "generalUtils.h"
#ifndef ASSEMBLER_OP_UTILS_H
#define ASSEMBLER_OP_UTILS_H
result validateOperation(int opIndex, int opsAmount, char **line, char **firstOp, char **secOp, labelLst *labLst,
                         label **lab, sWordLst *instLst);
#endif
