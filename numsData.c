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

result isDataScenario(char *word, char **line, label *lab, sWordLst *dataLst, labelLst *labLst) {
    void *ptr;
    data *dat;
    rawWord *raw;
    if (isData(word) == TRUE) {
        getAlloc(sizeof(rawWord), &ptr);
        raw = (rawWord *) ptr;
        breakDownLine(line, &raw, 1);
        getAlloc(sizeof(data), &ptr);
        dat = (data *) ptr;
        VALIDATE_FUNC_CALL(collectData(raw, dat), "")
        checkLabFlagOnScenario(&lab, labLst, setLabCode, dataCounter++);
        addData(dataLst, labLst, lab, dat);
        return TRUE;
    } return FALSE;
}

result collectData(rawWord *raw, data *dat){
    long num;
    data *next;
    void *ptr;
    while (dat->next != NULL){
        VALIDATE_FUNC_CALL(isNumData(&num, raw->word) == ERR, "")
        dat->num = (int) num;
        VALIDATE_FUNC_CALL(getAlloc(sizeof(data), &ptr), "");
        next = (data *) ptr;
        dat->next = next;
        dat = next;
        raw = raw->next;
        if (raw != NULL && !(strcmp(raw->word, SEP_STR))) return ERR;
        raw = raw->next;
    } return SUCCESS;
}

result addData(sWordLst *dataLst, labelLst *labLst, label *lab, data *dat){
    if (labelFlag) {
        addLabToLabLst(labLst, &lab, L_NONE, dataCounter++);
        setLabData(lab, 1);
    } while (dat != NULL){
        addNumWord(dat->num, NUM_DATA, dataLst);
    } freeDataLst(dat);
    return SUCCESS;
}

void freeDataLst(data *dat){
    data *tmp;
    while (dat->next != NULL){
        tmp = dat;
        dat = dat->next;
        freeHelper(tmp);
    } freeHelper(dat);
}