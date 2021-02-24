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

result lookForData(char **line, label **labLst, sWord **words){
    label *lab;
    result res;
    char *word;
    res = getWord(line, &word, 0);
    if (res == LINE_END) return LINE_END;
    unsigned long len = strlen(word);
    label *head = *labLst;
    if ((res = isLabelScenario(line, &word, &lab, len)) == ERR) return ERR;
    if (res == LINE_END) return SUCCESS;
    if ((res = isDataScenario(word, line, words, head, lab, labLst)) == ERR) return ERR;
    if (res == FALSE) res = isStrScenario(line, word, words, head, lab, labLst);
    if (res == ERR) return ERR;
    if (res == FALSE) res = isEntryOrder(word);
    if (res == TRUE) return SUCCESS;
    else {
        res = isExternOrder(word);
        if (res == TRUE) setLabelScenario(head, lab, labLst, setExtLabel);
    } return res;
}





