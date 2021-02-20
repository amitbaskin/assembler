#include <string.h>
#include "dataCollection.h"
#include "machineWordIdentifiers.h"
#include "generalUtils.h"

unsigned char collectData(char **line, data *dat){
    char *word;
    long num;
    data *next;
    void *ptr;
    while(getWord(line, &word) != LINE_END){
        if (isNumData(&num, word) == ERR) return ERR;
        dat->num = (int) num;
        getAlloc(sizeof(data), &ptr);
        next = (data *) ptr;
        dat->next = next;
        dat = next;
        if (getWord(line, &word) != LINE_END && strcmp(word, SEPARATOR) != 0) return ERR;
    } return SUCCESS;
}
