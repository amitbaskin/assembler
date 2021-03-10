#include <string.h>
#include "parseLine.h"
#include "generalUtils.h"
#include "parseLineUtils.h"
#include "labUtils.h"
#include "sWordSetters.h"
#include "numsData.h"
#include "strData.h"
#include "opDefGetters.h"
#include "parseOp.h"
#include "sWordSetters.h"
#include "sWordListUtils.h"
#include "opWordGetters.h"
#include "labSetters.h"
#include "labLstUtils.h"
#include "sWordGetters.h"
#include "opUtils.h"

extern labelFlag;

#define SWITCH_DATA_RES(res) {\
    switch (res){             \
        case ERR:             \
            return ERR;       \
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

result entryScenario(char **line, char **word, label **lab, sWordLst *instLst){
    VALIDATE_VAL(lookForLabel(line, word, lab), "");
    setLabType(*lab, L_ENT);
    addLabToInstLst(instLst, *word, 0, L_ENT, 0);
    return TRUE;
}
result extScenario(char **line, char **word, label **lab, labelLst *labLst){
    VALIDATE_VAL(lookForLabel(line, word, lab), "");
    addLabToLabLst(labLst, lab, EXT, 0);
    return TRUE;
}

result lookForData(char **word, char **line, label **lab, labelLst *labLst, sWordLst *instLst, sWordLst *dataLst){
    result res;
    getWord(line, word, 0);
    VALIDATE_VAL(res = isLabelDeclaration(*word, lab, strlen(*word)), "")
    if (res == TRUE) {
        labelFlag = 1;
        getWord(line, word, 0);
    } SWITCH_DATA_RES(isNumDataScenario(*word, line, *lab, dataLst, labLst))
    SWITCH_DATA_RES(isStrScenario(*word, line, *lab, dataLst, labLst))
    SWITCH_REF_RES(isEntryOrder(*word), entryScenario(line, word, lab, instLst), "")
    SWITCH_REF_RES(isExternOrder(*word), extScenario(line, word, lab, labLst), "")
    return FALSE;
}

result lookForOperation(char **firstOp, char **secOp, char **word, char **line, label **lab, labelLst *labLst, sWordLst
*instLst){
    int opIndex = getOpIndexByStr(*word);
    if (opIndex == NOT_OP) return ERR;
    int opsAmount = getOperandsAmount(opIndex);
    VALIDATE_VAL(validateOperation(opIndex, opsAmount, line, firstOp, secOp, labLst, lab, instLst), "")
    return SUCCESS;
}

result lookForLabel(char **line, char **word, label **lab){
    unsigned long len;
    getWord(line, word, 0);
    len = strlen(*word);
    if (checkLabelLegality(word, lab, len) != TRUE) return ERR;
    return finishLine(line);
}
