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
#include "opWordSetters.h"
#include "sWordGetters.h"
#include "labLstUtils.h"

extern int instructionCounter;

#define VALIDATE_OP(opValidation, msg) { \
    if ((opValidation) == FALSE) {         \
        printf(msg);                     \
        return ERR;                      \
    }                                    \
}

#define VALIDATE_LINE_CONTINUATION(wordResult, msg){ \
    if ((wordResult) == FALSE) {                       \
        printf(msg);                                 \
        return ERR;                                  \
    }                                                \
}

#define VALIDATE_SEP(wordResult, msg){ \
    if ((wordResult) != SEP) {           \
        printf(msg);                   \
        return ERR;                    \
    }                                  \
}

#define CHECK_REF_TYPE(checkFunc, type){ \
    if ((checkFunc) == TRUE) return type;\
}                                        \

void processOp(int opIndex, int opsAmount, ref srcType, ref destType, char **firstOp, char **secOp, labelLst *labLst,
 label **lab, sWordLst *instLst, int srcReg, long srcNum, int destReg, long destNum){
    opWord *op;
    initOpWord(opIndex, srcType, destType, &op);
    checkLabFlagOnScenario(lab, labLst, setLabCode, instructionCounter);
    addOpWord(op, instLst);
    addAllOperandsWord(opsAmount, firstOp, secOp, instLst, srcType, destType, srcReg, srcNum, destReg, destNum);
}

result validateTwoOps(char **line, int opIndex, char **firstOp, char **secOp, labelLst *labLst, label **lab, sWordLst
*instLst){
    int srcReg;
    long srcNum;
    int destReg;
    long destNum;
    ref srcType;
    ref destType;
    result res;
    VALIDATE_LINE_CONTINUATION(res = getWord(line, firstOp, 1), "")
    VALIDATE_SEP(res, "")
    getWord(line, secOp, 0);
    VALIDATE_VAL(finishLine(line), "")
    srcType = getOperandType(*firstOp, &srcReg, &srcNum);
    destType = getOperandType(*secOp, &destReg, &destNum);
    VALIDATE_OP(validateSrcOp(srcType, opIndex),"")
    VALIDATE_OP(validateDestOp(destType, opIndex),"")
    processOp(opIndex, 2, srcType, destType, firstOp, secOp, labLst, lab, instLst, srcReg, srcNum, destReg, destNum);
    return SUCCESS;
}

result validateOneOp(char **line, int opIndex, char **DestOp, labelLst *labLst, label **lab, sWordLst *instLst){
    int destReg;
    long destNum;
    ref destType;
    VALIDATE_LINE_CONTINUATION(getWord(line, DestOp, 0), "");
    VALIDATE_VAL(finishLine(line), "");
    destType = getOperandType(*DestOp, &destReg, &destNum);
    VALIDATE_OP(validateDestOp(destType, opIndex), "")
    processOp(opIndex, 1, R_NONE, destType, DestOp, NULL, labLst, lab, instLst, NOT_REG, 0, destReg, destNum);
    return SUCCESS;
}

result validateZeroOps(char **line){
    return finishLine(line);
}

result validateOperandsAmount(char **line, int opIndex, int operandsAmount, char **firstOp, char **secOp, labelLst
*labLst, label **lab, sWordLst *instLst){
    switch (operandsAmount) {
        case 2:
            return validateTwoOps(line, opIndex, firstOp, secOp, labLst, lab, instLst);

        case 1:
            return validateOneOp(line, opIndex, firstOp, labLst, lab, instLst);

        case 0:
            return validateZeroOps(line);

        default:
            return ERR;
    }
}

ref getOperandType(char *operand, int *regNum, long *num){
    if ((*regNum = isReg(operand)) != NOT_REG) return R_REG;
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

ref addOperandWord(ref r, char **operand, sWordLst *instLst, int reg, long num){
    switch(r){
        case IM:
            addNumWord(num, IM_NUM, instLst);
            return IM;

        case DIR:
            addLabToInstLst(instLst, *operand, instructionCounter++, L_NONE, 0);
            return DIR;

        case REL:
            addLabToInstLst(instLst, *operand, instructionCounter++, L_NONE, 1);
            return REL;

        case R_REG:
            addRegWord(reg, instLst);
            return R_REG;

        default:
            return R_NONE;
    }
}

void addAllOperandsWord(int operandsAmount, char **firstOp, char **secOp, sWordLst *instLst, ref srcType, ref destType,
                        int srcReg, long srcNum, int destReg, long destNum){
    if (operandsAmount == 1) addOperandWord(destType, firstOp, instLst, destReg, destNum);
    if (operandsAmount == 2) {
        addOperandWord(srcType, firstOp, instLst, srcReg, srcNum);
        addOperandWord(destType, secOp, instLst, destReg, destNum);
    }
}

result initOpWord(int opIndex, ref src, ref dest, opWord **op){
    void *ptr;
    VALIDATE_VAL(getAlloc(sizeof(opWord), &ptr), "");
    *op = (opWord *) ptr;
    setOpIndex(*op, opIndex);
    setOpSrcRef(*op, src);
    setOpDestRef(*op, dest);
    return SUCCESS;
}

