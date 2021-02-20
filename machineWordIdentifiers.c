#include <stdlib.h>
#include <string.h>
#include "generalUtils.h"
#include "machineWordIdentifiers.h"

int isReg(char *r){
    int i;
    for (i=0; i<REGS_LEN; i++){
        if (!strcmp(r, regs[i])) return i;
    } return NOT_REG;
}

unsigned char isData(char *word){
    if (!strcmp(word, DATA_ORDER)) return TRUE;
    return FALSE;
}

unsigned char isStringOrder(char *word){
    if (!strcmp(word, STRING_ORDER)) return TRUE;
    return FALSE;
}

unsigned char isEntryOrder(char *word){
    if (!strcmp(word, ENTRY_ORDER)) return TRUE;
    return FALSE;
}

unsigned char isExternOrder(char *word){
    if (!strcmp(word, EXTERN_ORDER)) return TRUE;
    return FALSE;
}

unsigned char isString(char *word){
    unsigned long len;
    len = strlen(word);
    if (word[0] == '"' && word[len-1] == '"') return TRUE;
    return FALSE;
}

unsigned char isImmediateNum(long *got, char *word){
    unsigned long len;
    len = strlen(word);
    if (len < 2 || word[0] != NUM_PREFIX) return FALSE;
    *got = strtol(word+1, &word, 10);
    if (strcmp(word, "\0") != 0) return ERR;
    else return TRUE;
}

unsigned char isNumData(long *got, char *word){
    *got = strtol(word, &word, 10);
    if (strcmp(word, "\0") != 0) return ERR;
    else return TRUE;
}
