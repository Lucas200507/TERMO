#include <stdio.h>
#include <string.h>
#include <locale.h>


int main(){
    char palavra[] = {"uva"};
    char digitado[4];
    int correto, tentativas = 1, i, j, achou;
    char Lcorretas[20] = ""; // Letras corretas em posi��es diferentes
    char Lincorretas[20] = ""; // Letras incorretas
    char Lposicao[10] = ""; // Letras corretas em posi��es iguais
    char aux[] = {" - "};
    
    setlocale(LC_ALL, "Portuguese");
    
    correto = 0;

    while(correto == 0 && tentativas <= 5){
    	printf("FASE 1\n");
    	printf("Tentiva: %d\n", tentativas);
        //Reinicializa as strings a cada nova palavra inserida
        strcpy(Lcorretas, "");
        strcpy(Lposicao, "");

        printf("Digite uma palavra com '3' letras:\n");
        scanf(" %s", &digitado);
        

        // Remove o caractere de nova linha do final de 'digitado'
        digitado[strcspn(digitado, "\n")] = '\0';
        
        //VERIFICA��O DO TAMANHO DA PALAVRA
        if (strlen(digitado) > strlen(palavra)){
            printf("A palavra digitada possui mais de 3 caracteres, digite novamente.\n");
            continue;
        } else if(strlen(digitado) < strlen(palavra)){
            printf("A palavra digitada possui menos de 3 caracteres, digite novamente.\n");
            continue;
        }


        //VERIFICA��O DA PALAVRA
        if (strcmp(palavra, digitado) == 0){
            printf("-----------------------------------------------------\n");
            printf("               A PALAVRA EST� CORRETA!                \n");
            printf("-----------------------------------------------------\n");
            correto = 1;
        } else {
        	
        	int tamanho_palavra = strlen(palavra);
        	
			for (i = 0; i < tamanho_palavra; i++) {
                char temp[2] = {digitado[i], '\0'};  // Tempor�rio para a letra atual
                temp[strcspn(temp, "\n")] = '\0';
                
                if (palavra[i] == digitado[i]) {
                    strcat(Lcorretas, temp);
                    strcat(Lcorretas, aux);
                    Lposicao[i] = digitado[i];
                } else {
                	Lposicao[i] = '_';
                    achou = 0;
                    // Verifica se a letra existe na palavra, mas em outra posi��o
                    for (j = 0; j < tamanho_palavra; j++) {
                    	
                        if (palavra[i] == digitado[j]) {
                            achou = 1;
                            
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
            printf("As letras nas posi��es corretas s�o: \n");
            printf("\n                    %s                \n\n", Lposicao);
            printf("As letras corretas s�o: %s\n", Lcorretas);
            printf("As letras incorretas s�o: %s\n", Lincorretas);
            tentativas++;
            printf("-----------------------------------------------------\n");

        } 

    }


    if (correto == 0) {
        printf("N�mero m�ximo de tentativas alcan�ado. A palavra correta era '%s'.\n", palavra);
    }
    
    return 0;
}
