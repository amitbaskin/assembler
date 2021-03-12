#include "generalUtils.h"
#include "wordId.h"
#ifndef ASSEMBLER_OP_UTILS_H
#define ASSEMBLER_OP_UTILS_H
result validateTwoOps(char **line, int opIndex, char **firstOp, char **secOp, labelLst *labLst, label **lab, sWordLst
*instLst);
result validateOneOp(char **line, int opIndex, char **destOp, labelLst *labLst, label **lab, sWordLst *instLst);
result validateZeroOps(char **line, int opIndex, label **lab, labelLst *labLst, sWordLst *instLst);
result validateOperandsAmount(char **line, int opIndex, int operandsAmount, char **firstOp, char **secOp, labelLst
*labLst, label **lab, sWordLst *instLst);
ref getOperandType(char **operand, int *regNum, long *num);
unsigned char validateSrcOp(ref type, int opIndex);
unsigned char validateDestOp(ref type, int opIndex);
ref addOperandWord(ref r, char **operand, sWordLst *instLst, int reg, long num);
void addAllOperandsWord(int operandsAmount, char **firstOp, char **secOp, sWordLst *instLst, ref srcType, ref destType,
                        int srcReg, long srcNum, int destReg, long destNum);
result initOpWord(int opIndex, ref src, ref dest, opWord **op);
void processOp(int opIndex, int opsAmount, ref srcType, ref destType, char **firstOp, char **secOp, labelLst *labLst,
               label **lab, sWordLst *instLst, int srcReg, long srcNum, int destReg, long destNum);
#endif
