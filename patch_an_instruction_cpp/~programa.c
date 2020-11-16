#include <stdio.h>
#include <string.h>

#define SENHA "chewbacca"


signed main(void) {

    const char senha[32];
    
    printf("Digite a senha: ");
    scanf("%s", &senha);

    if(strcmp(senha, SENHA) == 0) {
        printf("Senha correta!\n");
    } else {
        printf("Senha incorreta!\n");
    }


    return 0;
}
