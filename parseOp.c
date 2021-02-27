#include "parseOp.h"
#include "generalUtils.h"
#include "operationsApi.h"
#include "parseOpUtils.h"
#include "parseLineUtils.h"
#include "manageMachineWord.h"

result validateOperation(char *word, char **line, char **firstOp, char **secOp, ref *srcType, ref *destType){
    result res;
    int opIndex = getOpIndex(word);
    if (opIndex == NOT_OP) return ERR;
    int opsAmount = getOperandsAmount(opIndex);
    res = validateOperandsAmount(line, opsAmount, firstOp, secOp, opIndex, srcType, destType);
    if (res == ERR) return res;
    res = finishLine(line);
    if (res == ERR) return res;
    return SUCCESS;
}
