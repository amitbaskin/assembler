/* getters for information of the assembly operators */

#include <string.h>
#include "opDefGetters.h"
#include "wordId.h"


static const operation opLst[] = {\
{0, "mov", 2, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1},
{1, "cmp", 2, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1},
{2, "add", 2, 2, 10, 1, 1, 0, 1, 0, 1, 0, 1},
{3, "sub", 2, 2, 11, 1, 1, 0, 1, 0, 1, 0, 1},
{4, "lea", 2, 4, 0, 0, 1, 0, 0, 0, 1, 0, 1},
{5, "clr", 1, 5, 10, 0, 0, 0, 0, 0, 1, 0, 1},
{6, "not", 1, 5, 11, 0, 0, 0, 0, 0, 1, 0, 1},
{7, "inc", 1, 5, 12, 0, 0, 0, 0, 0, 1, 0, 1},
{8, "dec", 1, 5, 13, 0, 0, 0, 0, 0, 1, 0, 1},
{9, "jmp", 1, 9, 10, 0,0, 0, 0, 0, 1, 1, 0},
{10, "bne", 1, 9, 11, 0,0, 0, 0, 0, 1, 1, 0},
{11, "jsr", 1, 9, 12, 0,0, 0, 0, 0, 1, 1, 0},
{12, "red", 1, 12, 0, 0, 0, 0, 0, 0, 1, 0, 1},
{13, "prn", 1, 13, 0, 0, 0, 0, 0, 1, 1, 0, 1},
{14, "rts", 0, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{15, "stop",0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

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
