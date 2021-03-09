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

extern int dataCounter;
extern int labelFlag;

result isDataScenario(char *word, char **line, label *lab, sWordLst *dataLst, labelLst *labLst) {
    void *ptr;
    rawWordLst *lst;
    VALIDATE_VAL(initRawWordLst(&lst), "")
    VALIDATE_VAL(initRawWordLst(&lst), "");
    if (isData(word) == TRUE) {
        initRawWordLst(&lst);
        breakDownLine(line, lst, 1);
        VALIDATE_VAL(collectData(lst), "")
        checkLabFlagOnScenario(&lab, labLst, setLabCode, dataCounter++);
        addSWordData(dataLst, labLst, lab, lst);
        return TRUE;
    } return FALSE;
}

result collectData(rawWordLst *lst){
    long num;
    rawWord *ptr;
    for (ptr = getRawWordTail(lst); ptr != NULL; promoteRawWord(&ptr)){
        VALIDATE_VAL(isNumData(&num, getRawWordStr(ptr)), "")
        setRawWordNum(ptr, (int) num);
    } return SUCCESS;
}

result addSWordData(sWordLst *dataLst, labelLst *labLst, label *lab, rawWordLst *rawLst){
    rawWord *ptr;
    if (labelFlag) {
        addLabToLabLst(labLst, &lab, L_NONE, dataCounter++);
        setLabData(lab, 1);
    } for (ptr = getRawWordTail(rawLst); ptr != NULL; promoteRawWord(&ptr)){
        addNumWord(getRawWordNum(ptr), NUM_DATA, dataLst);
    } freeRawWordLst(rawLst);
    return SUCCESS;
}
