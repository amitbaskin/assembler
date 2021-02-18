#include <string.h>
#include "operationsApi.h"
#include "operationsDef.h"

int isOp(char *word){
    int i;
    for (i=0; i<OPS_AMOUNT; i++){
        if (!strcmp(ops[i]->name, word)) return i;
    } return -1;
}

unsigned char getFunct(int i){
    return ops[i]->funct;
}

unsigned char getOpCode(int i){
    return ops[i]->opcode;
}

unsigned char getIsImSrc(int i){
    return ops[i]->isImSrc;
}

unsigned char getIsDirSrc(int i){
    return ops[i]->isDirSrc;
}

unsigned char getIsRelSrc(int i){
    return ops[i]->isRelSrc;
}

unsigned char getIsRegSrc(int i){
    return ops[i]->isRegSrc;
}

unsigned char getIsImDest(int i){
    return ops[i]->isImDest;
}

unsigned char getIsDirDest(int i){
    return ops[i]->isDirDest;
}

unsigned char getIsRelDest(int i){
    return ops[i]->isRelDest;
}

unsigned char getIsRegDest(int i){
    return ops[i]->isRegDest;
}
