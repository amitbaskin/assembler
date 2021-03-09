#include <string.h>
#include "strData.h"
#include "parseLineUtils.h"
#include "generalUtils.h"
#include "wordId.h"
#include "sWordSetters.h"
#include "labUtils.h"
#include "parseLine.h"
#include "labLstUtils.h"
#include "labSetters.h"
#include "sWordListUtils.h"

extern int labelFlag;
extern int dataCounter;

result isStrScenario(char *word, char **line, label *lab, sWordLst *dataLst, labelLst *labLst){
    if (isStringOrder(word) == FALSE) return FALSE;
    if (getWord(line, &word, 0) != LINE_END) VALIDATE_VAL(finishLine(line), "");
    if (isString(word) == FALSE) return ERR;
    strScenario(word, lab, labLst, dataLst);
    return SUCCESS;
}

void strScenario(char *str, label *lab, labelLst *labLst, sWordLst *instLst){
    unsigned long len = strlen(str);
    int i;
    char chr;
    if (labelFlag) {
        checkLabFlagOnScenario(&lab, labLst, setLabCode, dataCounter++);
    } for (i=1; i<len-1; i++){
        chr = str[i];
        addChrWord(chr, instLst);
    }
}
