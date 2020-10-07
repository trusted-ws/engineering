#include <iostream>
#include <cstring>
#include "binary.h"

#define OFFSET  0x3a55


int main(void) {

    const char *ip = "192.168.0.1:500";

    printf("My offset: %x\n", OFFSET);
    for(int i = OFFSET; i < OFFSET + 21; i++) {
        printf("0x%.02X\t", payload[i]);
    }
    
    std::cout << std::endl;

    for(int i = OFFSET; i < OFFSET + 21; i++) {
        printf("%c\t", payload[i]);
    }

    printf("\n\n");

    //std::stringstream stream;

    char newip[21];

    for(int i = 0; i < strlen(ip) + 1; i++) {
        
        newip[i] = (int)ip[i];
        //std::cout << "Char = " << str << std::endl;
        std::cout << "0x" << std::hex << (int) ip[i] << "\t";
    }

    std::cout << std::endl;

    for(int i = 0; i < strlen(ip) + 1; i++) {
        printf("%c\t", newip[i]);
    }


    return 0;
}
