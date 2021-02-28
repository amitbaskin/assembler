#include <stdio.h>
#include "firstParse.h"
#include "parseLine.h"
#include "labelUtils.h"
#include "sWordSetters.h"
#include "generalUtils.h"
#include "sWordGetters.h"

result parseFile(FILE *fp){
    void *ptr;
    char *line;
    result res;
    char *word;
    label *lab;
    label *labHead;
    label *labLst;
    sWord *sWordLst;
    sWord *dataLst;
    getAlloc(MAX_LINE_LEN, &ptr);
    line = (char *) ptr;
    getAlloc(MAX_LINE_LEN, &ptr);
    word = (char *) ptr;
    lab = getNewEmptyLabel();
    labHead = getNewEmptyLabel();
    labLst = labHead;
    sWordLst = getNewEmptySword();
    while (getLine(&line, fp) != FILE_END){
        res = lookForData(&word, &line, &lab, labHead, &labLst, &sWordLst, &dataLst);
        if (res == ERR) return ERR;
        res = lookForOperation(&word, &line, &lab, labHead, &labLst, &sWordLst);
        if (res == ERR) return ERR;
    } ICF = instructionCounter;
    DCF = dataCounter;
    return SUCCESS;
}