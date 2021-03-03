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
    VALIDATE_FUNC_CALL(finishLine(line), "")
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
    result res;
    VALIDATE_FUNC_CALL(finishLine(line), "");
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
            addNumWord(num, DIR_NUM, sWordLst);
            return IM;

        case DIR:
            addLabToInstLst(sWordLst, operand, NONE, labHead, 0);
            return DIR;

        case REL:
            addLabToInstLst(sWordLst, operand, NONE, labHead, 1);
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
