#include "rawWordUtils.h"

result initRawWord(rawWord **word){
    void *ptr;
    VALIDATE_VAL(getAlloc(sizeof(rawWord), &ptr), "");
    *word = (rawWord *) ptr;
    VALIDATE_VAL(getAlloc(sizeof(rawData), &ptr), "")
    setRawData(*word, (rawData *) ptr);
    VALIDATE_VAL(getAlloc(MAX_LINE_LEN, &ptr), "")
    setRawWordStr(*word, (char *) ptr);
    return SUCCESS;
}
void freeRawWord(rawWord *word){
    freeHelper(getRawData(word));
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

rawData *getRawData(rawWord *word){
    return word->data;
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

void setRawData(rawWord *raw, rawData *data){
    raw->data = data;
}



