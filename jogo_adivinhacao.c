#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <curses.h>

bool verificador_flag() {
	int x;

	printf("\n-----------------------------------------------------------\n");
	printf("Presione enter para procurar outro numero ou S para sair\n");
	printf("-----------------------------------------------------------\n");
	x = getchar();

	if (x == 10) {
		return true;
	} else {
		return false;
	}
}

void mensagem_FIM() {
	system("clear");
	printf("\n-----------------------------------------------------------\n");
	printf("                           FIM\n");
	printf("-----------------------------------------------------------\n\n");
}

int main () {

	int num_sorteado, num_informado;
	int aux;

	srand(time(NULL));
	num_sorteado = 1 + (rand () % (100 - 1));

	do {
		system("clear");
		printf("--------------------------------------------------\n\n");
		printf("              Jogo de adivinhação\n\n");
		printf("--------------------------------------------------\n\n");

		printf("Informe o numero que acha que foi sorteado: ");
		scanf("%d",&num_informado);

		aux = num_sorteado - num_informado;
		setbuf(stdin,NULL);

		if (aux > 0 && aux <= 5) {
			printf("\nNão é esse número, mas está proximo um valor um pouco acima de %d.\n\n",num_informado);
			if (verificador_flag() == true) {
				system("clear");
			} else {
				mensagem_FIM();
				num_informado = num_sorteado;
			}
		} else {
			if (aux < 0 && aux >= -5) {
				printf("\nNão é esse número, mas está proximo um valor um pouco abaixo de %d.\n\n",num_informado);
				if (verificador_flag() == true) {
					system("clear");
				} else {
					mensagem_FIM();
					num_informado = num_sorteado;
				}
			} else {
				if (num_informado != num_sorteado) {
					printf("\nNão é esse numero !\n\n");
					if (verificador_flag() == true) {
						system("clear");
					} else {
						mensagem_FIM();
						num_informado = num_sorteado;
					}
				} else {
					if (num_informado == num_sorteado) {
						printf("\nAcertou, você ganhou !!!\n\n");
					}
				}
			}
		}


	} while (num_informado != num_sorteado);

	return 0;
}