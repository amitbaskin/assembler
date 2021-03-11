#include "stdio.h"
#include "errFuncs.h"
#include "generalUtils.h"

#define ERR_PREFIX "\nERROR: %s\nfile: \"%s\", line number: %d, line content: \"%s\"\n"
#define errMsg(msg){ \
    printf(ERR_PREFIX, msg, inputFileName, lineCounter, curLine); \
}

extern int lineCounter;
extern char *inputFileName;
extern char *curLine;

void allocErr(){
    errMsg("memory allocation failure")
}

void openFileErr(){
    errMsg("failed to open file")
}

void lineTooLongErr(){
    char msg[MAX_LINE_LEN];
    sprintf(msg, "line exceeded limit of characters: %d", MAX_LINE_LEN);
    errMsg(msg)
}

void labTooLongErr(){
    char msg[MAX_LINE_LEN];
    sprintf(msg, "label name exceeded limit of characters: %d", MAX_LAB_LEN);
    errMsg(msg)
}

void illegalChrErr(){
    errMsg("label contains illegal character\nmust begin with a letter and the rest must be alphanumeric")
}

void illegalLabTypeErr(){
    errMsg("illegal label type")
}

void labClashErr(){
    errMsg("label declaration clashes with a pre defined one")
}

void keyWordErr(const char *keyWord){
    char msg[MAX_LINE_LEN];
    sprintf(msg, "label declaration clashes with keyword: %s", keyWord);
    errMsg(msg)
}

void relLabErr(){
    errMsg("relative label specified doesn't exist")
}

void undefinedStatementErr(){
    errMsg("undefined statement")
}

void lineNotEndErr(){
    errMsg("line continued beyond expected")
}

void lineEndErr(){
    errMsg("line ended before expected")
}

void sepErr(){
    errMsg("expected comma between values")
}

void operandErr(){
    errMsg("operator got an unexpected operand")
}

void nonStrDataErr(){
    errMsg("expected to get a string enclosed with quotation marks")
}

void nonNumericDataErr(){
    errMsg("expected numeric data")
}

void emptyLabelErr(){
    errMsg("got an empty label")
}
