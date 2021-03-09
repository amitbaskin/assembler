#include <stdio.h>
#include "firstParse.h"
#include "parseLine.h"
#include "parseLineUtils.h"
#include "labUtils.h"
#include "sWordSetters.h"
#include "generalUtils.h"
#include "sWordGetters.h"

result isEmptyLine(const char *line){
    while(*line != '\0'){
        if (*line != ' ' && *line != '\t' && *line != '\n') return FALSE;
    } return TRUE;
}

result parseFile(FILE *fp, sWordLst *instLst, sWordLst *dataLst, labelLst *labLst){
    char *line;
    char *lineOrgPtr;
    result res = SUCCESS;
    char *word;
    label *lab;
    char *firstOp;
    char *secOp;
    initLab(&lab);
    VALIDATE_VAL(getWordAlloc(&line, MAX_LINE_LEN), "")
    lineOrgPtr = line;
    VALIDATE_VAL(getWordAlloc(&word, MAX_LINE_LEN), "")
    VALIDATE_VAL(initLab(&lab), "")
    while (res != FILE_END){
        labelFlag = 0;
        line = lineOrgPtr;
        res = getLine(&line, fp);
        VALIDATE_VAL(res, "")
        if (*line == COMMENT_CHR || isEmptyLine(line) == TRUE) continue;
        res = lookForData(&word, &line, &lab, labLst, instLst, dataLst);
        if (res == TRUE || res == ERR) continue;
        VALIDATE_VAL(getWordAlloc(&firstOp, MAX_LINE_LEN), "")
        VALIDATE_VAL(getWordAlloc(&secOp, MAX_LINE_LEN), "")
        res = lookForOperation(&firstOp, &secOp, &word, &line, &lab, labLst, instLst);
        freeHelper(firstOp);
        freeHelper(secOp);
    } freeHelper(lineOrgPtr);
    freeHelper(word);
    ICF = instructionCounter;
    DCF = dataCounter;
    return res;
}
