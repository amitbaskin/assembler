#include "parseLabel.h"
#include "generalUtils.h"
#include "machineWordIdentifiers.h"
#include "labelApi.h"
#include "manageMachineWord.h"

result isLabelScenario(char **line, char **word, label **lab, unsigned long len){
    void *ptr;
    if (isLabelDeclaration(*word, len) == TRUE){
        if (isLegalLabel(*word, len) != TRUE) return ERR;
        labelFlag = TRUE;
        getAlloc(sizeof(label), &ptr);
        lab = ptr;
        getAlloc(len + 1, ptr);
        (*lab)->name = ptr;
        strlcpy((*lab)->name, *word, len);
        (*lab)->name[len] = '\0';
        return getWord(line, word, 0);
    } return FALSE;
}

result setLabelScenario(label *head, label *lab, label **labLst, void setter(label *)){
    if (!isLabelInLst(head, lab->name)){
        (*labLst)->next = lab;
        setter(lab);
        lab->address = dataCounter;
        return SUCCESS;
    } else return ERR;
}
