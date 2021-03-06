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
    getNewEmptyLab(&lab);
    VALIDATE_FUNC_CALL(getWordAlloc(&line, MAX_LINE_LEN), "")
    lineOrgPtr = line;
    VALIDATE_FUNC_CALL(getWordAlloc(&word, MAX_LINE_LEN), "")
    VALIDATE_FUNC_CALL(getNewEmptyLab(&lab), "")
    while (res != FILE_END){
        res = getLine(&line, fp);
        VALIDATE_FUNC_CALL(res, "")
        if (*line == COMMENT_CHR || isEmptyLine(line) == TRUE) continue;
        res = lookForData(&word, &line, &lab, labLst, instLst, dataLst);
        if (res == TRUE || res == ERR) break;
        res = lookForOperation(&word, &line, &lab, labLst, instLst);
    } freeHelper(lineOrgPtr);
    freeHelper(word);
    ICF = instructionCounter;
    DCF = dataCounter;
    return res;
}
