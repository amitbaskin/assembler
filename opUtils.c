#include <string.h>
#include "opUtils.h"
#include "generalUtils.h"
#include "wordId.h"
#include "opDefGetters.h"
#include "parseLineUtils.h"
#include "labUtils.h"
#include "sWordSetters.h"
#include "parseLine.h"
#include "labSetters.h"
#include "sWordListUtils.h"

#define VALIDATE_OP(opValidation, msg) { \
    if (opValidation == FALSE) {         \
        printf(msg);                     \
        return ERR;                      \
    }                                    \
}

#define VALIDATE_LINE_CONTINUATION(wordResult, msg){ \
    if (wordResult == FALSE) {                       \
        printf(msg);                                 \
        return ERR;                                  \
    }                                                \
}

#define VALIDATE_SEP(wordResult, msg){ \
    if (wordResult != SEP) {           \
        printf(msg);                   \
        return ERR;                    \
    }                                  \
}

#define CHECK_REF_TYPE(checkFunc, type){ \
    if (checkFunc == TRUE) return type;\
}

result validateTwoOps(char **line, char **firstOp, char **secOp, int opIndex, ref *srcType, ref *destType){
    int srcReg;
    long srcNum;
    int destReg;
    long destNum;
    char *sep;
    VALIDATE_LINE_CONTINUATION(getWord(line, firstOp, 0), "")
    VALIDATE_SEP(getWord(line, &sep, 1), "")
    getWord(line, secOp, 0);
    VALIDATE_VAL(finishLine(line), "")
    *srcType = getOperandType(*firstOp, &srcReg, &srcNum);
    *destType = getOperandType(*secOp, &destReg, &destNum);
    VALIDATE_OP(validateSrcOp(*srcType, opIndex),"")
    VALIDATE_OP(validateDestOp(*destType, opIndex),"")
    return SUCCESS;
}

result validateOneOp(char **line, char **op, int opIndex, ref *destType){
    int destReg;
    long destNum;
    VALIDATE_LINE_CONTINUATION(getWord(line, op, 0), "");
    VALIDATE_VAL(finishLine(line), "");
    *destType = getOperandType(*op, &destReg, &destNum);
    VALIDATE_OP(validateDestOp(*destType, opIndex), "")
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
    CHECK_REF_TYPE(isImmediateNum(num, operand), IM)
    CHECK_REF_TYPE(checkRel(operand), REL)
    CHECK_REF_TYPE(isLegalLabel(operand, strlen(operand)), DIR)
    return R_NONE;
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

ref addOperandWord(char *operand, labelLst *labLst, sWordLst *instLst){
    int regType;
    long num;
    ref r = getOperandType(operand, &regType, &num);
    switch(r){
        case IM:
            addNumWord(num, DIR_NUM, instLst);
            return IM;

        case DIR:
            addLabToInstLst(instLst, operand, L_NONE, 0);
            return DIR;

        case REL:
            addLabToInstLst(instLst, operand, L_NONE, 1);
            return REL;

        case R_REG:
            addRegWord(regType, instLst);
            return R_REG;

        default:
            return R_NONE;
    }
}

void addAllOperandsWord(int operandsAmount, char *firstOp, char *secOp, labelLst *labLst, sWordLst *instLst){
    if (operandsAmount > 0) addOperandWord(firstOp, labLst, instLst);
    if (operandsAmount == 2) addOperandWord(secOp, labLst, instLst);
}
