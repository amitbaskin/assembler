#include <string.h>
#include "parseLine.h"
#include "parseLineUtils.h"
#include "labUtils.h"

extern int labelFlag;
extern int errFlag;
extern int ICF;
extern int instructionCounter;
extern int lineCounter;
extern int dataCounter;
extern char *curLine;

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
        isFileEnd = getLine(&line, fp); /* err handled inside, keep finding errs */
        if (isFileEnd == ERR) continue;
        if (*line == COMMENT_CHR || isEmptyLine(line) == TRUE) continue;
        /* err handled inside, keep finding errs */
        if (getWord(&line, &word, 0) == LAB_DEC){
            if (processLabel(&line, &word, &lab, strlen(word)) == ERR) continue;
            /* err handled inside, keep finding errs */
        } res = lookForData(&word, &line, &lab, labLst, instLst, dataLst);
        if (res == ERR || res != FALSE) continue;
        if (getWordAlloc(&firstOp) == ERR) continue; /* err handled inside, keep finding errs */
        if (getWordAlloc(&secOp) == ERR) continue; /* err handled inside, keep finding errs */
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
