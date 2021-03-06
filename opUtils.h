#include "generalUtils.h"
#include "wordId.h"
#ifndef ASSEMBLER_OP_UTILS_H
#define ASSEMBLER_OP_UTILS_H
result validateTwoOps(char **line, char **firstOp, char **secOp, int opIndex, ref *srcType, ref *destType);
result validateOneOp(char **line, char **op, int opIndex, ref *destType);
result validateZeroOps(char **line);
result validateOperandsAmount(char **line, int operandsAmount, char **firstOp, char **secOp, int opIndex, ref
*srcType, ref *destType);
ref getOperandType(char *operand, int *regType, long *num);
result validateSrcOp(ref type, int opIndex);
result validateDestOp(ref type, int opIndex);
void addAllOperandsWord(int operandsAmount, char *firstOp, char *secOp, labelLst *labLst, sWordLst *instLst);
#endif
