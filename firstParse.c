#include <stdio.h>
#include "firstParse.h"
#include "parseLine.h"
#include "parseLineUtils.h"
#include "labUtils.h"
#include "sWordSetters.h"
#include "generalUtils.h"
#include "sWordGetters.h"

result getLineAlloc(char **output){
    void *ptr;
    if (getAlloc(MAX_LINE_LEN, &ptr) == ERR) return ERR;
    *output = ptr;
    return SUCCESS;
}

result parseFile(FILE *fp, sWord *sWordLst, sWord *dataLst, label *labLst){
    char *line;
    result res;
    char *word;
    label *lab;
    label *labHead;
    if (getLineAlloc(&line) == ERR) return ERR;
    if (getLineAlloc(&word) == ERR) return ERR;
    if (getNewEmptyLabel(&lab) == ERR) return ERR;
    labHead = labLst;
    while ((res = getLine(&line, fp)) != FILE_END){
        res = lookForData(&word, &line, &lab, labHead, &labLst, &sWordLst, &dataLst);
        if (res == ERR) return ERR;
        res = lookForOperation(&word, &line, &lab, labHead, &labLst, &sWordLst);
        if (res == ERR) return ERR;
    } if (res == ERR) return res;
    ICF = instructionCounter;
    DCF = dataCounter;
    return SUCCESS;
}
