/* this file is used to handle operator statements */

#include <string.h>
#include <ctype.h>
#include "opDef.h"
#include "parseLineUtils.h"
#include "labUtils.h"
#include "labSetters.h"
#include "sWordListUtils.h"
#include "opWordGetSet.h"
#include "labLstUtils.h"
#include "errFuncs.h"
#include "globalVars.h"


/* general logic for validating an operand
 * returns ERR if the validation statement returned 0 */
#define VALIDATE_OP(opValidation) { \
    if ((opValidation) == 0) {      \
        operandErr();               \
        return ERR;                 \
    }                               \
}

/* general logic to get the type of an operand
 * if the check statement returned TRUE then it returns the type given */
#define CHECK_REF_TYPE(checkFunc, type){ \
    if ((checkFunc) == TRUE) return type;\
}                                        \

ref getOperandType(char **operand, int *regNum, long *num){
    /* get the type of a given operand
     * if it is not valid returns the R_NONE constant saying it refers to NONE operand (symbolises the invalidation) */
    result res;
    if (isdigit(**operand)) {
        noNumPrefixErr();
        return R_NONE;
    }
    if ((*regNum = isReg(*operand)) != NOT_REG) return R_REG;
    res = isImmediateNum(num,  *operand);
    if (res == ERR) return R_NONE;
    CHECK_REF_TYPE(res, IM)
    CHECK_REF_TYPE(checkRel(operand), REL)
    CHECK_REF_TYPE(isLegalLabHelper(*operand, strlen(*operand)), DIR)
    return R_NONE;
}

unsigned char validateSrcOp(ref type, int opIndex){
    /* checks if the given source operand type suits the operator in the given index
     * returns 1 if it does and 0 otherwise */
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
            return 0; /* the switch statement is used here for readability but it should not be possible to
            * get to this default statement because this function should always get a type of one of the mentioned
            types above */
    }
}

unsigned char validateDestOp(ref type, int opIndex){
    /* checks if the given dest operand type suits the operator in the given index
     * returns 1 if it does and 0 otherwise */
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
            return 0;  /* the switch statement is used here for readability but it should not be possible to
            * get to this default statement because this function should always get a type of one of the mentioned
            types above */
    }
}

ref addOperandWord(ref r, char **operand, sWordLst *instLst, int reg, long num){
    /* adds an operand word to the instruction list according to the given type */
    switch(r){
        case IM:
            addNumWord(num, getInstructionCounter(), IM_NUM, instLst);
            updateInstructionCounter();
            return IM;

        case DIR:
            addLabToInstLst(instLst, *operand, getInstructionCounter(), LAB, L_NONE, 0);
            updateInstructionCounter();
            return DIR;

        case REL:
            addLabToInstLst(instLst, *operand, getInstructionCounter(), LAB, L_NONE, 1);
            updateInstructionCounter();
            return REL;

        case R_REG:
            addRegWord(reg, instLst);
            return R_REG;

        default:
            return R_NONE; /* the switch statement is used here for readability but it should not be possible to
            * get to this default statement because this function should always get a type of one of the mentioned
            types above */
    }
}

void addAllOperandsWord(int operandsAmount, char **firstOp, char **secOp, sWordLst *instLst, ref srcType, ref destType,
                        int srcReg, long srcNum, int destReg, long destNum){
    /* adds operands words to the instruction list according to the data collected in the arguments of this function
     * this is being executed also according to the number of operands specified by the operandsAmount variable that
     * should be added */
    if (operandsAmount == 1) addOperandWord(destType, firstOp, instLst, destReg, destNum);
    if (operandsAmount == 2) {
        addOperandWord(srcType, firstOp, instLst, srcReg, srcNum);
        addOperandWord(destType, secOp, instLst, destReg, destNum);
    }
}

result initOpWord(int opIndex, ref src, ref dest, opWord **op){
    /* allocates memory for an operator word */
    void *ptr;
    VALIDATE_VAL(getAlloc(sizeof(opWord), &ptr))
    *op = (opWord *) ptr;
    setOpIndex(*op, opIndex);
    setOpSrcRef(*op, src);
    setOpDestRef(*op, dest);
    return SUCCESS;
}

void processOp(int opIndex, int opsAmount, ref srcType, ref destType, char **firstOp, char **secOp, labelLst *labLst,
 label **lab, sWordLst *instLst, int srcReg, long srcNum, int destReg, long destNum){
    /* processes the operator statement according to the data collected in the arguments of this function */
    opWord *op;
    initOpWord(opIndex, srcType, destType, &op);
    labFlagOnScenario(lab, labLst, getInstructionCounter(), 0);
    addOpWord(op, instLst);
    addAllOperandsWord(opsAmount, firstOp, secOp, instLst, srcType, destType, srcReg, srcNum, destReg, destNum);
}

