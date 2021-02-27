#include <string.h>
#include "operationsApi.h"
#include "operationsDef.h"

int getOpIndex(char *word){
    int i;
    for (i=0; i < OPERATIONS_AMOUNT; i++){
        if (!strcmp(operations[i], word)) return i;
    } return NOT_OP;
}

char *getOpName(int opIndex){
    return operations[opIndex];
}

unsigned char getFunct(int opIndex){
    return functs[opIndex];
}

unsigned char getOperandsAmount(int opIndex){
    return opAmounts[opIndex];
}

unsigned char getOpCode(int opIndex){
    return opcodes[opIndex];
}

unsigned char getIsImSrc(int opIndex){
    return isImSrcLst[opIndex];
}

unsigned char getIsDirSrc(int opIndex){
    return isDirSrcLst[opIndex];
}

unsigned char getIsRelSrc(int opIndex){
    return isRelSrcLst[opIndex];
}

unsigned char getIsRegSrc(int opIndex){
    return isRegSrcLst[opIndex];
}

unsigned char getIsImDest(int opIndex){
    return isImDestLst[opIndex];
}

unsigned char getIsDirDest(int opIndex){
    return isDirDestLst[opIndex];
}

unsigned char getIsRelDest(int opIndex){
    return isRelDestLst[opIndex];
}

unsigned char getIsRegDest(int opIndex){
    return isRegDestLst[opIndex];
}