#include "secParse.h"
#include "generalUtils.h"
#include "sWordSetters.h"
#include "labUtils.h"
#include "labSetters.h"
#include "sWordGetters.h"
#include "labLstUtils.h"
#include "sWordListUtils.h"
#include "sWordUtils.h"
#include "labGetters.h"

extern lineCounter;
extern int ICF;

result parseInstLst(sWordLst *instLst, labelLst *labLst){
    label *lab;
    result res = SUCCESS;
    wordStatus status;
    sWord *ptr;
    for (ptr = getSWordTail(instLst); ptr != NULL; promoteSWord(&ptr)){
        lineCounter++;
        int x = lineCounter;
        status = getSWordStatus(ptr);
        if (status == W_ENT) {
            if (isLabInLst(labLst, &lab, L_ENT, getSULabName(ptr)) == FALSE) {
                res = ERR;
                printf("");
                continue;
            }
        } if (status == LAB) {
            if (isLabInLst(labLst, &lab, L_NONE, getSULabName(ptr)) == FALSE) {
                res = ERR;
                printf("");
                continue;
            } freeHelper(getSULab(ptr));
            setSULab(ptr, lab);
            if (getLabType(lab) == EXT) setSWordAddressType(ptr, E_TYPE);
            else setSWordAddressType(ptr, R_TYPE);
        }
    } return res;
}