result validateTwoOps(char **line, int opIndex, char **firstOp, char **secOp, labelLst *labLst, label **lab,
                       sWordLst *instLst){
    /* makes sure the operator gets two operands in the right format and verifies the suitability of the two given
     * operands to the given operator specified by the opIndex variable, i.e. by it's index in the operators list,
     * given that this operator indeed accepts two operands.
     * furthermore it adds the operator and operands to the instructions list if all went well and returns ERR
     * otherwise */
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
    }
    if (res != SEP) {
        noSepAfterFirstOperandErr();
        return ERR;
    }
    getWord(line, secOp, 0);
    if (**secOp == '\0'){
        lineEndErr();
        return ERR;
    }
    VALIDATE_VAL(finishLine(line))
    srcType = getOperandType(firstOp, &srcReg, &srcNum);
    if (srcType == R_NONE) return ERR; /* already handled */
    destType = getOperandType(secOp, &destReg, &destNum);
    if (destType == R_NONE) return ERR; /* already handled */
    if (validateSrcOp(srcType, opIndex) == 0){
        operandErr();
        return ERR;
    }
    if (validateDestOp(destType, opIndex) == 0){
        operandErr();
        return ERR;
    }
    processOp(opIndex, 2, srcType, destType, firstOp, secOp, labLst, lab, instLst, srcReg, srcNum, destReg, destNum);
    return SUCCESS;
}

result validateOneOp(char **line, int opIndex, char **destOp, labelLst *labLst, label **lab, sWordLst *instLst){
    /* makes sure the operator gets one operand in the right format and verifies the suitability of the given
     * operand to the given operator specified by the opIndex variable, i.e. by it's index in the operators list,
     * given that this operator indeed accepts one operand.
     * furthermore it adds the operator and operand to the instructions list if all went well and returns ERR
     * otherwise */
    int destReg;
    long destNum;
    ref destType;
    unsigned long len;
    getWord(line, destOp, 0);
    if (**destOp == '\0'){
        lineEndErr();
        return ERR;
    }
    len = strlen(*destOp);
    if (len == 1 && **destOp == NUM_PREFIX) {
        imNumErr();
        return ERR;
    }
    VALIDATE_VAL(finishLine(line))
    destType = getOperandType(destOp, &destReg, &destNum);
    VALIDATE_OP(validateDestOp(destType, opIndex))
    processOp(opIndex, 1, R_NONE, destType, destOp, NULL, labLst, lab, instLst, NOT_REG, 0, destReg, destNum);
    return SUCCESS;
}

result validateZeroOps(char **line, int opIndex, label **lab, labelLst *labLst, sWordLst *instLst){
    /* makes sure the operator gets zero operands given that the operator specified by the opIndex variable operator
     * indeed doesn't accept any operands.
     * furthermore it adds the operator to the instructions list if all went well and returns ERR otherwise */
    opWord *op;
    initOpWord(opIndex, R_NONE, R_NONE, &op);
    labFlagOnScenario(lab, labLst, getInstructionCounter(), 0);
    addOpWord(op, instLst);
    return finishLine(line);
}

result validateOperands(char **line, int opIndex, int operandsAmount, char **firstOp, char **secOp,
                        labelLst *labLst, label **lab, sWordLst *instLst){
    /* validates that the right amount of operands was given to the specified operator and furthermore verifies the
     * validity of the operands if there should be any.
     * returns ERR if some error has occurred in the process and SUCCESS otherwise */
    switch (operandsAmount) {
        case 2:
            return validateTwoOps(line, opIndex, firstOp, secOp, labLst, lab, instLst);

        case 1:
            return validateOneOp(line, opIndex, firstOp, labLst, lab, instLst);

        case 0:
            return validateZeroOps(line, opIndex, lab, labLst, instLst);

        default:
            return ERR; /* the switch statement is used here for readability but it should not be possible to
            * get to this default statement because this function should always get operands amount between 0 to 2 */
    }
}

 result validateOperation(int opIndex, int opsAmount, char **line, char **firstOp, char **secOp, labelLst *labLst,
                         label **lab, sWordLst *instLst){
    /* the entire flow for validating an operator statement */
    VALIDATE_VAL(validateOperands(line, opIndex, opsAmount, firstOp, secOp, labLst, lab, instLst))
    VALIDATE_VAL(finishLine(line))
    return SUCCESS;
}
