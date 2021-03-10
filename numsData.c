#include <string.h>
#include "numsData.h"
#include "parseLineUtils.h"
#include "generalUtils.h"
#include "sWordSetters.h"
#include "labUtils.h"
#include "labSetters.h"
#include "sWordListUtils.h"
#include "labLstUtils.h"
#include "parseLine.h"
#include "rawWordUtils.h"
#include "rawWordLstUtils.h"
#include "errFuncs.h"

extern int dataCounter;
extern int labelFlag;

result isNumDataScenario(char *word, char **line, label *lab, sWordLst *dataLst, labelLst *labLst) {
    rawWordLst *rawLst;
    VALIDATE_VAL(initRawWordLst(&rawLst))
    if (isData(word) == TRUE) {
        initRawWordLst(&rawLst);
        VALIDATE_VAL(breakDownData(line, rawLst, 1))
        VALIDATE_VAL(collectData(rawLst))
        addSWordData(dataLst, labLst, lab, rawLst);
        return TRUE;
    } return FALSE;
}

result collectData(rawWordLst *lst){
    long num;
    rawWord *ptr;
    for (ptr = getRawWordTail(lst); ptr != NULL; promoteRawWord(&ptr)){
        VALIDATE_VAL(isNum(&num, getRawWordStr(ptr)))
        freeHelper(getRawWordStr(ptr));
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
//
//labSetter(*lab, 1);
//        addLabToLabLst(labLst, lab, L_NONE, address);
