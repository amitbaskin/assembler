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
    VALIDATE_FUNC_CALL(getAlloc(MAX_LINE_LEN, &ptr), "")
    *output = ptr;
    return SUCCESS;
}

result parseFile(FILE *fp, sWord *sWordLst, sWord *dataLst, label *labLst){
    char *line;
    result res;
    char *word;
    label *lab;
    label *labHead;
    labHead = labLst;
    VALIDATE_FUNC_CALL(getLineAlloc(&line), "")
    VALIDATE_FUNC_CALL(getNewEmptyLabel(&lab), "")
    while ((res = getLine(&line, fp)) != FILE_END){
        if (*line == COMMENT_CHR) continue;
        VALIDATE_FUNC_CALL(lookForData(&word, &line, &lab, labHead, &labLst, &sWordLst, &dataLst), "")
        VALIDATE_FUNC_CALL(lookForOperation(&word, &line, &lab, labHead, &labLst, &sWordLst), "")
    } if (res == ERR) return res;
    ICF = instructionCounter;
    DCF = dataCounter;
    return SUCCESS;
}
