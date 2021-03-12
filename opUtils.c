#include <string.h>
#include "ctype.h"
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
#include "errFuncs.h"


extern int instructionCounter;
extern int labelFlag;

#define VALIDATE_OP(opValidation) { \
    if ((opValidation) == 0) {  \
        operandErr();               \
        return ERR;                 \
    }                               \
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
    res = getWord(line, firstOp, 1);
    if (**firstOp == '\0'){
        lineEndErr();
        return ERR;
    } if (res != SEP) {
        noSepAfterFirstOperand();
        return ERR;
    } getWord(line, secOp, 0);
    if (**secOp == '\0'){
        lineEndErr();
        return ERR;
    } VALIDATE_VAL(finishLine(line))
    srcType = getOperandType(firstOp, &srcReg, &srcNum);
    if (srcType == R_NONE) return ERR; /* already handled */
    destType = getOperandType(secOp, &destReg, &destNum);
    if (destType == R_NONE) return ERR; /* already handled */
    if (validateSrcOp(srcType, opIndex) == 0){
        operandErr();
        return ERR;
    } if (validateDestOp(destType, opIndex) == 0){
        operandErr();
        return ERR;
    } processOp(opIndex, 2, srcType, destType, firstOp, secOp, labLst, lab, instLst, srcReg, srcNum, destReg, destNum);
    return SUCCESS;
}

result validateOneOp(char **line, int opIndex, char **destOp, labelLst *labLst, label **lab, sWordLst *instLst){
    int destReg;
    long destNum;
    ref destType;
    getWord(line, destOp, 0);
    if (**destOp == '\0'){
        lineEndErr();
        return ERR;
    } VALIDATE_VAL(finishLine(line))
    destType = getOperandType(destOp, &destReg, &destNum);
    VALIDATE_OP(validateDestOp(destType, opIndex))
    processOp(opIndex, 1, R_NONE, destType, destOp, NULL, labLst, lab, instLst, NOT_REG, 0, destReg, destNum);
    return SUCCESS;
}

result validateZeroOps(char **line, int opIndex, label **lab, labelLst *labLst, sWordLst *instLst){
    opWord *op;
    initOpWord(opIndex, R_NONE, R_NONE, &op);
    checkLabFlagOnScenario(lab, labLst, setLabCode, instructionCounter);
    addOpWord(op, instLst);
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
            return validateZeroOps(line, opIndex, lab, labLst, instLst);
        default:
            return ERR; /* not supposed to be possible to get here */
    }
}

ref getOperandType(char **operand, int *regNum, long *num){
    result res;
    if (isdigit(**operand)) {
        noNumPrefixErr();
        return R_NONE;
    } if ((*regNum = isReg(*operand)) != NOT_REG) return R_REG;
    res = isImmediateNum(num,  *operand);
    if (res == ERR) return R_NONE;
    CHECK_REF_TYPE(res, IM)
    CHECK_REF_TYPE(checkRel(operand), REL)
    CHECK_REF_TYPE(isLegalLabFormat(*operand, strlen(*operand)), DIR)
    return R_NONE;
}

unsigned char validateSrcOp(ref type, int opIndex){
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
            return 0; /* not supposed to be possible to get here */
    }
}

unsigned char validateDestOp(ref type, int opIndex){
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
            return 0; /* not supposed to be possible to get here */
    }
}

ref addOperandWord(ref r, char **operand, sWordLst *instLst, int reg, long num){
    switch(r){
        case IM:
            addNumWord(num, instructionCounter++, IM_NUM, instLst);
            return IM;

        case DIR:
            addLabToInstLst(instLst, *operand, instructionCounter++, LAB, L_NONE, 0);
            return DIR;

        case REL:
            addLabToInstLst(instLst, *operand, instructionCounter++, LAB, L_NONE, 1);
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
    VALIDATE_VAL(getAlloc(sizeof(opWord), &ptr))
    *op = (opWord *) ptr;
    setOpIndex(*op, opIndex);
    setOpSrcRef(*op, src);
    setOpDestRef(*op, dest);
    return SUCCESS;
}
