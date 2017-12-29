#include <stdio.h>
#include <stdlib.h>

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

	int num, exp_primo = 1;

	printf("Informe o numero: ");
	scanf("%d",&num);
	system("clear");

	if (num > 1) {
		printf("%d = ",num);
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
		printf("Fatoração não é possivel para o numero %d!\n\n",num);
	}

	return 0;
}