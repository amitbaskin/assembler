#include "assembler.h"
#include "wordId.h"
#include "sWordUtils.h"
#include "labUtils.h"
#include "firstParse.h"
#include "fileUtils.h"
#include "secParse.h"
#include "outputUtils.h"
#include "generalUtils.h"
#include "sWordListUtils.h"
#include "labLstUtils.h"

result assemble(char *fName) {
    labelLst *labLst = NULL;
    sWordLst *instLst = NULL;
    sWordLst *dataLst = NULL;
    FILE *fp;
    VALIDATE_FUNC_CALL(initializeSWordLst(instLst), "")
    VALIDATE_FUNC_CALL(initializeSWordLst(dataLst), "")
    VALIDATE_FUNC_CALL(initializeLabLst(labLst), "")
    VALIDATE_FUNC_CALL(getReadFile(fName, &fp), "")
    VALIDATE_FUNC_CALL(parseFile(fp, instLst, dataLst, labLst), "")
    VALIDATE_FUNC_CALL(parseInstLst(instLst, labLst), "")
    VALIDATE_FUNC_CALL(getMainOutputFIle(fName, &fp), "")
    printIntsLst(fp, instLst, labLst);
    printDataLst(fp, instLst);
    VALIDATE_FUNC_CALL(printEntLst(fName, labLst), "")
    VALIDATE_FUNC_CALL(printExtLst(fName, instLst), "")
    freeLabLst(labLst);
    freeSWordLst(instLst);
    freeSWordLst(dataLst);
    return SUCCESS;
}