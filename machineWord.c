#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "machineWord.h"

unsigned char isLabel(char *word){
    unsigned long len;
    len = strlen(word);
    if (word[len-2] == LABEL_SUFFIX) return 1;
    return 0;
}

unsigned char isLegalLabel(const char *word){
    unsigned long len;
    len = strlen(word);
    int i;
    if (isalpha(word[0])){
        for (i=1; i<len; i++){
            if(!isalnum(word[i])) return 0;
        }
    } return 1;
}

unsigned char isData(char *word){
    if (!strcmp(word, DATA_ORDER)) return 1;
    return 0;
}

unsigned char isStringOrder(char *word){
    if (!strcmp(word, STRING_ORDER)) return 1;
    return 0;
}

unsigned char isEntryOrder(char *word){
    if (!strcmp(word, ENTRY_ORDER)) return 1;
    return 0;
}

unsigned char isExternOrder(char *word){
    if (!strcmp(word, EXTERN_ORDER)) return 1;
    return 0;
}

unsigned char isString(char *word){
    unsigned long len;
    len = strlen(word);
    if (word[0] == '"' && word[len-1] == '"') return 1;
    return 0;
}

void getNumFromWord(long *got, char *word){
    unsigned long len;
    len = strlen(word);
    if (len < 2 || word[0] != NUM_PREFIX) return;
    *got = strtol(word+1, &word, 10);
}
