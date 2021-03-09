#include "generalUtils.h"
#include "wordId.h"
#ifndef ASSEMBLER_OP_UTILS_H
#define ASSEMBLER_OP_UTILS_H
result validateTwoOps(char **line, int opIndex, char **firstOp, char **secOp, sWordLst *instLst, labelLst *labLst);
result validateOneOp(char **line, int opIndex, char **op, sWordLst *instLst, labelLst *labLst);
result validateZeroOps
(char **line);
result validateOperandsAmount(char **line, int opIndex, int operandsAmount, char **firstOp, char **secOp, sWordLst
*instLst, labelLst *labLst);
ref getOperandType(char *operand, int *regType, long *num);
result validateSrcOp(ref type, int opIndex);
result validateDestOp(ref type, int opIndex);
ref addOperandWord(ref r, char *operand, sWordLst *instLst, int reg, long num);
void addAllOperandsWord(int operandsAmount, char *firstOp, char *secOp, sWordLst *instLst, ref srcType, ref destType,
                        int srcReg, long srcNum, int destReg, long destNum);
result initOpWord(int opIndex, ref src, ref dest, opWord **op);
#endif
