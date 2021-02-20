#include <stdio.h>
#include <string.h>
#include "parseLine.h"
#include "generalUtils.h"
#include "parseLineUtils.h"
#include "labelUtils.h"
#include "manageMachineWord.h"

result parseLine(rawWord *raw, label **labLst){
    label *lab;
    void *ptr;
    unsigned long len = strlen(raw->word);
    label *head = *labLst;
    if (isLabelDeclaration(raw->word, len) == TRUE){
        if (isLegalLabel(raw->word, len) != TRUE) return ERR;
        labelFlag = 1;
        raw = raw->next;
        getAlloc(sizeof(label), &ptr);
        lab = ptr;
        raw->word[len-1] = '\0';
        lab->name = raw->word;
    } if (isData(raw->word) == TRUE){
        if (labelFlag){
            if (!isLabelInLst(head, lab->name)){
                (*labLst)->next = lab;
                setDataLabel(lab);
                lab->address = dataCounter;
            }
        }
    } else return ERR;
    return SUCCESS;
}

