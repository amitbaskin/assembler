#include "parseLabel.h"
#include "generalUtils.h"
#include "wordIdentifiers.h"
#include "labelUtils.h"
#include "sWordSetters.h"

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

result addLabToLabLst(label *head, label **lab, label **labLst, labelType type, int address){
    result res = isLabInLst(head, lab, type, (*lab)->name);
    if (res == FALSE){
        (*labLst)->next = *lab;
        setLabelType(*lab, type);
        (*lab)->address = address;
        return SUCCESS;
    } else return ERR;
}
