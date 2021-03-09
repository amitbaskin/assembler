#include "secParse.h"
#include "generalUtils.h"
#include "sWordSetters.h"
#include "labUtils.h"
#include "labSetters.h"
#include "sWordGetters.h"
#include "labLstUtils.h"
#include "sWordListUtils.h"
#include "sWordUtils.h"

result parseInstLst(sWordLst *instLst, labelLst *labLst){
    label *lab;
    result res = SUCCESS;
    sWord *ptr;
    wordStatus status;
    for (ptr = getSWordTail(instLst); ptr != NULL; promoteSWord(&ptr)){
        status = getSWordStatus(ptr);
        if (status == W_ENT) {
            if (isLabInLst(labLst, &lab, L_ENT, getSULabName(ptr)) == FALSE) {
                res = ERR;
                printf("");
                continue;
            }
            setLabType(lab, L_ENT);
        }

        if (status == LAB) {
            if (isLabInLst(labLst, &lab, L_NONE, getSULabName(ptr)) == FALSE) {
                res = ERR;
                printf("");
                continue;
            }
            setSULab(ptr, lab);
        }
    } return res;
}
