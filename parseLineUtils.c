#include <stdio.h>
#include <string.h>
#include "parseLineUtils.h"
#include "generalUtils.h"
#include "machineWordIdentifiers.h"
#include "labelUtils.h"
#include "manageMachineWord.h"
#include "dataCollection.h"

enum result dataScenario(char *line, sWord **lastWord, data *dat){
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

void breakDownLineHelper(rawWord **word, char *str){
    void *ptr;
    (*word)->word = str;
    getAlloc(sizeof(rawWord), &ptr);
    (*word)->next = (rawWord *) ptr;
    *word = (rawWord *) ptr;
}

result breakDownLine(char **line, rawWord *word){
    result res;
    char *str;
    while ((res = getWord(line, &str)) == SUCCESS){
        breakDownLineHelper(&word, str);
    } if (res == SEP) {
        breakDownLineHelper(&word, SEP_STR);
        return breakDownLine(line, word);
    } return res;
}

result collectData(char **line, data *dat){
    char *word;
    long num;
    data *next;
    void *ptr;
    result res;
    while((res = getWord(line, &word)) != LINE_END && res != FILE_END){
        if (isNumData(&num, word) == ERR) return ERR;
        dat->num = (int) num;
        getAlloc(sizeof(data), &ptr);
        next = (data *) ptr;
        dat->next = next;
        dat = next;
        if (getWord(line, &word) != LINE_END && res != SEP) return ERR;
    } if (res == FILE_END) return res;
    return SUCCESS;
}


