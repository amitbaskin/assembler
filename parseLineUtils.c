#include "parseLineUtils.h"
#include "generalUtils.h"
#include "wordId.h"
#include "sWordSetters.h"
#include "parseLine.h"

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

int getLineLoopCond(char chr, int i){
    return (chr != '\n') && (chr != EOF) && (i <= MAX_LINE_LEN);
}

result getLine(char **line, FILE *fp){
    int chr;
    int i;
    for (; (chr = fgetc(fp)) == ' ' || chr == '\t'; (*line)++);
    ungetc(chr, fp);
    for (i=0; getLineLoopCond((char) (chr = fgetc(fp)), i); (*line)[i] = (char) chr, i++);
    (*line)[i] = '\0';
    if (chr == EOF) return FILE_END;
    if (chr != '\n') return ERR;
    return SUCCESS;
}

unsigned char isSepCond(unsigned char isSep, char chr){
    return isSep ? chr != SEPARATOR : 1;
}

int getWordLoopCond(char chr, unsigned char isSep){
    return (chr != ' ') && (chr != '\t') && (chr != '\n') && isSepCond(isSep, chr);
}

result getWord(char **line, char **word, unsigned char isSep){
    char chr;
    int i;
    for (; (chr = **line) == ' ' || chr == '\t'; (*line)++);
    for (i=0; getWordLoopCond((chr = **line), i); (*word)[i] = (char) chr, (*line)++, i++);
    (*word)[i] = '\0';
    if (chr == '\0') return LINE_END;
    if (isSep && chr == SEPARATOR) return SEP;
    return SUCCESS;
}
