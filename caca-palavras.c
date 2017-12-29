#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define TAM 30

void cacaPalavras_manual(char matriz[][TAM]) {
	int x, y;

	for (x = 0; x < TAM; x++) {
		for (y = 0; y < TAM; y++) {
			printf("Informe a letra do caça-palavras na posição [%d][%d]: ",x+1,y+1);
			scanf("%s",&matriz[x][y]);
		}
	}
}

void cacaPalavras_aleatorio(char matriz[][TAM]) {
	int x, y;

	srand(time(NULL));
    for (x = 0; x < TAM; x++) {
        for (y = 0; y < TAM; y++) {
	    	matriz[x][y] = 65 + (rand () % (122 - 65));

	    	if (matriz[x][y] >= 91 && matriz[x][y] <= 96) {
	    		while (matriz[x][y] >= 91 && matriz[x][y] <= 96) {
	    			matriz[x][y] = 65 + (rand () % (122 - 65));
	    		}
	    	}
        }
    }
}

int main () {

    char matriz[TAM][TAM];
    char k[TAM];
    int x, y, z, tam_k;
    int iguais, num_ocorrencia;
    int flag;
    int escolha;

    printf("Escolha uma opção abaixo: \n");
    printf("1 - Cadastrar o caça-palavras manualmente\n");
    printf("2 - Gerar um caça-palavras aleatorio\n");
    printf("Opção: ");
    scanf("%d",&escolha);

    switch (escolha) {
    	case 1: 
    		system("clear");
    		cacaPalavras_manual(matriz);
    		system("clear");
    	break;

    	case 2:
    		cacaPalavras_aleatorio(matriz);
    		system("clear");
    	break;

    	default:
    		system("clear");
    		printf("ERROR\n");
    		exit(0);
    }

    do {
    	num_ocorrencia = 0;
    	
    	printf("----------------------------------------------------------\n");
    	printf("                     CAÇA-PALAVRAS\n");
    	printf("----------------------------------------------------------\n\n");
    	for (x = 0; x < TAM; x++) {
        	for (y = 0; y < TAM; y++) {
        		printf("%c ",matriz[x][y]);
 	       }
 	       printf("\n");
    	}

    	printf("\n----------------------------------------------------------\n");
    	printf("Informe a palavra que você quer procurar no caça-palavras: ");
    	scanf(" %[^\n]s",k);
    	tam_k = strlen(k);

    	for (x = 0; x < TAM; x++) {
        	for (y = 0; y < TAM; y++) {
	    		iguais = 0;
            	for (z = 0; z < tam_k; z++) {
               	 	if (z == 0) {
                  		if (matriz[x][y] == k[z]) {
		       	 			iguais++;
                   		}
               		} else {
                    	if (matriz[x][y+z] == k[z]) {
							iguais++;
                   	    }
                	}
            	}
            
	    		if (iguais == tam_k) {
					num_ocorrencia++;
        		}
        	}
    	}

    	for (y = 0; y < TAM; y++) {
        	for (x = 0; x < TAM; x++) {
	    		iguais = 0;
            	for (z = 0; z < tam_k; z++) {
                 	if (z == 0) {
                    	if (matriz[x][y] == k[z]) {
		        			iguais++;
                    	}
                	} else {
                    	if (matriz[x+z][y] == k[z]) {
							iguais++;
                    	}
                	}
            	}
            
	    		if (iguais == tam_k) {
					num_ocorrencia++;
            	}
        	}
    	}

    	

    	printf("\nO caça-palavras possui %d ocorrências da palavra %s.\n",num_ocorrencia,k);

    	printf("\n----------------------------------------------------------\n\n");

    	printf("Quer procurar outra palavra no caça-palavras ?\n");
    	printf("1 - Sim\n");
    	printf("2 - Não\n");
    	printf("Opção: ");
    	scanf("%d",&flag);

    	system("clear");
    } while (flag != 2);

    printf("----------------------------------------------------------\n");
    printf("                         FIM\n");
    printf("----------------------------------------------------------\n\n");
    
    return 0;
}