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
            return ERR;           \
                              \
        case TRUE:            \
            return SUCCESS;   \
                              \
        default:          \
            break;\
    }\
}

#define SWITCH_REF_RES(checkIfOrder, orderScenario) {\
    if (checkIfOrder == TRUE){                     \
        VALIDATE_FUNC_CALL(orderScenario)             \
        return SUCCESS;\
    }\
}


result entryScenario(char **line, char **word, sWord **instLst, label *labHead){
    if (lookForLabel(line, word) == ERR) return ERR;
    addLabToInstLst(instLst, *word, L_ENT, labHead, 0);
    setLabType(getSULab(*instLst), L_ENT);
    return SUCCESS;
}

result extScenario(char **line, char **word, label *labHead, label **lab, label **labLst){
    if (lookForLabel(line, word) == ERR) return ERR;
    addLabToLabLst(labHead, lab, labLst, EXT, 0);
    return SUCCESS;
}

result lookForData(char **word, char **line, label **lab, label *labHead, label **labLst, sWord **instLst,
                   sWord **dataLst){
    getWord(line, word, 0);
    VALIDATE_FUNC_CALL(isLabel(word, lab, strlen(*word)))
    SWITCH_DATA_RES(isDataScenario(*word, line, dataLst, labHead, *lab, labLst))
    SWITCH_DATA_RES(isStrScenario(line, *word, dataLst, labHead, *lab, labLst))
    SWITCH_REF_RES(isEntryOrder(*word), entryScenario(line, word, instLst, labHead))
    SWITCH_REF_RES(isExternOrder(*word), extScenario(line, word, labHead, lab, labLst))
    return ERR;
}

result lookForOperation(char **word, char **line, label **lab, label *labHead, label **labLst, sWord **sWordLst){
    result res;
    char *firstOp;
    char *secOp;
    opWord *init;
    ref srcType = 0;
    ref destType = 0;
    int opIndex = getOpIndexByStr(*word);
    if (opIndex == NOT_OP) return ERR;
    int opsAmount = getOperandsAmount(opIndex);
    res = validateOperation(*word, opsAmount, line, &firstOp, &secOp, &srcType, &destType);
    if (res == ERR) return ERR;
    init = getOpWord(opIndex, srcType, destType);
    addOpWord(init, sWordLst);
    if (labelFlag) {
        setCodeLab(*lab);
        addLabToLabLst(labHead, labLst, labLst, NONE, instructionCounter++);
    } addAllOperandsWord(opsAmount, firstOp, secOp, labHead, sWordLst);
    return SUCCESS;
}

result lookForLabel(char **line, char **word){
    unsigned long len;
    label *lab;
    result res;
    getWord(line, word, 0);
    len = strlen(*word);
    if (isLabel(word, &lab, len) != TRUE) return ERR;
    res = finishLine(line);
    if (res == ERR) return res;
    return SUCCESS;
}
