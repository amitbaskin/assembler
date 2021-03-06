#include "parseOp.h"
#include "generalUtils.h"
#include "opDefGetters.h"
#include "opUtils.h"
#include "parseLineUtils.h"
#include "sWordSetters.h"

result validateOperation(char *word, int opIndex, int opsAmount, char **line, char **firstOp, char **secOp, ref
*srcType, ref *destType){
    VALIDATE_VAL(validateOperandsAmount(line, opsAmount, firstOp, secOp, opIndex, srcType, destType), "")
    VALIDATE_VAL(finishLine(line), "")
    return SUCCESS;
}
