#ifndef ASSEMBLER_ERR_FUNCS_H
#define ASSEMBLER_ERR_FUNCS_H
void allocErr();
void openFileErr();
void lineTooLongErr();
void labTooLongErr();
void illegalChrErr();
void illegalLabTypeErr();
void labClashErr();
void relLabErr();
void lineEndErr();
void lineNotEndErr();
void nonStrDataErr();
void nonNumericDataErr();
void sepErr();
void operandErr();
void undefinedStatementErr();
void keyWordErr(const char *keyWord);
void emptyLabelErr();
#endif
