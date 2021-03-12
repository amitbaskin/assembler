#include "stdio.h"
#include "errFuncs.h"
#include "generalUtils.h"

#define FIRST_PARSE_ERR_FORMAT "\nERROR (first parse): %s\nfile: \"%s\", line number: %d, line content: \"%s\"\n"
#define firstParseErrMsg(msg){ \
    printf(FIRST_PARSE_ERR_FORMAT, msg, inputFileName, lineCounter, curLine); \
}

#define SEC_PARSE_ERR_FORMAT "\nERROR (second parse): %s\nfile: \"%s\", label name: \"%s\"\n"
#define secParseErrMsg(msg, labName){ \
    printf(SEC_PARSE_ERR_FORMAT, msg, inputFileName, labName); \
}

extern int lineCounter;
extern char *inputFileName;
extern char *curLine;

void allocErr(){
    firstParseErrMsg("memory allocation failure")
}

void openFileErr(){
    firstParseErrMsg("failed to open file")
}

void lineTooLongErr(){
    char msg[50];
    sprintf(msg, "line exceeded limit of characters: %d", MAX_LINE_LEN);
    firstParseErrMsg(msg)
}

void labTooLongErr(){
    char msg[50];
    sprintf(msg, "label name exceeded limit of characters: %d", MAX_LAB_LEN);
    firstParseErrMsg(msg)
}

void illegalChrErr(){
    firstParseErrMsg("label contains illegal character\nmust begin with a letter and the rest must be alphanumeric")
}

void labClashErr(){
    firstParseErrMsg("label declaration clashes with a pre defined one")
}

void keyWordErr(const char *keyWord){
    char msg[50];
    sprintf(msg, "label declaration clashes with keyword: %s", keyWord);
    firstParseErrMsg(msg)
}

void relLabErr(){
    firstParseErrMsg("relative label specified doesn't exist")
}

void undefinedStatementErr(){
    firstParseErrMsg("undefined statement")
}

void lineNotEndErr(){
    firstParseErrMsg("line continued beyond expected")
}

void lineEndErr(){
    firstParseErrMsg("line ended before expected")
}

void sepErr(){
    firstParseErrMsg("expected comma between values")
}

void operandErr(){
    firstParseErrMsg("operator got an unexpected operand")
}

void nonStrDataErr(){
    firstParseErrMsg("expected to get a string enclosed with quotation marks")
}

void nonNumericDataErr(){
    firstParseErrMsg("expected numeric data")
}

void emptyLabelErr(){
    firstParseErrMsg("got an empty label")
}

void illegalLabTypeErr(char *labName){
    secParseErrMsg("illegal label type", labName)
}

void useOfUndefinedLabErr(char *labName){
    secParseErrMsg("use of undefined label", labName)
}
