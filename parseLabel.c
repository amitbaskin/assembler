#include "parseLabel.h"
#include "generalUtils.h"
#include "machineWordIdentifiers.h"
#include "labelApi.h"
#include "manageMachineWord.h"

result isLabelScenario(char **line, char **word, label **lab, unsigned long len){
    void *ptr;
    if (isLabelDeclaration(*word, len) == TRUE){
        if (isLegalLabel(*word, len) != TRUE) return ERR;
        labelFlag = 1;
        getAlloc(sizeof(label), &ptr);
        lab = ptr;
        getAlloc(len + 1, ptr);
        (*lab)->name = ptr;
        strlcpy((*lab)->name, *word, len);
        (*lab)->name[len] = '\0';
        return getWord(line, word, 0);
    } return FALSE;
}

result dataLabelScenario(label *head, label *lab, label **labLst){
    if (!isLabelInLst(head, lab->name)){
        (*labLst)->next = lab;
        setDataLabel(lab);
        lab->address = dataCounter;
        return SUCCESS;
    } else return ERR;
}
