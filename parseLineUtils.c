#include "parseLineUtils.h"
#include "generalUtils.h"
#include "wordIdentifiers.h"
#include "sWordSetters.h"

result finishLine(char **line){
    char chr;
    for (; (chr = **line) == ' ' || chr == '\t'; (*line)++);
    if (chr != '\0') return ERR;
    return SUCCESS;
}

void breakDownLineHelper(rawWord **raw, char *str){
    void *ptr;
    (*raw)->word = str;
    getAlloc(sizeof(rawWord), &ptr);
    (*raw)->next = (rawWord *) ptr;
    *raw = (rawWord *) ptr;
}

result breakDownLine(char **line, rawWord **raw, unsigned char isSep){
    result res;
    char *str;
    while ((res = getWord(line, &str, isSep)) == SUCCESS){
        breakDownLineHelper(raw, str);
    } if (isSep && res == SEP) {
        breakDownLineHelper(raw, SEP_STR);
        return breakDownLine(line, raw, isSep);
    } return res;
}
