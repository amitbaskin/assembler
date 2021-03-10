#include "stdio.h"
#include "errFuncs.h"
#include "generalUtils.h"

#define ERR_PREFIX "ERROR with file %s: "

extern int lineCounter;
extern char *inputFileName;

void allocErr(){
    printf(ERR_PREFIX "memory allocation failure in line: %d\n", inputFileName, lineCounter);
}

void openFileErr(){
    printf(ERR_PREFIX "failed to open the file\n", inputFileName);
}

void lineTooLongErr(){
    printf(ERR_PREFIX "line %d exceeded limit: %d\n", inputFileName, lineCounter, MAX_LINE_LEN);
}

void illegalChrErr(){
    printf(ERR_PREFIX "label in line: %d contains illegal character. Must begin with a letter and all the rest must "
                      "be alphanumeric.\n", inputFileName, lineCounter);
}

void illegalLabTypeErr(){
    printf(ERR_PREFIX "illegal label type in line: %d\n", inputFileName, lineCounter);
}

void labClashErr(){
    printf(ERR_PREFIX "label specified in line: %d clashes with a pre defined label\n", inputFileName, lineCounter);
}

void keyWordErr(const char *keyWord){
    printf(ERR_PREFIX "label specified in line: %d clashes with keyword: %s\n", inputFileName, lineCounter, keyWord);
}

void relLabErr(){
    printf(ERR_PREFIX "relative label in line: %d doesn't exist\n", inputFileName, lineCounter);
}

void undefinedStatementErr(){
    printf(ERR_PREFIX "undefined statement in line: %d\n", inputFileName, lineCounter);
}

void lineNotEndErr(){
    printf(ERR_PREFIX "expected line: %d to end but it continued\n ", inputFileName, lineCounter);
}

void lineEndErr(){
    printf(ERR_PREFIX "expected line: %d to continue but it ended\n ", inputFileName, lineCounter);
}

void sepErr(){
    printf(ERR_PREFIX "expected comme in line: %d but didn't find it where it should have been\n ", inputFileName,
           lineCounter);
}

void operandErr(){
    printf(ERR_PREFIX "in line: %d an operator got an unexpected operand\n ", inputFileName, lineCounter);
}

void notStrErr(){
    printf(ERR_PREFIX "in line: %d expected to get a string but didn't\n ", inputFileName, lineCounter);
}

void notNumErr(){
    printf(ERR_PREFIX "in line: %d expected to get an int but didn't\n ", inputFileName, lineCounter);
}