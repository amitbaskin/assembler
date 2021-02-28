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

result lookForData(char **word, char **line, label **lab, label *labHead, label **labLst, sWord **instLst, sWord
**dataLst){
    result res;
    res = getWord(line, word, 0);
    if (res == LINE_END) return LINE_END;
    unsigned long len = strlen(*word);
    if ((res = isLabel(word, lab, len)) == ERR) return ERR;
    if (res == LINE_END) return SUCCESS;
    if ((res = isDataScenario(*word, line, dataLst, labHead, *lab, labLst)) == ERR) return ERR;
    if (res == FALSE) res = isStrScenario(line, *word, dataLst, labHead, *lab, labLst);
    if (res == ERR) return res;
    if (res == FALSE) res = isEntryOrder(*word);
    if (res == TRUE) {
        res = lookForLabel(line, word, &len);
        if (res == ERR) return res;
        addLabToInstLst(instLst, *word, L_ENT, labHead, 0);
        setLabType(getSULab(*instLst), L_ENT);
    } else if (isExternOrder(*word) == TRUE) {
        res = lookForLabel(line, word, &len);
        if (res == ERR) return res;
        addLabToLabLst(labHead, lab, labLst, EXT, 0);
    } return res;
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
    res = validateOperation(*word, line, &firstOp, &secOp, &srcType, &destType);
    if (res == ERR) return ERR;
    init = getOpWord(opIndex, srcType, destType);
    addOpWord(init, sWordLst);
    if (labelFlag) {
        setCodeLab(*lab);
        addLabToLabLst(labHead, labLst, labLst, NONE, instructionCounter++);
    } return SUCCESS;
}

result lookForLabel(char **line, char **word, unsigned long *len){
    label *lab;
    result res;
    getWord(line, word, 0);
    *len = strlen(*word);
    if (isLabel(word, &lab, *len) != TRUE) return ERR;
    res = finishLine(line);
    if (res == ERR) return res;
    return SUCCESS;
}
