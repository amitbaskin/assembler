#include <stdio.h>
#include <stdlib.h>
#include "operationsDef.h"

void initializeOps(){
    char *names[] = OPERATIONS;
    unsigned char functs[] = FUNCTS;
    unsigned char opcodes[] = OPCODES;
    unsigned char isImSrcLst[] = IS_IMMEDIATE_SOURCE_LST;
    unsigned char isDirSrcLst[] = IS_DIRECT_SOURCE_LST;
    unsigned char isRelSrcLst[] = IS_RELATIVE_SOURCE_LST;
    unsigned char isRegSrcLst[] = IS_REGISTRY_SOURCE_LST;
    unsigned char isImDestLst[] = IS_IMMEDIATE_DEST_LST;
    unsigned char isDirDestLst[] = IS_DIRECT_DEST_LST;
    unsigned char isRelDestLst[] = IS_RELATIVE_DEST_LST;
    unsigned char isRegDestLst[] = IS_REGISTRY_DEST_LST;
    struct op *cur;
    int i;
    for (i=0; i<OPS_AMOUNT; i++){
        cur = (struct op*) malloc(sizeof (struct op));
        cur->name = names[i];
        cur->funct = functs[i];
        cur->opcode = opcodes[i];
        cur->isImSrc = isImSrcLst[i];
        cur->isDirSrc = isDirSrcLst[i];
        cur->isRelSrc = isRelSrcLst[i];
        cur->isRegSrc = isRegSrcLst[i];
        cur->isImDest = isImDestLst[i];
        cur->isDirDest = isDirDestLst[i];
        cur->isRelDest = isRelDestLst[i];
        cur->isRegDest = isRegDestLst[i];
        ops[i] = cur;
    }
}

void printOps(){
    int i;
    for (i=0; i<OPS_AMOUNT; i++){
        printf("name: %s, funct: %u, opcode: %u, isImSrc: %u, isDirSrc: %u, isRelSrc: %u, isRegSrc: %u\n"
               "isImDest: %u, isDirDest: %u, isRelDest %u, isRegDest: %u\n\n",
               ops[i]->name, ops[i]->funct, ops[i]->opcode, ops[i]->isImSrc, ops[i]->isDirSrc, ops[i]->isRelSrc,
               ops[i]->isRegSrc, ops[i]->isImDest, ops[i]->isDirDest, ops[i]->isRelDest, ops[i]->isRegDest);
    }
}
