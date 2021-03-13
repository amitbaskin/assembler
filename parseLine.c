/* this file is used to process a line for an assembly file */

#include <string.h>
#include "parseLineUtils.h"
#include "labUtils.h"
#include "strData.h"
#include "opDefGetters.h"
#include "sWordListUtils.h"
#include "labSetters.h"
#include "labLstUtils.h"
#include "opUtils.h"
#include "errFuncs.h"
#include "numsData.h"

extern int labelFlag;
extern int instructionCounter;

/* bubble up errors and pass TRUE results as SUCCESS */
#define SWITCH_DATA_RES(res) {\
    switch (res){             \
        case ERR:             \
            return ERR; /* handled before hand */ \
                              \
        case TRUE:            \
            return SUCCESS;   \
                              \
        default:              \
            break;            \
    }                         \
}

/* general logic for checking if some condition holds and if so executes the appropriate scenario */
#define SWITCH_REF_RES(checkIfOrder, orderScenario) {\
    if ((checkIfOrder) == TRUE){                            \
        return orderScenario;                             \
    }                                                     \
}

result lookForLabel(char **line, char **word, label **lab){
    /* expects to find a legal label in the next word of the line and returns ERR if none exists, otherwise returns
     * SUCCESS */
    unsigned long len;
    getWord(line, word, 0);
    len = strlen(*word);
    if (getLegalLab(word, lab, len) != TRUE) {
        return ERR; /* handled inside */
    } return finishLine(line);
}

result entryScenario(char **line, char **word, label **lab, sWordLst *instLst){
    /* executes the entry scenario given that an entry statement has been encountered
     * saves the statement in the instruction list in order to handle it in the second parse to check if the
     * statement was valid */
    VALIDATE_VAL(lookForLabel(line, word, lab))
    setLabType(*lab, L_ENT);
    addLabToInstLst(instLst, *word, instructionCounter, W_ENT, L_ENT, 0);
    return TRUE;
}
result extScenario(char **line, char **word, label **lab, labelLst *labLst){
    /* executes the extern scenario given that an entry statement has been encountered
     * adds the given label to label list */
    VALIDATE_VAL(lookForLabel(line, word, lab))
    addLabToLabLst(labLst, lab, EXT, 0);
    return TRUE;
}

result lookForData(char **word, char **line, label **lab, labelLst *labLst, sWordLst *instLst, sWordLst *dataLst){
    SWITCH_DATA_RES(isNumDataScenario(*word, line, *lab, dataLst, labLst))
    SWITCH_DATA_RES(isStrScenario(*word, line, *lab, dataLst, labLst))
    SWITCH_REF_RES(isEntryOrder(*word), entryScenario(line, word, lab, instLst))
    SWITCH_REF_RES(isExternOrder(*word), extScenario(line, word, lab, labLst))
    return FALSE;
}

result lookForOperation(char **firstOp, char **secOp, char **word, char **line, label **lab, labelLst *labLst,
                        sWordLst *instLst){
    /* expects to find an operator statement and returns ERR if none encountered, otherwise returns SUCCESS
     * if all went well it adds the operator and its operands to the instructions list */
    int opsAmount;
    int opIndex = getOpIndexByStr(*word);
    if (opIndex == NOT_OP) {
        undefinedStatementErr();
        return ERR;
    } opsAmount = getOperandsAmount(opIndex);
    VALIDATE_VAL(validateOperation(opIndex, opsAmount, line, firstOp, secOp, labLst, lab, instLst))
    return SUCCESS;
}
