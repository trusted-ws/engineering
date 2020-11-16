/*
 * Simple program to patch an specific instruction 
 * in a binary.
 */ 

#include <stdio.h>
#include <cstring>
#include <stdlib.h>

#define OFFSET 0x11ab       /* Offset of instruction */
#define INSTRUCTION 0x74    /* JE (Jump if equal) */
#define REPLACE 0x75        /* JNE (Jump if not equal) */

signed main(int argc, char *argv[]) {

    if(argc != 2) {
        fprintf(stderr, "Please specify the binary!\n");
        return 1;
    }

    FILE *pFile = { 0 };
    char instruction[1] = { 0 };
    const char replace[1] = { INSTRUCTION };

    if((pFile = fopen(argv[1], "rb+"))) {

        fseek(pFile, OFFSET, SEEK_SET);
        fread(instruction, sizeof(char), 1, pFile);
        
        if(instruction[0] == REPLACE) {
            fseek(pFile, OFFSET, SEEK_SET);
            fwrite(replace, sizeof(char), sizeof(replace), pFile);
            printf("Patch sucessfully!\n");
        } else {
            printf("Instruction %#x isn't on this offset (%#x).\n", REPLACE, OFFSET);
        }
    } else {
        printf("Binary '%s' not found!\n", argv[1]);
    }

    return 0;
}
