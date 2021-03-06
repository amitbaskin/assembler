#include "secParse.h"
#include "generalUtils.h"
#include "sWordSetters.h"
#include "labUtils.h"
#include "labSetters.h"
#include "sWordGetters.h"
#include "labLstUtils.h"
#include "sWordListUtils.h"

result parseInstLst(sWordLst *instLst, labelLst *labLst){
    label *lab;
    result res = SUCCESS;
    sWord *ptr;
    while ((ptr = getSWordIterNext(instLst)) != NULL && getSWordStatus(ptr) != W_NONE){
        switch (getSWordStatus(ptr)) {
            case W_ENT:
                if (isLabInLst(labLst, &lab, L_ENT, getSULabName(ptr)) == FALSE) {
                    res = ERR;
                    printf("");
                    continue;
                } setLabType(lab, L_ENT);
                setThisSWord(&ptr, getSWordNext(ptr));

            case LAB:
                if (isLabInLst(labLst, &lab, L_NONE, getSULabName(ptr)) == FALSE) {
                    res = ERR;
                    printf("");
                    continue;
                } setSULab(ptr, lab);
                setThisSWord(&ptr, getSWordNext(ptr));
                break;

            default:
                setThisSWord(&ptr, getSWordNext(ptr));
        }
    } return res;
}
