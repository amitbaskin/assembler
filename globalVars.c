/* this file is used to declare the global variables used in this program */

#include "generalUtils.h"
int labelFlag = 0;
int errFlag = 0;
int instructionCounter = INITIAL_INSTRUCTION_NUM;
int dataCounter = 0;
int lineCounter = 0;
int ICF = 0; /* instruction counter final - used for adding to the addresses of the data items so they will be at
 * the end of the main output */
char *inputFileName = "\0";
char *curLine = "\0";
