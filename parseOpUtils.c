#include <string.h>
#include "parseOpUtils.h"
#include "generalUtils.h"
#include "wordIdentifiers.h"
#include "operationsApi.h"
#include "parseLineUtils.h"
#include "labelUtils.h"
#include "sWordSetters.h"

result validateTwoOps(char **line, char **firstOp, char **secOp, int opIndex, ref *srcType, ref *destType){
    int srcReg;
    long srcNum;
    int destReg;
    long destNum;
    char *sep;
    result res = getWord(line, firstOp, 0);
    if (res == LINE_END) return ERR;
    res = getWord(line, &sep, 1);
    if (res != SEP) return ERR;
    getWord(line, secOp, 0);
    res = finishLine(line);
    if (res == ERR) return res;
    *srcType = getOperandType(*firstOp, &srcReg, &srcNum);
    *destType = getOperandType(*secOp, &destReg, &destNum);
    res = validateSrcOp(*srcType, opIndex);
    if (res == FALSE) return ERR;
    res = validateDestOp(*destType, opIndex);
    if (res == FALSE) return ERR;
    return SUCCESS;
}

result validateOneOp(char **line, char **op, int opIndex, ref *destType){
    int destReg;
    long destNum;
    result res = getWord(line, op, 0);
    if (res == LINE_END) return ERR;
    res = finishLine(line);
    if (res == ERR) return res;
    *destType = getOperandType(*op, &destReg, &destNum);
    res = validateDestOp(*destType, opIndex);
    if (res == FALSE) return ERR;
    return SUCCESS;
}

result validateZeroOps(char **line){
    return finishLine(line);
}

result validateOperandsAmount(char **line, int operandsAmount, char **firstOp, char **secOp, int opIndex, ref
 *srcType, ref *destType){
    switch (operandsAmount) {
        case 2:
            return validateTwoOps(line, firstOp, secOp, opIndex, srcType, destType);
        case 1:
            return validateOneOp(line, firstOp, opIndex, destType);
        case 0:
            return validateZeroOps(line);
        default:
            return ERR;
    }
}

ref getOperandType(char *operand, int *regType, long *num){
    if ((*regType = isReg(operand)) != NOT_REG) return R_REG;
    if (isImmediateNum(num, operand) == TRUE) return IM;
    if (checkRel(operand) == TRUE) return REL;
    if (isLegalLabel(operand, strlen(operand)) == TRUE) return DIR;
    return NOT_REF;
}

result validateSrcOp(ref type, int opIndex){
    switch(type){
        case IM:
            return getIsImSrc(opIndex);
        case DIR:
            return getIsDirSrc(opIndex);
        case REL:
            return getIsRelSrc(opIndex);
        case R_REG:
            return getIsRegSrc(opIndex);
        default:
            return ERR;
    }
}

result validateDestOp(ref type, int opIndex){
    switch(type){
        case IM:
            return getIsImDest(opIndex);
        case DIR:
            return getIsDirDest(opIndex);
        case REL:
            return getIsRelDest(opIndex);
        case R_REG:
            return getIsRegDest(opIndex);
        default:
            return ERR;
    }
}

ref addOperandWord(char *operand, label *labHead, sWord **sWordLst){
    int regType;
    long num;
    ref r = getOperandType(operand, &regType, &num);
    switch(r){
        case IM:
            addNumWord(num, sWordLst);
            return IM;
        case DIR:
            addLabToInstLst(sWordLst, strlen(operand), operand, NONE, labHead, 0);
            return DIR;
        case REL:
            addLabToInstLst(sWordLst, strlen(operand), operand, NONE, labHead, 1);
            return REL;
        case R_REG:
            addRegWord(regType, sWordLst);
            return R_REG;
        default:
            return NOT_REF;
    }
}

void addAllOperandsWord(int operandsAmount, char *firstOp, char *secOp, label *labHead, sWord **sWordLst){
    if (operandsAmount > 0) addOperandWord(firstOp, labHead, sWordLst);
    if (operandsAmount == 2) addOperandWord(secOp, labHead, sWordLst);
}
