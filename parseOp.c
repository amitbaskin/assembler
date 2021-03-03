#include "parseOp.h"
#include "generalUtils.h"
#include "opDefGetters.h"
#include "opUtils.h"
#include "parseLineUtils.h"
#include "sWordSetters.h"

result validateOperation(char *word, int opsAmount, char **line, char **firstOp, char **secOp, ref *srcType,
                         ref *destType){
    result res;
    int opIndex = getOpIndexByStr(word);
    if (opIndex == NOT_OP) return ERR;
    res = validateOperandsAmount(line, opsAmount, firstOp, secOp, opIndex, srcType, destType);
    if (res == ERR) return res;
    res = finishLine(line);
    if (res == ERR) return res;
    return SUCCESS;
}
