/* this file is used to declare the global variables used in this program */

#include "generalUtils.h"
int labelFlag = 0;
int errFlag = 0;
int instructionCounter = INITIAL_INSTRUCTION_NUM;
int dataCounter = 0;
int lineCounter = 0;
int ICF = 0; /* instruction counter final - used for adding to the addresses of the data items so they will be at
 * the end of the main output */
char *inputFileName = "\0";
char *curLine = "\0";

int getLabelFlag(){
    return labelFlag;
}

int getErrFlag(){
    return errFlag;
}

int getInstructionCounter(){
    return instructionCounter;
}

int getDataCounter(){
    return dataCounter;
}

int getLineCounter(){
    return lineCounter;
}

int getIcf(){
    return ICF;
}

char *getInputFileName(){
    return inputFileName;
}

char *getCurLine(){
    return curLine;
}

void raiseLabelFlag(){
    labelFlag = 1;
}

void raiseErrFlag(){
    errFlag = 1;
}

void resetLabelFlag(){
    labelFlag = 0;
}

void resetErrFlag(){
    errFlag = 0;
}

void updateInstructionCounter(){
    instructionCounter++;
}

void updateDataCounter(){
    dataCounter++;
}

void updateLineCounter(){
    lineCounter++;
}

void setCurLine(char *line){
    curLine = line;
}

void setInputFileName(char *name){
    inputFileName = name;
}

void setIcf(int final){
    ICF = final;
}

void initGlobalVars(){
    labelFlag = 0;
    errFlag = 0;
    instructionCounter = INITIAL_INSTRUCTION_NUM;
    dataCounter = 0;
    lineCounter = 0;
    ICF = 0;
}
