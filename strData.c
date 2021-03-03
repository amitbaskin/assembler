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

result isStrScenario(char **line, char *word, sWord **sWordLst, label *head, label *lab, label **labLst){
    if (isStringOrder(word) == FALSE) return FALSE;
    if (getWord(line, &word, 0) != LINE_END) VALIDATE_FUNC_CALL(finishLine(line), "");
    if (isString(word) == FALSE) return ERR;
    strScenario(word, sWordLst, head, lab, labLst);
    return SUCCESS;
}

void strScenario(char *str, sWord **sWordLst, label *head, label *lab, label **labLst){
    unsigned long len = strlen(str);
    int i;
    char chr;
    if (labelFlag) {
        addLabToLabLst(head, &lab, labLst, NONE, dataCounter++);
        setDataLab(lab);
    } for (i=1; i<len-1; i++){
        chr = str[i];
        addChrWord(chr, sWordLst);
    }
}
