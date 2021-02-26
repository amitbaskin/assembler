#include <string.h>
#include "parseOpUtils.h"
#include "generalUtils.h"
#include "machineWordIdentifiers.h"
#include "operationsApi.h"
#include "parseLineUtils.h"
#include "labelApi.h"
#include "manageMachineWord.h"

result validateTwoOps(char **line, char **firstOp, char **secOp){
    char *sep;
    result res = getWord(line, firstOp, 0);
    if (res == LINE_END) return ERR;
    res = getWord(line, &sep, 1);
    if (res != SEP) return ERR;
    getWord(line, secOp, 0);
    return finishLine(line);
}

result validateOneOp(char **line, char **op){
    result res = getWord(line, op, 0);
    if (res == LINE_END) return ERR;
    return finishLine(line);
}

result validateZeroOps(char **line){
    return finishLine(line);
}

result validateOperandsAmount(char **line, int operandsAmount, char **firstOp, char **secOp){
    switch (operandsAmount) {
        case 2:
            return validateTwoOps(line, firstOp, secOp);
        case 1:
            return validateOneOp(line, firstOp);
        case 0:
            return validateZeroOps(line);
        default:
            return ERR;
    }
}

ref getOperandType(char *operand, int *regType, long *num){
    if ((*regType = isReg(operand)) != NOT_REG) return R_REG;
    if (isImmediateNum(num, operand) == TRUE) return IM;
    if (isRel(operand) == TRUE) return REL;
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
            addLabWord(sWordLst, strlen(operand), operand, labHead, 0);
            return DIR;
        case REL:
            addLabWord(sWordLst, strlen(operand), operand, labHead, 1);
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