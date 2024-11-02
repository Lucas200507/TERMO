#include <stdio.h>
#include <string.h>



int main(){
    char palavra[] = {"uva"};
    char digitado[4];
    int correto, tentativas = 1;
    char Lcorretas[20] = {""}; // Letras corretas em posições diferentes
    char Lincorretas[20] = {""}; // Letras incorretas
    char Lposicao[10] = {""}; // Letras corretas em posições iguais
    char aux[] = {" - "};
    
    
    correto = 0;

    while(correto == 0 && tentativas <= 5){
        //Reinicializa as strings a cada nova palavra inserida
        strcpy(Lcorretas, "");
        strcpy(Lincorretas, "");
        strcpy(Lposicao, "");

        printf("Digite uma palavra com '3' letras:\n");
        fgets(digitado, sizeof(digitado), stdin);

        // Remove o caractere de nova linha do final de 'digitado'
        digitado[strcspn(digitado, "\n")] = '\0';
        palavra[strcspn(palavra, "\n")] = '\0';
        //VERIFICAÇÃO DO TAMANHO DA PALAVRA
        if (strlen(digitado) > strlen(palavra)){
            printf("A palavra digitada possui mais de 3 caracteres, digite novamente.\n");
            continue;
        } else if(strlen(digitado) < strlen(palavra)){
            printf("A palavra digitada possui menos de 3 caracteres, digite novamente.\n");
            continue;
        }


        //VERIFICAÇÃO DA PALAVRA
        if (strcmp(palavra, digitado) == 0){
            printf("-----------------------------------------------------\n");
            printf("               A PALAVRA ESTÁ CORRETA!                \n");
            printf("-----------------------------------------------------\n");
            correto = 1;
        } else {

            int tamanho_palavra =  strlen(palavra);

            for (int i = 0; i < tamanho_palavra; i++) {
                char temp[2] = {digitado[i], '\0'};  // Temporário para a letra atual

                if (palavra[i] == digitado[i]) {
                    strcat(Lposicao, temp);
                    strcat(Lposicao, aux);
                } else {
                    int achou = 0;
                    // Verifica se a letra existe na palavra, mas em outra posição
                    for (int j = 0; j < tamanho_palavra; j++) {
                        if (palavra[j] == digitado[i]) {
                            achou = 1;
                            break;
                        }
                    }
                    if (achou) {
                        strcat(Lcorretas, temp);
                        strcat(Lcorretas, aux);
                    } else {
                        strcat(Lincorretas, temp);
                        strcat(Lincorretas, aux);
                    }
                }
            }

            printf("-----------------------------------------------------\n");
            printf("As letras nas posições corretas são: %s\n", Lposicao);
            printf("As letras corretas são: %s\n", Lcorretas);
            printf("As letras incorretas são: %s\n", Lincorretas);
            tentativas++;
            printf("-----------------------------------------------------\n");

        } 
        

        

    }


    if (correto == 0) {
        printf("Número máximo de tentativas alcançado. A palavra correta era '%s'.\n", palavra);
    }
    
    return 0;
}