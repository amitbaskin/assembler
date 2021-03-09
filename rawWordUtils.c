#include "rawWordUtils.h"

result initRawWord(rawWord **word){
    void *ptr;
    VALIDATE_VAL(getAlloc(sizeof(rawWord), &ptr), "");
    *word = (rawWord *) ptr;
    return SUCCESS;
}
void freeRawWord(rawWord *word){
    freeHelper(word);
}
void promoteRawWord(rawWord **word){
    *word = (*word)->next;
}

rawWord *getRawWordNext(rawWord *word){
    return word->next;
}

char *getRawWordStr(rawWord *raw){
    return raw->data->word;
}

int getRawWordNum(rawWord *raw){
    return raw->data->num;
}

void setRawWordNext(rawWord *this, rawWord *other){
    this->next = other;
}

void setRawWordStr(rawWord *raw, char *str){
    raw->data->word = str;
}

void setRawWordNum(rawWord *raw, int num){
    raw->data->num = num;
}
