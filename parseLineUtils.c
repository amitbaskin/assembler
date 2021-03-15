/* this file is used to provide utilities for parsing a line from an assembly file */

#include "parseLineUtils.h"
#include "errFuncs.h"


unsigned char isSepCond(unsigned char isSep, char chr){
    /* meant for separating between parsings that look for a separator and ones that don't
     * this is adjusting the condition used while parsing in order to determine if the parsing was successful */
    return isSep ? chr != SEPARATOR : 1;
}

int getWordLoopCond(char chr, unsigned char isSep){
    /* condition for when to stop reading from the line extracted from an assembly file, and start processing the
     * string being read from now on */
    return (chr != ' ') && (chr != '\t') && (chr != '\n' &&chr != '\0')  && (chr != LABEL_SUFFIX) &&
           isSepCond(isSep, chr);
}

int getLineLoopCond(char chr, int i){
    /* condition for when to stop reading from the input assembly file, in order to start recording the line
     * extracted from it */
    return (chr != '\n') && (chr != EOF) && (i < MAX_LINE_LEN);
}

result finishLine(char **line){
    /* make sure the line ends with white characters only, if so return SUCCESS and else return ERR */
    char chr;
    for (; (chr = **line) == ' ' || chr == '\t'; (*line)++);
    if (chr != '\0') {
        lineNotEndErr();
        return ERR;
    } return SUCCESS;
}

result isEmptyLine(const char *line){
    /* checks whether the given line contains white characters only
     * returns TRUE if so and FALSE otherwise */
    while(*line != '\0'){
        if (*line != ' ' && *line != '\t' && *line != '\n') return FALSE;
    } return TRUE;
}

result getLine(char **line, FILE *fp){
    /* extracts a line from an input assembly file */
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
    /* extracts a word from an assembly file line */
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
