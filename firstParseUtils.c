#include <stdio.h>
#include <string.h>
#include "firstParseUtils.h"
#include "generalUtils.h"
#include "machineWordIdentifiers.h"
#include "labelUtils.h"
#include "manageMachineWord.h"
#include "dataCollection.h"

unsigned char dataScenario(char *line, sWord **lastWord, data *dat){
    uWord *unionWord;
    sWord *structWord;
    if (collectData(&line, dat) == ERR) return ERR;
    while (dat != NULL){
        unionWord = getUWord();
        setNumData(unionWord, dat->num);
        dat = dat->next;
        structWord = getSword();
        structWord->status = NUM;
        structWord->uWord = unionWord;
        structWord->address = dataCounter;
        structWord->addressType = R_TYPE;
        (*lastWord)->next = structWord;
        *lastWord = structWord;
    } return SUCCESS;
}

void strScenario(char *str, sWord **lastWord){
    uWord *unionWord;
    sWord *structWord;
    unsigned long len = strlen(str);
    int i;
    char chr;
    for (i=1; i<len-1; i++){
        chr = str[i];
        unionWord = getUWord();
        setChrData(unionWord, chr);
        structWord->status = CHR;
        structWord = getSword();
        structWord->uWord = unionWord;
        structWord->address = dataCounter;
        structWord->addressType = R_TYPE;
        (*lastWord)->next = structWord;
        *lastWord = structWord;
    }
}
