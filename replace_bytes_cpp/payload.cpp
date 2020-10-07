#include <iostream>
#include <stdlib.h>
#include <unistd.h>

#define NUMERO_DE_PING 4

void funcao(std::string ip, int porta) {
    for(register int i = 1; i <= NUMERO_DE_PING; i++) {
        printf("Ping %d: %s:%d\n", i, ip.c_str(), porta);
        sleep(1);
    }
}

int main(void) {

    const char *ip = "255.255.255.255"; /* IP */
    const char *port = "65535"; /* PORT */

    std::string str(ip);
    funcao(ip, atoi(port));

    return 0;
}
