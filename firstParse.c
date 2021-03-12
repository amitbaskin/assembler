#include <stdio.h>
#include "string.h"
#include "firstParse.h"
#include "parseLine.h"
#include "parseLineUtils.h"
#include "labUtils.h"
#include "sWordSetters.h"
#include "generalUtils.h"
#include "sWordGetters.h"
#include "errFuncs.h"

extern int labelFlag;
extern int errFlag;
extern int ICF;
extern int instructionCounter;
extern int lineCounter;
extern int dataCounter;
extern char *curLine;

result isEmptyLine(const char *line){
    while(*line != '\0'){
        if (*line != ' ' && *line != '\t' && *line != '\n') return FALSE;
    } return TRUE;
}

result parseFile(FILE *fp, sWordLst *instLst, sWordLst *dataLst, labelLst *labLst){
    char *line;
    result res = SUCCESS;
    char *word;
    label *lab;
    char *firstOp;
    char *secOp;
    char *orgFirstOp;
    char *orgSecOp;
    result isFileEnd = FALSE;
    VALIDATE_VAL(initLab(&lab))
    VALIDATE_VAL(getWordAlloc(&line))
    curLine = line;
    VALIDATE_VAL(getWordAlloc(&word))
    VALIDATE_VAL(initLab(&lab))
    while (isFileEnd != FILE_END){
        lineCounter++;
        labelFlag = 0;
        line = curLine;
        VALIDATE_VAL(isFileEnd = getLine(&line, fp))
        if (*line == COMMENT_CHR || isEmptyLine(line) == TRUE) continue;
        if (getWord(&line, &word, 0) == LAB_DEC){
            VALIDATE_VAL(res = processLabel(&line, &word, &lab, strlen(word)))
        } res = lookForData(&word, &line, &lab, labLst, instLst, dataLst);
        if (res == ERR || res != FALSE) continue;
        VALIDATE_VAL(getWordAlloc(&firstOp))
        VALIDATE_VAL(getWordAlloc(&secOp))
        orgFirstOp = firstOp;
        orgSecOp = secOp;
        res = lookForOperation(&firstOp, &secOp, &word, &line, &lab, labLst, instLst);
        freeHelper(orgFirstOp);
        freeHelper(orgSecOp);
    } freeHelper(curLine);
    freeHelper(word);
    ICF = instructionCounter;
    lineCounter = 0;
    return res;
}
