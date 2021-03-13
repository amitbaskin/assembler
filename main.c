#include "assembler.h"

int main(int argc, char **args) {
    /* assemble the given file names given as arguments */
    while (--argc){
        assemble(*++args);
    } return 0;
}
