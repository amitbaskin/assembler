#include <stdio.h>
#include <string.h>
#include "firstParseLine.h"
#include "generalUtils.h"
#include "firstParseLineUtils.h"
#include "labelApi.h"
#include "manageMachineWord.h"
#include "parseLabel.h"
#include "numsData.h"
#include "strData.h"
#include "operationsApi.h"
#include "parseOp.h"

result lookForData(char **word, char **line, label **lab, label *labHead, label **labLst, sWord **sWordLst){
    result res;
    res = getWord(line, word, 0);
    if (res == LINE_END) return LINE_END;
    unsigned long len = strlen(*word);
    if ((res = isLabelScenario(line, word, lab, len)) == ERR) return ERR;
    if (res == LINE_END) return SUCCESS;
    if ((res = isDataScenario(*word, line, sWordLst, labHead, *lab, labLst)) == ERR) return ERR;
    if (res == FALSE) res = isStrScenario(line, *word, sWordLst, labHead, *lab, labLst);
    if (res == ERR) return res;
    if (res == FALSE) res = isEntryOrder(*word);
    if (res == TRUE) {
        res = lookForLabel(line, word, &len);
        if (res == ERR) return res;
        addLabWord(sWordLst, len, *word, labHead, 0);
        setEntLabel((*sWordLst)->uWord->lab);
    } else if (isExternOrder(*word) == TRUE) {
        res = lookForLabel(line, word, &len);
        if (res == ERR) return res;
        addLabelScenario(labHead, lab, labLst, setExtLabel, 0);
    } return res;
}

result lookForOperation(char **word, char **line, label **lab, label *labHead, label **labLst, sWord **sWordLst){
    result res;
    char *firstOp;
    char *secOp;
    initial *init;
    ref srcType = 0;
    ref destType = 0;
    int opIndex = getOpIndex(*word);
    if (opIndex == NOT_OP) return ERR;
    res = validateOperation(*word, line, &firstOp, &secOp, &srcType, &destType);
    if (res == ERR) return ERR;
    init = getInitWord(opIndex, srcType, destType);
    addInitWord(init, sWordLst);
    if (labelFlag) {
        setCodeLabel(*lab);
        addLabelScenario(labHead, labLst, labLst, setExtLabel, instructionCounter++);
    } return SUCCESS;
}

result lookForLabel(char **line, char **word, unsigned long *len){
    label *lab;
    result res;
    getWord(line, word, 0);
    *len = strlen(*word);
    if (isLabelScenario(line, word, &lab, *len) != TRUE) return ERR;
    res = finishLine(line);
    if (res == ERR) return res;
    return SUCCESS;
}
