#include "generalUtils.h"
#include "wordId.h"
#ifndef ASSEMBLER_PARSE_LINE_H
#define ASSEMBLER_PARSE_LINE_H
void labelFlagOnScenario(label **lab, label *labHead, label **labLst);
result entryScenario(char **line, char **word, sWord **instLst, label *labHead);
result extScenario(char **line, char **word, label *labHead, label **lab, label **labLst);
result lookForData(char **word, char **line, label **lab, label *labHead, label **labLst, sWord **instLst, sWord
**dataLst);
result lookForOperation(char **word, char **line, label **lab, label *labHead, label **labLst, sWord **sWordLst);
result lookForLabel(char **line, char **word);
#endif
