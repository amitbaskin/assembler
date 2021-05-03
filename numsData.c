/* this file is used to handle the integer data statements */

#include "parseLineUtils.h"
#include "labSetters.h"
#include "sWordListUtils.h"
#include "labLstUtils.h"
#include "rawWordUtils.h"
#include "rawWordLstUtils.h"
#include "errFuncs.h"
#include "globalVars.h"


result breakDownData(char **line, rawWordLst *lst){
    /* breaks down a line to consecutive words and makes sure the are separators between them */
    result res;
    char *str;
    rawWord *word;
    int isContinue;
    int counter;
    unsigned char isSep = 1;
    for (counter=0, isContinue=1; isContinue; counter++, setRawWordStr(word, str), addRawWord(lst, word)){
        VALIDATE_VAL(getFixedStrAlloc(&str))
        res = getWord(line, &str, 1);
        if (res == LINE_END) {
            isContinue = 0;
            if (*str == '\0') break;
        }
        if (!isSep) {
            sepErr();
            return ERR;
        }
        if (res != SEP) isSep = 0;
        VALIDATE_VAL(initRawWord(&word))
    }
    if (counter == 0){
        nonNumericDataErr();
        return ERR;
    }
    return res;
}

result collectData(rawWordLst *lst){
    /* collects the numeric data from the broken line
     * returns ERR if encountered a word which is not an integer else returns SUCCESS */
    long num;
    rawWord *ptr;
    for (ptr = getRawWordTail(lst); ptr != NULL; promoteRawWord(&ptr)){
        if (isNum(&num, getRawWordStr(ptr)) == ERR) {
            nonNumericDataErr();
            return ERR;
        }
        freeHelper(getRawWordStr(ptr));
        setRawWordNum(ptr, (int) num);
    }
    return SUCCESS;
}

result addSWordData(sWordLst *dataLst, labelLst *labLst, label *lab, rawWordLst *rawLst){
    /* adds the collected data to the data list and if a label was declared so adds it to the label list with the
     * address of this data line */
    rawWord *ptr;
    if (getLabelFlag()) {
        setLabData(lab, 1);
        addLabToLabLst(labLst, &lab, L_NONE, getDataCounter());
    }
    for (ptr = getRawWordTail(rawLst); ptr != NULL; promoteRawWord(&ptr)){
        addNumWord(getRawWordNum(ptr), getDataCounter(), NUM_DATA, dataLst);
        updateDataCounter();
    }
    freeRawWordLst(rawLst);
    return SUCCESS;
}

result isNumDataScenario(char *word, char **line, label *lab, sWordLst *dataLst, labelLst *labLst) {
    /* checks if the given word is a data statement and if so operates accordingly in order to collect the data
     * returns ERR if and error has occurred in the process and TRUE otherwise */
    rawWordLst *rawLst;
    if (isDataOrder(word) == TRUE) {
        VALIDATE_VAL(initRawWordLst(&rawLst))
        VALIDATE_VAL(breakDownData(line, rawLst))
        VALIDATE_VAL(collectData(rawLst))
        addSWordData(dataLst, labLst, lab, rawLst);
        return TRUE;
    }
    return FALSE;
}
