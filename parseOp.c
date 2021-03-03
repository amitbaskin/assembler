#include "parseOp.h"
#include "generalUtils.h"
#include "opDefGetters.h"
#include "opUtils.h"
#include "parseLineUtils.h"
#include "sWordSetters.h"

result validateOperation(char *word, int opsAmount, char **line, char **firstOp, char **secOp, ref *srcType,
                         ref *destType){
    int opIndex = getOpIndexByStr(word);
    if (opIndex == NOT_OP) return ERR;
    VALIDATE_FUNC_CALL(validateOperandsAmount(line, opsAmount, firstOp, secOp, opIndex, srcType, destType), "")
    VALIDATE_FUNC_CALL(finishLine(line), "")
    return SUCCESS;
}
