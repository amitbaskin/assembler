#include "parseOp.h"
#include "generalUtils.h"
#include "operationsApi.h"
#include "parseOpUtils.h"
#include "parseLineUtils.h"


result getOperands(char *word, char **line, int *opsAmount, char **firstOp, char **secOp){
    result res;
    int opIndex = isOp(word);
    if (opIndex == NOT_OP) return ERR;
    *opsAmount = getOperandsAmount(opIndex);
    res = validateOperandsAmount(line, *opsAmount, firstOp, secOp);
    if (res == ERR) return res;
    res = finishLine(line);
    if (res == ERR) return res;
    return SUCCESS;
}

