#include <string.h>
#include "numsData.h"
#include "parseLineUtils.h"
#include "generalUtils.h"
#include "sWordSetters.h"
#include "labUtils.h"
#include "labSetters.h"
#include "sWordListUtils.h"
#include "labLstUtils.h"

result isDataScenario(char *word, char **line, sWord **words, label *head, label *lab, label **labLst) {
    void *ptr;
    data *dat;
    rawWord *raw;
    if (isData(word) == TRUE) {
        getAlloc(sizeof(rawWord), &ptr);
        raw = (rawWord *) ptr;
        breakDownLine(line, &raw, 1);
        getAlloc(sizeof(data), &ptr);
        dat = (data *) ptr;
        if (collectData(raw, dat) == ERR) return ERR;
        addData(words, dat, head, lab, labLst);
        return TRUE;
    } return FALSE;
}

result collectData(rawWord *raw, data *dat){
    long num;
    data *next;
    void *ptr;
    result res;
    while (dat->next != NULL){
        if ((res = isNumData(&num, raw->word) == ERR)) return ERR;
        dat->num = (int) num;
        getAlloc(sizeof(data), &ptr);
        next = (data *) ptr;
        dat->next = next;
        dat = next;
        raw = raw->next;
        if (raw != NULL && !(strcmp(raw->word, SEP_STR))) return ERR;
        raw = raw->next;
    } return res;
}

result addData(sWord **sWordLst, data *dat, label *head, label *lab, label **labLst){
    if (labelFlag) {
        addLabToLabLst(head, &lab, labLst, NONE, dataCounter++);
        setDataLab(lab);
    } while (dat != NULL){
        addNumWord(dat->num, NUM_DATA, sWordLst);
    } return SUCCESS;
}
