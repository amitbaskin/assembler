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
    VALIDATE_FUNC_CALL(getLineAlloc(&line))
    VALIDATE_FUNC_CALL(getNewEmptyLabel(&lab))
    labHead = labLst;
    while ((res = getLine(&line, fp)) != FILE_END){
        if (lookForData(&word, &line, &lab, labHead, &labLst, &sWordLst, &dataLst) == ERR) return ERR;
        if (lookForOperation(&word, &line, &lab, labHead, &labLst, &sWordLst) == ERR) return ERR;
    } if (res == ERR) return res;
    ICF = instructionCounter;
    DCF = dataCounter;
    return SUCCESS;
}
