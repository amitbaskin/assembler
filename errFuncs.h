#ifndef ASSEMBLER_ERR_FUNCS_H
#define ASSEMBLER_ERR_FUNCS_H
void allocErr();
void openFileErr();
void lineTooLongErr();
void labTooLongErr();
void illegalChrErr();
void labClashErr();
void relLabErr();
void lineEndErr();
void lineNotEndErr();
void nonStrDataErr();
void nonNumericDataErr();
void imNumNoDataErr();
void noNumPrefixErr();
void noSepAfterFirstOperand();
void sepErr();
void operandErr();
void undefinedStatementErr();
void keyWordErr(const char *keyWord);
void emptyLabelErr();
void illegalLabTypeErr(char *labName);
void useOfUndefinedLabErr(char *labName);
#endif
