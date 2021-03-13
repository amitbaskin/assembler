/* getters for information of the assembly operators */

#include <string.h>
#include "opDefGetters.h"
#include "opDef.h"

char *getOpName(int index){
    return opLst[index].name;
}

unsigned char getOperandsAmount(int index){
    return opLst[index].opAmount;
}

int getOpCode(int index){
    return opLst[index].opcode;
}

int getFunct(int index){
    return opLst[index].funct;
}

unsigned char getIsImSrc(int index){
    return opLst[index].isImSrc;
}

unsigned char getIsDirSrc(int index){
    return opLst[index].isDirSrc;
}

unsigned char getIsRelSrc(int index){
    return opLst[index].isRelSrc;
}

unsigned char getIsRegSrc(int index){
    return opLst[index].isRegSrc;
}

unsigned char getIsImDest(int index){
    return opLst[index].isImDest;
}

unsigned char getIsDirDest(int index){
    return opLst[index].isDirDest;
}

unsigned char getIsRelDest(int index){
    return opLst[index].isRelDest;
}

unsigned char getIsRegDest(int index){
    return opLst[index].isRegDest;
}

int getOpIndexByStr(char *word){
    /* checks if the given word is an operator statement, if so returns its index in the operators list and otherwise
     * returns the NOT_OP constant */
    int i;
    for (i=0; i < OPERATIONS_AMOUNT; i++){
        if (!strcmp(opLst[i].name, word)) return i;
    } return NOT_OP;
}
