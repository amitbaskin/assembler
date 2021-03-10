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
    int isContinue = 1;
    while (isContinue){
        VALIDATE_VAL(getWordAlloc(&str), "")
        res = getWord(line, &str, isSep);
        if (res == LINE_END) {
            isContinue = 0;
            if (*str == '\0') break;
        } initRawWord(&word);
        setRawWordStr(word, str);
        addRawWord(lst, word);
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
    return (chr != ' ') && (chr != '\t') && (chr != '\n' &&chr != '\0')  && (chr != LABEL_SUFFIX) &&
    isSepCond(isSep, chr);
}

result getWord(char **line, char **word, unsigned char isSep){
    char *originalPtr = *word;
    char chr;
    int i;
    for (; (chr = **line) == ' ' || chr == '\t'; (*line)++);
    for (i=0; getWordLoopCond((chr = **line), i); (*word)[i] = (char) chr, (*line)++, i++);
    (*word)[i] = '\0';
    if (*originalPtr == '\0') return FALSE;
    if (chr == LABEL_SUFFIX) {
        (*line)++;
        return LAB_DEC;
    } if (chr == '\0') return LINE_END;
    if (isSep && chr == SEPARATOR) {
        (*line)++;
        return SEP;
    }
    return SUCCESS;
}
