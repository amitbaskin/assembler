#ifndef ASSEMBLER_GLOBAL_VARS_H
#define ASSEMBLER_GLOBAL_VARS_H
int getLabelFlag();
int getErrFlag();
int getInstructionCounter();
int getDataCounter();
int getLineCounter();
int getIcf();
char *getInputFileName();
char *getCurLine();
void raiseLabelFlag();
void raiseErrFlag();
void updateInstructionCounter();
void updateDataCounter();
void updateLineCounter();
void setCurLine(char *line);
void setInputFileName(char *name);
void setIcf(int final);
void initGlobalVars();
void resetLabelFlag();
void resetErrFlag();
#endif
