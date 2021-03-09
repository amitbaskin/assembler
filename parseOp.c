#include "parseOp.h"
#include "generalUtils.h"
#include "opDefGetters.h"
#include "opUtils.h"
#include "parseLineUtils.h"
#include "sWordSetters.h"

result validateOperation(int opIndex, int opsAmount, char **line, char **firstOp, char **secOp, labelLst *labLst,
                         label **lab, sWordLst *instLst){
    VALIDATE_VAL(validateOperandsAmount(line, opIndex, opsAmount, firstOp, secOp, labLst, lab, instLst), "")
    VALIDATE_VAL(finishLine(line), "")
    return SUCCESS;
}
//char **line, int opIndex, int operandsAmount, char **firstOp, char **secOp, labelLst
//*labLst, label **lab, sWordLst *instLst