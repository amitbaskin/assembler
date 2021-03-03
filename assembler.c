#include "assembler.h"
#include "wordId.h"
#include "sWordUtils.h"
#include "labUtils.h"
#include "firstParse.h"
#include "fileUtils.h"
#include "secParse.h"
#include "outputUtils.h"
#include "generalUtils.h"

result assemble(char *fName) {
    label *labLst;
    sWord *sWordLst;
    sWord *dataLst;
    FILE *fp;
    VALIDATE_FUNC_CALL(getNewEmptySword(&sWordLst), "")
    VALIDATE_FUNC_CALL(getNewEmptySword(&dataLst), "")
    VALIDATE_FUNC_CALL(getNewEmptyLabel(&labLst), "")
    VALIDATE_FUNC_CALL(getReadFile(fName, &fp), "")
    VALIDATE_FUNC_CALL(parseFile(fp, sWordLst, dataLst, labLst), "")
    VALIDATE_FUNC_CALL(parseInstLst(sWordLst, labLst), "")
    VALIDATE_FUNC_CALL(getMainOutputFIle(fName, &fp), "")
    printIntsLst(fp, sWordLst, labLst);
    printDataLst(fp, sWordLst);
    VALIDATE_FUNC_CALL(printEntLst(fName, labLst), "")
    VALIDATE_FUNC_CALL(printExtLst(fName, sWordLst), "")
    return SUCCESS;
}