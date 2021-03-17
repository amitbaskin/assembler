/* this file is used for the second parse of an assembly file */

#include "secParse.h"
#include "labSetters.h"
#include "sWordGetters.h"
#include "labLstUtils.h"
#include "sWordListUtils.h"
#include "sWordUtils.h"
#include "labGetters.h"
#include "errFuncs.h"
#include "sWordSetters.h"


result parseInstLst(sWordLst *instLst, labelLst *labLst){
    /* make sure that the entry statements made in the input assembly file indeed refer to actual declared labels and
     * that no labels were declared both entry and extern */
    label *lab;
    result res = SUCCESS;
    wordStatus status;
    sWord *ptr;
    char *labName;
    for (ptr = getSWordTail(instLst); ptr != NULL; promoteSWord(&ptr)){
        status = getSWordStatus(ptr);
        if (status == W_ENT) {
            labName = getSULabName(ptr);
            if (isLabInLst(labLst, &lab, L_ENT, labName) == FALSE) {
                useOfUndefinedLabErr(labName);
                res = ERR; /* handled inside */
                continue;
            }
            setLabType(lab, L_ENT);
        }
        else if (status == LAB) {
            labName = getSULabName(ptr);
            if (isLabInLst(labLst, &lab, L_NONE, labName) == FALSE) {
                useOfUndefinedLabErr(labName);
                res = ERR; /* handled inside */
                continue;
            }
            else if (isSULabRel(ptr)) {
                setSWordAddressType(ptr, A_TYPE);
            }
            else if (getLabType(lab) == EXT) {
                setSWordAddressType(ptr, E_TYPE);
                setSULabType(ptr, EXT);
            }
            else {
                setSWordAddressType(ptr, R_TYPE);
                setSULabAddress(ptr, getLabAddress(lab));
            }
        }
    }
    return res;
}
