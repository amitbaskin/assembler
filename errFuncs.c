#include <stdio.h>
#include "generalUtils.h"
#include "wordId.h"
extern int lineCounter;
extern char *inputFileName;
extern char *curLine;
extern int errFlag;

#define PRE_PARSE_ERR_FORMAT "\nERROR (pre parse): %s\nfile: %s\n"
#define preParseErrMsg(msg){ \
    printf(PRE_PARSE_ERR_FORMAT, msg, inputFileName); \
}

#define FIRST_PARSE_ERR_FORMAT "\nERROR (first parse): %s\nfile: %s, line number: %d, line content: %s\n"
#define firstParseErrMsg(msg){ \
    errFlag = 1;               \
    printf(FIRST_PARSE_ERR_FORMAT, msg, inputFileName, lineCounter, curLine); \
}

#define SEC_PARSE_ERR_FORMAT "\nERROR (second parse): %s\nfile: %s, label name: %s\n"
#define secParseErrMsg(msg, labName){ \
    printf(SEC_PARSE_ERR_FORMAT, msg, inputFileName, labName); \
}

void allocErr(){
    firstParseErrMsg("memory allocation failure")
}

void openFileErr(){
    preParseErrMsg("failed to open file")
}

void lineTooLongErr(){
    char msg[50];
    sprintf(msg, "line exceeds limit of characters: %d", MAX_LINE_LEN);
    firstParseErrMsg(msg)
}

void labTooLongErr(){
    char msg[50];
    sprintf(msg, "label name exceeds limit of characters: %d", MAX_LAB_LEN);
    firstParseErrMsg(msg)
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

void lineEndErr(){
    firstParseErrMsg("line ended before expected")
}

void lineNotEndErr(){
    firstParseErrMsg("line did not end when expected")
}

void sepErr(){
    char msg[80];
    sprintf(msg, "there should be no '%c' after operator but there should be one between operands", SEPARATOR);
    firstParseErrMsg(msg)
}

void operandErr(){
    firstParseErrMsg("operator got wrong operand type")
}

void nonStrDataErr(){
    firstParseErrMsg("expected to get a string enclosed with quotation marks")
}

void nonNumericDataErr(){
    char msg[80];
    sprintf(msg, "expected numeric data separated by '%c'", SEPARATOR);
    firstParseErrMsg(msg)
}

void imNumNoDataErr(){
    char msg[50];
    sprintf(msg, "expected numeric value after '%c'", NUM_PREFIX);
    firstParseErrMsg(msg)
}

void noNumPrefixErr(){
    char msg[100];
    sprintf(msg, "an operand must not start with a digit\nin case of a numeric operand, it must have the '%c' "
                 "prefix", NUM_PREFIX);
    firstParseErrMsg(msg)
}

void emptyLabelErr(){
    firstParseErrMsg("got an empty label")
}

void illegalChrErr(){
    firstParseErrMsg("label contains illegal character\nmust begin with a letter and the rest must be alphanumeric")
}

void noSepAfterFirstOperand(){
    char msg[50];
    sprintf(msg, "expected a '%c' after the first operand", SEPARATOR);
    firstParseErrMsg(msg)
}

void illegalLabTypeErr(char *labName){
    secParseErrMsg("label appears to be both exten and entry", labName)
}

void useOfUndefinedLabErr(char *labName){
    secParseErrMsg("use of undefined label", labName)
}
