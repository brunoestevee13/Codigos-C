#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

int verif_primo(int *num) {
	int div;
	int cont;

	do {
		*num = *num + 1;
		div = 0;
		for (cont = 1; cont <= *num; cont++) {
			if (*num % cont == 0) {
				div++;
			}
		}

		if (div == 2) {
			return 0;
		}
	} while (1);
}

int main () {

	int num, exp_primo;
	char flag;

	do {
		exp_primo = 1;
		printf("Informe o numero: ");
		scanf("%d",&num);
		system("cls");

		if (num > 1) {
			printf("Numero fatorado :");
			printf("\n\n\t\t\t%d = ",num);
			do {
				verif_primo(&exp_primo);

				if (num % exp_primo == 0) {
					while (num % exp_primo == 0) {
						if (num / exp_primo == 1) {
							printf("%d\n\n",exp_primo);
						} else {
							printf("%d x ",exp_primo);
						}
						num /= exp_primo;
					}
				}
			} while (num > 1);
		} else {
			printf("Fatora%c%co n%co %c possivel para o numero %d!\n\n",135,132,132,130,num);
		}

		printf(" _________________________________________________________________\n");
		printf("|                                                                 |\n");
		printf("|Aperte ENTER para ver outro numero fatorado ou aperte S para sair|\n");
		printf("|_________________________________________________________________|\n");
		flag = getch();

		if ((int)(toupper(flag)) == 83) {
			return 0;
		} else {
			system("cls");
		}

	} while (1);

	return 0;
}
