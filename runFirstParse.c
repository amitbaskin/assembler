#include <stdio.h>
#include <string.h>
#include "runFirstParse.h"
#include "generalUtils.h"
#include "labelUtils.h"
#include "manageMachineWord.h"

void run(FILE *fp){
    char *line;
    getLine(&line, fp);
    char *word;
    getWord(&line, &word);
    unsigned long len = strlen(word);
    if (isLabelDeclaration(word, len) == TRUE) labelFlag = 1;
    getWord(&line, &word);
}

