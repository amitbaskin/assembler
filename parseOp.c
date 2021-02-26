#include "parseOp.h"
#include "generalUtils.h"
#include "operationsApi.h"
#include "parseOpUtils.h"
#include "parseLineUtils.h"


result parseOp(char *word, char **line){
    result res;
    char *firstOp;
    char *sep;
    char *secOp;
    int opsAmount;
    int opIndex = isOp(word);
    if (opIndex == NOT_OP) return ERR;
    opsAmount = getOperandsAmount(opIndex);
    res = validateOperandsAmount(line, opsAmount, &firstOp, &sep, &secOp);
    if (res == ERR) return ERR;
    res = finishLine(line);
    if (res == ERR) return ERR;

}