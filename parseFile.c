#include <stdio.h>
#include "parseFile.h"
#include "generalUtils.h"
#include "firstParseLine.h"
#include "labelApi.h"
#include "manageMachineWord.h"
#define MAX_LINE_LEN 81

result firstParse(FILE *fp){
    void *ptr;
    char *line;
    result res;
    char *word;
    label *lab;
    label *labHead;
    label *labLst;
    sWord *sWordLst;
    getAlloc(MAX_LINE_LEN, &ptr);
    line = (char *) ptr;
    getAlloc(MAX_LINE_LEN, &ptr);
    word = (char *) ptr;
    lab = getEmptyLabel();
    labHead = getEmptyLabel();
    labLst = labHead;
    sWordLst = getSword();
    while (getLine(&line, fp) != FILE_END){
        res = lookForData(&word, &line, &lab, labHead, &labLst, &sWordLst);
        if (res == ERR) return ERR;
        res = lookForOperation(&word, &line, &lab, labHead, &labLst, &sWordLst);
        if (res == ERR) return ERR;
    } ICF = instructionCounter;
    DCF = dataCounter;
    return SUCCESS;
}

