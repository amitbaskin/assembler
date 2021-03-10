#ifndef ASSEMBLER_ERR_FUNCS_H
#define ASSEMBLER_ERR_FUNCS_H
void allocErr();
void dataNumErr();
void openFileErr();
void lineTooLongErr();
void illegalChrErr();
void illegalLabTypeErr();
void labClashErr();
void relLabErr();
void lineEndErr();
void lineNotEndErr();
void notStrErr();
void notNumErr();
void sepErr();
void operandErr();
void undefinedStatementErr();
void keyWordErr(const char *keyWord);
#endif
