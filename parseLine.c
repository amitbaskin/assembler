#include <stdio.h>
#include <string.h>
#include "parseLine.h"
#include "generalUtils.h"
#include "parseLineUtils.h"
#include "labelApi.h"
#include "manageMachineWord.h"
#include "parseLabel.h"
#include "numsData.h"
#include "strData.h"
#include "operationsApi.h"
#include "parseOp.h"

result lookForData(char **word, char **line, label **lab, label *labHead, label **labLst, sWord **words){
    result res;
    res = getWord(line, word, 0);
    if (res == LINE_END) return LINE_END;
    unsigned long len = strlen(*word);
    if ((res = isLabelScenario(line, word, lab, len)) == ERR) return ERR;
    if (res == LINE_END) return SUCCESS;
    if ((res = isDataScenario(*word, line, words, labHead, *lab, labLst)) == ERR) return ERR;
    if (res == FALSE) res = isStrScenario(line, *word, words, labHead, *lab, labLst);
    if (res == ERR) return ERR;
    if (res == FALSE) res = isEntryOrder(*word);
    if (res == TRUE) return SUCCESS;
    else if (isExternOrder(*word) == TRUE) {
        getWord(line, word, 0);
        if (isLabelScenario(line, word, lab, len) != TRUE) return ERR;
        res = finishLine(line);
        if (res == ERR) return res;
        addLabelScenario(labHead, lab, labLst, setExtLabel, instructionCounter++);
        res = getWord(line, word, 0);
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
