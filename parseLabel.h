#include <string.h>
#include "generalUtils.h"
#include "machineWordIdentifiers.h"
#ifndef ASSEMBLER_PARSE_LABEL_H
#define ASSEMBLER_PARSE_LABEL_H
result isLabelScenario(char **line, char **word, label **lab, unsigned long len);
result setLabelScenario(label *head, label *lab, label **labLst, void setter(label *));
#endif