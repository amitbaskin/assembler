#include <stdio.h>
#include <string.h>
#include "runFirstParse.h"
#include "generalUtils.h"
#include "labelUtils.h"
#include "manageMachineWord.h"



enum result parseLine(FILE *fp, char **line, char **word){
    enum result res = getLine(line, fp);
    if (res != SUCCESS) return res;


}

