#include "generalUtils.h"
#include "machineWordIdentifiers.h"
#ifndef ASSEMBLER_PARSE_OP_UTILS_H
#define ASSEMBLER_PARSE_OP_UTILS_H
result validateTwoOps(char **line, char **firstOp, char **secOp);
result validateOneOp(char **line, char **op);
result validateZeroOps(char **line);
result validateOperandsAmount(char **line, int operandsAmount, char **firstOp, char **secOp);
ref getOperandType(char *operand, int *regType, long *num);
result validateSrcOp(ref type, int opIndex);
result validateDestOp(ref type, int opIndex);
#endif
