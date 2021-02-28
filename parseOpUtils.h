#include "generalUtils.h"
#include "wordIdentifiers.h"
#ifndef ASSEMBLER_PARSE_OP_UTILS_H
#define ASSEMBLER_PARSE_OP_UTILS_H
result validateTwoOps(char **line, char **firstOp, char **secOp, int opIndex, ref *srcType, ref *destType);
result validateOneOp(char **line, char **op, int opIndex, ref *destType);
result validateZeroOps(char **line);
result validateOperandsAmount(char **line, int operandsAmount, char **firstOp, char **secOp, int opIndex, ref
*srcType, ref *destType);
ref getOperandType(char *operand, int *regType, long *num);
result validateSrcOp(ref type, int opIndex);
result validateDestOp(ref type, int opIndex);
void addAllOperandsWord(int operandsAmount, char *firstOp, char *secOp, label *labHead, sWord **sWordLst);
#endif
