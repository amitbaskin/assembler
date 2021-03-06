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
    if (checkIfOrder == TRUE){                            \
        return orderScenario;                             \
    }                                                     \
}
result entryScenario(char **line, char **word, label **lab, labelLst *labLst, sWordLst *instLst){
    if (lookForLabel(line, word, lab) == ERR) return ERR;
    addLabToInstLst(instLst, labLst, *word, L_ENT, 0);
    setLabType(getSULab(getSWordHead(instLst)), L_ENT);
    return TRUE;
}
result extScenario(char **line, char **word, label **lab, labelLst *labLst){
    VALIDATE_FUNC_CALL(lookForLabel(line, word, lab), "");
    addLabToLabLst(labLst, lab, EXT, 0);
    return TRUE;
}

result lookForData(char **word, char **line, label **lab, labelLst *labLst, sWordLst *instLst, sWordLst *dataLst){
    getWord(line, word, 0);
    VALIDATE_FUNC_CALL(isLabelDeclaration(*word, lab, strlen(*word)), "")
    SWITCH_DATA_RES(isDataScenario(*word, line, *lab, dataLst, labLst))
    SWITCH_DATA_RES(isStrScenario(*word, line, *lab, dataLst, labLst))
    SWITCH_REF_RES(isEntryOrder(*word), entryScenario(line, word, lab, labLst, instLst), "")
    SWITCH_REF_RES(isExternOrder(*word), extScenario(line, word, lab, labLst), "")
    return ERR;
}

result lookForOperation(char **word, char **line, label **lab, labelLst *labLst, sWordLst *instLst){
    char *firstOp;
    char *secOp;
    opWord *op;
    ref srcType = 0;
    ref destType = 0;
    int opIndex = getOpIndexByStr(*word);
    if (opIndex == NOT_OP) return ERR;
    int opsAmount = getOperandsAmount(opIndex);
    VALIDATE_FUNC_CALL(validateOperation(*word, opsAmount, line, &firstOp, &secOp, &srcType, &destType), "")
    getOpWord(opIndex, srcType, destType, &op);
    addOpWord(op, instLst);
    checkLabFlagOnScenario(lab, labLst, setLabCode, instructionCounter++);
    addAllOperandsWord(opsAmount, firstOp, secOp, labLst, instLst);
    return SUCCESS;
}

result lookForLabel(char **line, char **word, label **lab){
    unsigned long len;
    getWord(line, word, 0);
    len = strlen(*word);
    if (checkLabelLegality(word, lab, len) != SUCCESS) return ERR;
    return finishLine(line);
}
