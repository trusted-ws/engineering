#include <stdio.h>
#include <iostream>

#define FILENAME "file.txt"     /* Filename of binary */
#define OFFSET 0x32             /* Offset of instruction to replace */

int main(void) {

    const char buffer[2] = { 0x30, 0x30 };
    char fileBuffer[2] = { 0 };
    FILE *pFile;

    pFile = fopen(FILENAME, "rb+");

    fseek(pFile, OFFSET, SEEK_SET);
    fread(fileBuffer, sizeof(char), 2, pFile);
    fseek(pFile, OFFSET, SEEK_SET);

    if(fileBuffer[0] != 0x35 && fileBuffer[1] != 0x35) {
        fprintf(stderr, "Bytes don't match with 0x35 at this offset (%#x)\n", OFFSET);
    } else {
        printf("Bytes at offset %#x is: '%c' and '%c' and 'll be replaced with '%c' and '%c'...\n", OFFSET, fileBuffer[0], fileBuffer[1], buffer[0], buffer[1]);
        fwrite(buffer, sizeof(char), sizeof(buffer), pFile);

        fseek(pFile, OFFSET, SEEK_SET);
        fread(fileBuffer, sizeof(char), 2, pFile);
        printf("New bytes at offset %#x are: '%c' and '%c'.\n", OFFSET, fileBuffer[0], fileBuffer[1]);
    }

    fclose(pFile);

    return 0;
}
