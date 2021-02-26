#include "generalUtils.h"
#include "machineWordIdentifiers.h"
#ifndef ASSEMBLER_PARSE_OP_UTILS_H
#define ASSEMBLER_PARSE_OP_UTILS_H
result validateTwoOps(char **line, char **firstOp, char **sep, char **secOp);
result validateOneOp(char **line, char **op);
result validateZeroOps(char **line);
result validateOperandsAmount(char **line, int operandsAmount, char **firstOp, char **sep, char **secOp);
ref getOperandType(char *operand, long *got, label *labHead);
result validateSrcOp(ref type, int opIndex);
result validateDestOp(ref type, int opIndex);
#endif
