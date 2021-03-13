#include "parseLineUtils.h"
#include "labSetters.h"
#include "sWordListUtils.h"
#include "labLstUtils.h"
#include "rawWordUtils.h"
#include "rawWordLstUtils.h"
#include "errFuncs.h"

extern int dataCounter;
extern int labelFlag;

result breakDownData(char **line, rawWordLst *lst){
    result res;
    char *str;
    rawWord *word;
    int isContinue;
    int counter;
    unsigned char isSep = 1;
    for (counter=0, isContinue=1; isContinue; counter++, setRawWordStr(word, str), addRawWord(lst, word)){
        VALIDATE_VAL(getWordAlloc(&str))
        res = getWord(line, &str, 1);
        if (res == LINE_END) {
            isContinue = 0;
            if (*str == '\0') break;
        } if (!isSep) {
            sepErr();
            return ERR;
        } if (res != SEP) isSep = 0;
        VALIDATE_VAL(initRawWord(&word))
    } if (counter == 0){
        nonNumericDataErr();
        return ERR;
    } return res;
}

result collectData(rawWordLst *lst){
    long num;
    rawWord *ptr;
    for (ptr = getRawWordTail(lst); ptr != NULL; promoteRawWord(&ptr)){
        if (isNum(&num, getRawWordStr(ptr)) == ERR) {
            nonNumericDataErr();
            return ERR;
        } freeHelper(getRawWordStr(ptr));
        setRawWordNum(ptr, (int) num);
    } return SUCCESS;
}

result addSWordData(sWordLst *dataLst, labelLst *labLst, label *lab, rawWordLst *rawLst){
    rawWord *ptr;
    if (labelFlag) {
        setLabData(lab, 1);
        addLabToLabLst(labLst, &lab, L_NONE, dataCounter);
    } for (ptr = getRawWordTail(rawLst); ptr != NULL; promoteRawWord(&ptr)){
        addNumWord(getRawWordNum(ptr), dataCounter++, NUM_DATA, dataLst);
    } freeRawWordLst(rawLst);
    return SUCCESS;
}

result isNumDataScenario(char *word, char **line, label *lab, sWordLst *dataLst, labelLst *labLst) {
    rawWordLst *rawLst;
    if (isData(word) == TRUE) {
        VALIDATE_VAL(initRawWordLst(&rawLst))
        VALIDATE_VAL(breakDownData(line, rawLst))
        VALIDATE_VAL(collectData(rawLst))
        addSWordData(dataLst, labLst, lab, rawLst);
        return TRUE;
    } return FALSE;
}
