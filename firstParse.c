/* this file is used to run the general flow of the first parse of an assembly file */
#include <string.h>
#include "parseLine.h"
#include "parseLineUtils.h"
#include "labUtils.h"
#include "globalVars.h"


result parseFile(FILE *fp, sWordLst *instLst, sWordLst *dataLst, labelLst *labLst){
    /* first parse of an input assembly file returns ERR if error occurred in the process and SUCCESS otherwise */
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
    VALIDATE_VAL(getFixedStrAlloc(&line))
    setCurLine(line);
    VALIDATE_VAL(getFixedStrAlloc(&word))
    VALIDATE_VAL(initLab(&lab))
    while (isFileEnd != FILE_END){
        updateLineCounter();
        resetLabelFlag();
        line = getCurLine(); /* save the pointer for the beginning of the line in order to override it with the next line
        * later on */
        isFileEnd = getLine(&line, fp); /* err handled inside, keep finding errs */
        if (isFileEnd == ERR) continue;
        if (*line == COMMENT_CHR || isEmptyLine(line) == TRUE) continue;
        /* err handled inside, keep finding errs */
        if (getWord(&line, &word, 0) == LAB_DEC){
            if (processLabel(&line, &word, &lab, strlen(word)) == ERR) continue;
            /* err handled inside, keep finding errs */
        }
        res = lookForData(&word, &line, &lab, labLst, instLst, dataLst);
        if (res == ERR || res != FALSE) continue;
        if (getFixedStrAlloc(&firstOp) == ERR) continue; /* err handled inside, keep finding errs */
        if (getFixedStrAlloc(&secOp) == ERR) continue; /* err handled inside, keep finding errs */
        /* saves the pointers to the allocated operands in order to free them later as they might be modified while
         * processing the operator statement */
        orgFirstOp = firstOp;
        orgSecOp = secOp;
        res = lookForOperation(&firstOp, &secOp, &word, &line, &lab, labLst, instLst);
        freeHelper(orgFirstOp);
        freeHelper(orgSecOp);
    }
    freeHelper(getCurLine());
    freeHelper(word);
    setIcf(getInstructionCounter()); /* final instruction counter */
    return res;
}
