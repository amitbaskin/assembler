#include "parseLineUtils.h"
#include "generalUtils.h"
#include "wordId.h"
#include "sWordSetters.h"
#include "parseLine.h"
#include "rawWordLstUtils.h"
#include "rawWordUtils.h"
#include "errFuncs.h"

extern lineCounter;

result finishLine(char **line){
    char chr;
    for (; (chr = **line) == ' ' || chr == '\t'; (*line)++);
    if (chr != '\0') {
        lineEndErr();
        return ERR;
    } return SUCCESS;
}

result breakDownData(char **line, rawWordLst *lst){
    result res;
    char *str;
    rawWord *word;
    int isContinue;
    int counter;
    unsigned char isSep = 1;
    for (counter=0, isContinue=1; isContinue; counter++, setRawWordStr(word, str), addRawWord(lst, word)){
        VALIDATE_VAL(getWordAlloc(&str))
        res = getWord(line, &str, 1);
        if (res == LINE_END) {
            isContinue = 0;
            if (*str == '\0') break;
        } if (!isSep) sepErr();
        if (res != SEP) isSep = 0;
        VALIDATE_VAL(initRawWord(&word))
    } if (counter == 0){
        nonNumericDataErr();
        return ERR;
    } return res;
}

int getLineLoopCond(char chr, int i){
    return (chr != '\n') && (chr != EOF) && (i < MAX_LINE_LEN);
}

result getLine(char **line, FILE *fp){
    result res;
    int chr;
    int i;
    for (; (chr = fgetc(fp)) == ' ' || chr == '\t'; (*line)++);
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

unsigned char isSepCond(unsigned char isSep, char chr){
    return isSep ? chr != SEPARATOR : 1;
}

int getWordLoopCond(char chr, unsigned char isSep){
    return (chr != ' ') && (chr != '\t') && (chr != '\n' &&chr != '\0')  && (chr != LABEL_SUFFIX) &&
    isSepCond(isSep, chr);
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
