#include <string.h>
#include "operationsApi.h"
#include "operationsDef.h"

int isOp(char *word){
    int i;
    for (i=0; i<OPS_AMOUNT; i++){
        if (!strcmp(names[i], word)) return i;
    } return NOT_OP;
}

char *getOpName(int i){
    return names[i];
}

unsigned char getFunct(int i){
    return functs[i];
}

unsigned char getOpCode(int i){
    return opcodes[i];
}

unsigned char getIsImSrc(int i){
    return isImSrcLst[i];
}

unsigned char getIsDirSrc(int i){
    return isDirSrcLst[i];
}

unsigned char getIsRelSrc(int i){
    return isRelSrcLst[i];
}

unsigned char getIsRegSrc(int i){
    return isRegSrcLst[i];
}

unsigned char getIsImDest(int i){
    return isImDestLst[i];
}

unsigned char getIsDirDest(int i){
    return isDirDestLst[i];
}

unsigned char getIsRelDest(int i){
    return isRelDestLst[i];
}

unsigned char getIsRegDest(int i){
    return isRegDestLst[i];
}