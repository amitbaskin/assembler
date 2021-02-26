#include "parseOpUtils.h"
#include "generalUtils.h"
#include "machineWordIdentifiers.h"
#include "operationsApi.h"
#include "parseLineUtils.h"
#include "labelApi.h"

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

ref getOperandType(char *operand, int *regType, long *num, label **lab, label *labHead){
    if ((*regType = isReg(operand)) != NOT_REG) return R_REG;
    if (isImmediateNum(num, operand)) return IM;
    if (isLabelInLst(labHead, lab, operand)) return DIR;
    if (isRel(operand, lab, labHead)) return REL;
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
