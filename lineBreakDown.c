#include "lineBreakDown.h"

void helper(rawWord **word, char *str){
    void *ptr;
    (*word)->word = str;
    getAlloc(sizeof(rawWord), &ptr);
    (*word)->next = (rawWord *) ptr;
    *word = (rawWord *) ptr;
}

result breakDownLine(char **line, rawWord *word){
    result res;
    char *str;
    while ((res = getWord(line, &str)) == SUCCESS){
        helper(&word, str);
    } if (res == SEP) {
        helper(&word, SEP_STR);
        return breakDownLine(line, word);
    } return res;
}
