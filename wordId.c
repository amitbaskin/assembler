/* this file is used to identify in general the strings read from the assembly file */

#include <stdlib.h>
#include <string.h>
#include "wordId.h"
#include "errFuncs.h"


static const char *regs[] = REGS;

const char *getReg(int i){
    return regs[i];
}

int isReg(char *r){
    int i;
    for (i=0; i < REGS_AMOUNT; i++){
        if (!strcmp(r, regs[i])) return i;
    }
    return NOT_REG;
}

result isDataOrder(char *word){
    if (!strcmp(word, DATA_ORDER)) return TRUE;
    return FALSE;
}

result isStringOrder(char *word){
    if (!strcmp(word, STRING_ORDER)) return TRUE;
    return FALSE;
}

result isEntryOrder(char *word){
    if (!strcmp(word, ENTRY_ORDER)) return TRUE;
    return FALSE;
}

result isExternOrder(char *word){
    if (!strcmp(word, EXTERN_ORDER)) return TRUE;
    return FALSE;
}

result isString(char *word){
    unsigned long len;
    len = strlen(word);
    if (word[0] == '"' && word[len-1] == '"') return TRUE;
    return FALSE;
}

result isImmediateNum(long *got, char *word){
    result res;
    unsigned long len;
    len = strlen(word);
    if (len < 2 || word[0] != NUM_PREFIX) return FALSE;
    word++;
    res = isNum(got, word);
    if (res == ERR) imNumErr();
    return res;
}

result isNum(long *got, char *word){
    *got = strtol(word, &word, 10);
    if (strcmp(word, "\0") != 0) {
        return ERR;
    }
    else return TRUE;
}
