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

extern labelFlag;
extern instructionCounter;

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

#define SWITCH_REF_RES(checkIfOrder, orderScenario, msg) {\
    if ((checkIfOrder) == TRUE){                            \
        return orderScenario;                             \
    }                                                     \
}

result lookForLabel(char **line, char **word, label **lab){
    unsigned long len;
    getWord(line, word, 0);
    len = strlen(*word);
    if (getLegalLab(word, lab, len) != TRUE) {
        return ERR; /* handled inside */
    } return finishLine(line);
}

result entryScenario(char **line, char **word, label **lab, sWordLst *instLst){
    VALIDATE_VAL(lookForLabel(line, word, lab))
    setLabType(*lab, L_ENT);
    addLabToInstLst(instLst, *word, instructionCounter, W_ENT, L_ENT, 0);
    return TRUE;
}
result extScenario(char **line, char **word, label **lab, labelLst *labLst){
    VALIDATE_VAL(lookForLabel(line, word, lab))
    addLabToLabLst(labLst, lab, EXT, 0);
    return TRUE;
}

result lookForData(char **word, char **line, label **lab, labelLst *labLst, sWordLst *instLst, sWordLst *dataLst){
    SWITCH_DATA_RES(isNumDataScenario(*word, line, *lab, dataLst, labLst))
    SWITCH_DATA_RES(isStrScenario(*word, line, *lab, dataLst, labLst))
    SWITCH_REF_RES(isEntryOrder(*word), entryScenario(line, word, lab, instLst), "")
    SWITCH_REF_RES(isExternOrder(*word), extScenario(line, word, lab, labLst), "")
    return FALSE;
}

result lookForOperation(char **firstOp, char **secOp, char **word, char **line, label **lab, labelLst *labLst,
                        sWordLst *instLst){
    int opsAmount;
    int opIndex = getOpIndexByStr(*word);
    if (opIndex == NOT_OP) {
        undefinedStatementErr();
        return ERR;
    } opsAmount = getOperandsAmount(opIndex);
    VALIDATE_VAL(validateOperation(opIndex, opsAmount, line, firstOp, secOp, labLst, lab, instLst))
    return SUCCESS;
}
