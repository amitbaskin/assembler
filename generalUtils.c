#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generalUtils.h"

result getFile(char *name, FILE **fp, char *mode, char *suffix){
    unsigned long nameLen = strlen(name);
    unsigned long sufLen = strlen(suffix);
    char *fullName = malloc(nameLen+sufLen-1);
    strcpy(fullName, name);
    strcat(fullName, suffix);
    *fp = fopen(fullName, mode);
    if (*fp == NULL) {
        return ERR;
    } return SUCCESS;
}

int getReadFile(char *name, FILE **fp){
    return getFile(name, fp, "r", READ_FILE_SUFFIX);
}


int getWriteFile(char *name, FILE **fp){
    return getFile(name, fp, "w", WRITE_FILE_SUFFIX);
}

result getAlloc(size_t size, void **ptr){
    *ptr = malloc(size);
    if (ptr == NULL){
        return ERR;
    } return SUCCESS;
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

unsigned char isSepFunc(unsigned char isSep, char chr){
    return isSep ? chr != SEPARATOR : 1;
}

int getWordLoopCond(char chr, unsigned char isSep){
    return (chr != ' ') && (chr != '\t') && (chr != '\n') && isSepFunc(isSep, chr);
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
