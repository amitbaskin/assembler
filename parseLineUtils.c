#include "parseLineUtils.h"
#include "errFuncs.h"

extern lineCounter;

unsigned char isSepCond(unsigned char isSep, char chr){
    return isSep ? chr != SEPARATOR : 1;
}

int getWordLoopCond(char chr, unsigned char isSep){
    return (chr != ' ') && (chr != '\t') && (chr != '\n' &&chr != '\0')  && (chr != LABEL_SUFFIX) &&
           isSepCond(isSep, chr);
}

int getLineLoopCond(char chr, int i){
    return (chr != '\n') && (chr != EOF) && (i < MAX_LINE_LEN);
}

result finishLine(char **line){
    char chr;
    for (; (chr = **line) == ' ' || chr == '\t'; (*line)++);
    if (chr != '\0') {
        lineNotEndErr();
        return ERR;
    } return SUCCESS;
}

result isEmptyLine(const char *line){
    while(*line != '\0'){
        if (*line != ' ' && *line != '\t' && *line != '\n') return FALSE;
    } return TRUE;
}

result getLine(char **line, FILE *fp){
    result res;
    int chr;
    int i;
    for (; (chr = fgetc(fp)) == ' ' || chr == '\t'; );
    ungetc(chr, fp);
    for (i=0; getLineLoopCond((char) (chr = fgetc(fp)), i); (*line)[i] = (char) chr, i++);
    if (i == MAX_LINE_LEN) {
        for (; (fgetc(fp)) != '\n'; ); /* prepare next line */
        lineTooLongErr();
        res = ERR;
    } else if (chr == EOF) res = FILE_END;
    else res = SUCCESS;
    (*line)[i] = '\0';
    return res;
}

result getWord(char **line, char **word, unsigned char isSep){
    char chr;
    int i;
    for (; (chr = **line) == ' ' || chr == '\t'; (*line)++);
    for (i=0; getWordLoopCond((chr = **line), i); (*word)[i] = (char) chr, (*line)++, i++);
    (*word)[i] = '\0';
    if (chr == LABEL_SUFFIX) {
        (*line)++;
        return LAB_DEC;
    } if (chr == '\0') return LINE_END;
    if (isSep && chr == SEPARATOR) {
        (*line)++;
        return SEP;
    } return SUCCESS;
}
