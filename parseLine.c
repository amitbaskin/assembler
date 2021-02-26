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

result lookForData(char **word, char **line, label *labHead, label **labLst, sWord **words){
    label *lab;
    result res;
    res = getWord(line, word, 0);
    if (res == LINE_END) return LINE_END;
    unsigned long len = strlen(*word);
    if ((res = isLabelScenario(line, word, &lab, len)) == ERR) return ERR;
    if (res == LINE_END) return SUCCESS;
    if ((res = isDataScenario(*word, line, words, labHead, lab, labLst)) == ERR) return ERR;
    if (res == FALSE) res = isStrScenario(line, *word, words, labHead, lab, labLst);
    if (res == ERR) return ERR;
    if (res == FALSE) res = isEntryOrder(*word);
    if (res == TRUE) return SUCCESS;
    else if (isExternOrder(*word) == TRUE) {
        setLabelScenario(labHead, lab, labLst, setExtLabel);
        res = getWord(line, word, 0);
    } return res;
}

result lookForOperation(char **word, char **line, label **labLst, sWord **words){
    int isOperation = isOp(*word);
    if (isOperation == NOT_OP) return ERR;
    return SUCCESS;
}





