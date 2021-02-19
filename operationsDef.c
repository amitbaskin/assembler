#include <stdio.h>
#include "operationsDef.h"
#include "operationsApi.h"

#include "utils.h"

void printOps(){
    /*function for debugging purposes*/
    int i;
    for (i=0; i<OPS_AMOUNT; i++){
        printf("op name: %s, funct: %u, opcode: %u, isImSrc: %u, isDirSrc: %u, isRelSrc: %u, isRegSrc: %u\n"
               "isImDest: %u, isDirDest: %u, isRelDest %u, isRegDest: %u\n\n",
               getOpName(i), getFunct(i), getOpCode(i), getIsImSrc(i), getIsDirSrc(i), getIsRelSrc(i), getIsRegSrc(i),
               getIsImDest(i), getIsDirDest(i), getIsRelDest(i), getIsRegDest(i));
    }
}
