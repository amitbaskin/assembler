/* this file is used to run the general flow of the assembler */

#include "labUtils.h"
#include "firstParse.h"
#include "fileUtils.h"
#include "secParse.h"
#include "outputUtils.h"
#include "sWordListUtils.h"
#include "labLstUtils.h"
#include "labGetters.h"
#include "labSetters.h"
#include "globalVars.h"


void updateDataLabsAddresses(labelLst *labLst){
    /* add ICF (instruction counter final) to each address in the data image so that the data image will be at the
     * end of the output */
    label *ptr;
    for (ptr = getLabTail(labLst); ptr != NULL; promoteLab(&ptr)) {
        if (isLabData(ptr)) setLabAddress(ptr, getLabAddress(ptr) + getIcf());
    }
}

result assembleHelper(char *fName){
    /* run the entire flow of processing an assembly input, and output the requested files.
     * returns SUCCESS unless an error occurred in the process */
    labelLst *labLst = NULL;
    sWordLst *instLst = NULL;
    sWordLst *dataLst = NULL;
    FILE *fp;
    initGlobalVars();
    setInputFileName(fName);
    VALIDATE_VAL(initSWordLst(&instLst))
    VALIDATE_VAL(initSWordLst(&dataLst))
    VALIDATE_VAL(initLabLst(&labLst))
    VALIDATE_VAL(getReadFile(fName, &fp))
    VALIDATE_VAL(parseFile(fp, instLst, dataLst, labLst))
    if (getErrFlag()) return ERR; /* handled already */
    updateDataLabsAddresses(labLst);
    VALIDATE_VAL(parseInstLst(instLst, labLst))
    if (getErrFlag()) return ERR; /* handled already */
    VALIDATE_VAL(getMainOutputFile(fName, &fp))
    printInstLst(fp, instLst, labLst);
    printDataLst(fp, dataLst);
    VALIDATE_VAL(printEntFile(labLst, fName))
    VALIDATE_VAL(printExtLst(fName, instLst))
    freeSWordLst(instLst);
    freeSWordLst(dataLst);
    freeLabLst(labLst);
    VALIDATE_VAL(closeFile(fp)) /* err handled inside if one occurs */
    return SUCCESS;
}

result assemble(char *fName) {
    /* first remove old files if exist (some or all may not be created again) and then run the assembler */
    removeFile(getFullFileName(fName, MAIN_OUTPUT_SUFFIX));
    removeFile(getFullFileName(fName, ENT_SUFFIX));
    removeFile(getFullFileName(fName, EXT_SUFFIX));
    return assembleHelper(fName);
}
