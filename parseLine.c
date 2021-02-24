#include <stdio.h>
#include <string.h>
#include "parseLine.h"
#include "generalUtils.h"
#include "parseLineUtils.h"
#include "labelApi.h"
#include "manageMachineWord.h"

result parseLine(char **line, label **labLst, sWord **words){
    label *lab;
    result res;
    char *word;
    res = getWord(line, &word, 0);
    if (res == LINE_END) return LINE_END;
    unsigned long len = strlen(word);
    label *head = *labLst;
    if (isLabelScenario(line, &word, &lab, len) == ERR) return ERR;
    if ((res = isDataScenario(word, line, words)) == ERR) return ERR;
    if (res == FALSE) res = isStrScenario(line, word, words);
    if (res == TRUE && labelFlag) res = dataLabelScenario(head, lab, labLst);
    if (res == ERR) return ERR;
    return SUCCESS;
}

