#include <string.h>
#include "strData.h"
#include "parseLineUtils.h"
#include "generalUtils.h"
#include "wordIdentifiers.h"
#include "sWordSetters.h"
#include "parseLabel.h"
#include "labelUtils.h"

result isStrScenario(char **line, char *word, sWord **sWordLst, label *head, label *lab, label **labLst){
    result res;
    if (isStringOrder(word) == FALSE) return FALSE;
    res = getWord(line, &word, 0);
    if (isString(word) == FALSE) return ERR;
    if (res != LINE_END) res = finishLine(line);
    if (res == ERR) return ERR;
    strScenario(word, sWordLst, head, lab, labLst);
    return SUCCESS;
}

void strScenario(char *str, sWord **sWordLst, label *head, label *lab, label **labLst){
    unsigned long len = strlen(str);
    int i;
    char chr;
    if (labelFlag) {
        addLabToLabLst(head, &lab, labLst, NONE, dataCounter++);
        setDataLabel(lab);
    } for (i=1; i<len-1; i++){
        chr = str[i];
        addChrWord(chr, sWordLst);
    }
}

