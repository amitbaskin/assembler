#include "parseLineUtils.h"
#include "generalUtils.h"
#include "wordId.h"
#include "sWordSetters.h"
#include "parseLine.h"
#include "rawWordLstUtils.h"
#include "rawWordUtils.h"

result finishLine(char **line){
    char chr;
    for (; (chr = **line) == ' ' || chr == '\t'; (*line)++);
    if (chr != '\0') return ERR;
    return SUCCESS;
}

result breakDownData(char **line, rawWordLst *lst, unsigned char isSep){
    result res;
    char *str;
    rawWord *word;
    VALIDATE_VAL(getWordAlloc(&str), "")
    while ((res = getWord(line, &str, isSep)) == SUCCESS){
        initRawWord(&word);
        setRawWordStr(word, str);
        addRawWord(lst, word);
    } freeHelper(str);
    return res;
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
    return (chr != ' ') && (chr != '\t') && (chr != '\n' &&chr != '\0') && isSepCond(isSep, chr);
}

result getWord(char **line, char **word, unsigned char isSep){
    char *originalPtr = *word;
    char chr;
    int i;
    for (; (chr = **line) == ' ' || chr == '\t'; (*line)++);
    for (i=0; getWordLoopCond((chr = **line), i); (*word)[i] = (char) chr, (*line)++, i++);
    (*word)[i] = '\0';
    if (*originalPtr == '\0') return FALSE;
    if (chr == '\0') return LINE_END;
    if (isSep && chr == SEPARATOR) return SEP;
    return SUCCESS;
}
