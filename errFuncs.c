/* this file is used to handle the errors in the program */

#include <stdio.h>
#include "generalUtils.h"
#include "wordId.h"
#include "fileUtils.h"
#include "globalVars.h"


#define PRE_PARSE_ERR_FORMAT "\nERROR (pre parse): %s\nfile: %s%s\n"
#define preParseErrMsg(msg){ \
    raiseErrFlag();          \
    printf(PRE_PARSE_ERR_FORMAT, msg, getInputFileName(), INPUT_FILE_SUFFIX); \
}

#define POST_PARSE_ERR_FORMAT "\nERROR (post parse): %s\nfile: %s%s\n"
#define postParseErrMsg(msg){ \
    printf(POST_PARSE_ERR_FORMAT, msg, getInputFileName(), INPUT_FILE_SUFFIX); \
}

#define NON_PARSE_ERR_FORMAT "\nERROR (non-parse error): %s\nfile: %s%s, line number: %d, line content: %s\n"
#define nonParseErrMsg(msg){ \
    printf(NON_PARSE_ERR_FORMAT, msg, getInputFileName(), INPUT_FILE_SUFFIX, getLineCounter(), getCurLine()); \
}

#define FIRST_PARSE_ERR_FORMAT "\nERROR (first parse): %s\nfile: %s%s, line number: %d, line content: %s\n"
#define firstParseErrMsg(msg){ \
    raiseErrFlag();            \
    printf(FIRST_PARSE_ERR_FORMAT, msg, getInputFileName(), INPUT_FILE_SUFFIX, getLineCounter(), getCurLine()); \
}

#define SEC_PARSE_ERR_FORMAT "\nERROR (second parse): %s\nfile: %s%s, label name: %s\n"
#define secParseErrMsg(msg, labName){ \
    raiseErrFlag();                   \
    printf(SEC_PARSE_ERR_FORMAT, msg, getInputFileName(), INPUT_FILE_SUFFIX, labName); \
}

void usageErr(){
    printf("\nUsage: give assembly files as arguments separated by a white space\neach argument should be given as the "
           "relative path of the assembly file excluding the suffix of the file itself\nthe suffix of each file should"
           " be %s\n\n", INPUT_FILE_SUFFIX);
}

void allocErr(){
    nonParseErrMsg("memory allocation failure")
}

void openFileErr(){
    preParseErrMsg("failed to open file")
}

void closeFileErr(){
    preParseErrMsg("failed to close file")
}

void printErr(){
    postParseErrMsg("failed to write to file")
}

void lineTooLongErr(){
    char msg[50];
    sprintf(msg, "line exceeds limit of characters: %d", MAX_LINE_LEN);
    firstParseErrMsg(msg)
}

void lineEndErr(){
    firstParseErrMsg("line ended before expected")
}

void lineNotEndErr(){
    firstParseErrMsg("line did not end when expected")
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
    sprintf(msg, "expected integer data separated by '%c'", SEPARATOR);
    firstParseErrMsg(msg)
}

void imNumErr(){
    char msg[50];
    sprintf(msg, "expected integer value immediately after '%c'", NUM_PREFIX);
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

void noSepAfterFirstOperandErr(){
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
