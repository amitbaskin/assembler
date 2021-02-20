#include <string.h>
#include "dataCollection.h"
#include "machineWordIdentifiers.h"
#include "generalUtils.h"

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

