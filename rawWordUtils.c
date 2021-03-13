/* this file is used to provide utilities for handling a data structure containing integer data */

#include "rawWordUtils.h"

rawData *getRawData(rawWord *word){
    return word->data;
}

void setRawData(rawWord *raw, rawData *data){
    raw->data = data;
}

result initRawWord(rawWord **word){
    /* allocates memory for a rawWord
     * returns ERR if a memory allocation ERR has occurred and SUCCESS otherwise */
    void *ptr;
    VALIDATE_VAL(getAlloc(sizeof(rawWord), &ptr))
    *word = (rawWord *) ptr;
    VALIDATE_VAL(getAlloc(sizeof(rawData), &ptr))
    setRawData(*word, (rawData *) ptr);
    VALIDATE_VAL(getAlloc(MAX_LINE_LEN, &ptr))
    setRawWordStr(*word, (char *) ptr);
    return SUCCESS;
}

void freeRawWord(rawWord *word){
    freeHelper(getRawData(word));
    freeHelper(word);
}
void promoteRawWord(rawWord **word){
    /* sets a rawWord to point to its successor */
    *word = (*word)->next;
}

char *getRawWordStr(rawWord *raw){
    return raw->data->word;
}

int getRawWordNum(rawWord *raw){
    return raw->data->num;
}

void setRawWordStr(rawWord *raw, char *str){
    raw->data->word = str;
}

void setRawWordNum(rawWord *raw, int num){
    raw->data->num = num;
}
