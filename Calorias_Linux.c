#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

void init_attr(struct termios *old_attr,struct termios *new_attr);
int getch();

void cabecalho() {
	system("clear");
	printf(" _______________________________________________________________________\n");
	printf("|   ****************************************************************    |\n");
	printf("|   ****************** Calculadora de calorias *********************    |\n");
	printf("|   ****************************************************************    |\n");
	printf("|_______________________________________________________________________|\n");
}

int calculadora() {

	int idade, grau_ativ;
	char nome[50], flag, sexo;
	float altura, peso;
	float taxa_metab_basal, caloria_recom;

	do {
		cabecalho();
		printf("\n\nEscolha o sexo da pessoa\n");
		printf("[1] - Homem\n");
		printf("[2] - Mulher\n\n");
		printf("Digite o numero de acordo com sua escolha ou digite enter para voltar");
		sexo = getch();
		setbuf(stdin,NULL);

		switch (sexo) {
			case 49:
				cabecalho();
				printf("\n\nInforme o nome da pessoa: ");
				scanf(" %[^\n]s",nome);
				setbuf(stdin,NULL);

				cabecalho();
				printf("\n\nInforme a idade: ");
				scanf("%d",&idade);

				cabecalho();
				printf("\n\nInforme a altura: ");
				scanf("%f",&altura);

				cabecalho();
				printf("\n\nInforme o peso: ");
				scanf("%f",&peso);

				taxa_metab_basal = ((66.0 + (13.7 * peso)) + (5.0 * altura) - (6.76 * idade));

				cabecalho();
				setbuf(stdin,NULL);
				printf("\n\nInforme o seu grau de atividade diario\n\n");
				printf("[1] - Sedentário (Pouco ou nenhum exercicio + desk job)\n");
				printf("[2] - Pouco ativo (Pouco ativo no dia-a-dia & exercicios lights 1-3 dias por semana\n");
				printf("[3] - Moderamente ativo (Moderadamente ativo no dia-a-dia & exercicios em intensidade moderada 3-5 dias por semana)\n");
				printf("[4] - Muito ativo (Estilo de vida que exige esforco bruto & Exercicio intenso ou reliza algum esporte 6-7 dias por semana)\n\n");
				printf("Digite o numero de acordo com sua escolha");
				grau_ativ = getch();
				setbuf(stdin,NULL);

				switch (grau_ativ) {
					case 49:
						caloria_recom = taxa_metab_basal * 1.2;
						cabecalho();
						printf("\n\n\tNome: %s\tIdade: %d\n",nome,idade);
						printf("\tAltura: %.2f\tPeso: %.1f\n",altura,peso);
						printf("\tGasto de caloria diário: %.2f\n",caloria_recom);

		 				printf("\n----------------------------------------------------------------------\n");
		 				printf("Aperte qualquer tecla para usar a calculadora novamente ou S para sair\n");
		 				printf("----------------------------------------------------------------------\n");
		 				flag = getch();
		 				setbuf(stdin,NULL);
		 				if (flag == 83 || flag == 115) {
		 					return 0;
		 				}
					break;

					case 50:
						caloria_recom = taxa_metab_basal * 1.4;
						cabecalho();
						printf("\n\n\tNome: %s\tIdade: %d\n",nome,idade);
						printf("\tAltura: %.2f\tPeso: %.1f\n",altura,peso);
						printf("\tGasto de caloria diário: %.2f\n",caloria_recom);

		 				printf("\n----------------------------------------------------------------------\n");
		 				printf("Aperte qualquer tecla para usar a calculadora novamente ou S para sair\n");
		 				printf("----------------------------------------------------------------------\n");
		 				flag = getch();
		 				setbuf(stdin,NULL);
		 				if (flag == 83 || flag == 115) {
		 					return 0;
		 				}
					break;

					case 51:
						caloria_recom = taxa_metab_basal * 1.6;
						cabecalho();
						printf("\n\n\tNome: %s\tIdade: %d\n",nome,idade);
						printf("\tAltura: %.2f\tPeso: %.1f\n",altura,peso);
						printf("\tGasto de caloria diário: %.2f\n",caloria_recom);

		 				printf("\n----------------------------------------------------------------------\n");
		 				printf("Aperte qualquer tecla para usar a calculadora novamente ou S para sair\n");
		 				printf("----------------------------------------------------------------------\n");
		 				flag = getch();
		 				setbuf(stdin,NULL);
		 				if (flag == 83 || flag == 115) {
		 					return 0;
		 				}
					break;

					case 52:
						caloria_recom = taxa_metab_basal * 1.8;
						cabecalho();
						printf("\n\n\tNome: %s\tIdade: %d\n",nome,idade);
						printf("\tAltura: %.2f\tPeso: %.1f\n",altura,peso);
						printf("\tGasto de caloria diário: %.2f\n",caloria_recom);

		 				printf("\n----------------------------------------------------------------------\n");
		 				printf("Aperte qualquer tecla para usar a calculadora novamente ou S para sair\n");
		 				printf("----------------------------------------------------------------------\n");
		 				flag = getch();
		 				setbuf(stdin,NULL);
		 				if (flag == 83 || flag == 115) {
		 					return 0;
		 				}
					break;

					default:
						cabecalho();
						printf("\n\nInválido !!!");

						printf("\n----------------------------------------------------------------------\n");
		 				printf("Aperte qualquer tecla para usar a calculadora novamente ou S para sair\n");
		 				printf("----------------------------------------------------------------------\n");
		 				flag = getch();
		 				setbuf(stdin,NULL);
		 				if (flag == 83 || flag == 115) {
		 					return 0;
		 				}
		 			break;

				}
			break;

			case 50:
				cabecalho();
				printf("\n\nInforme o nome da pessoa: ");
				scanf(" %[^\n]s",nome);
				setbuf(stdin,NULL);

				cabecalho();
				printf("\n\nInforme a idade: ");
				scanf("%d",&idade);

				cabecalho();
				printf("\n\nInforme a altura: ");
				scanf("%f",&altura);

				cabecalho();
				printf("\n\nInforme o peso: ");
				scanf("%f",&peso);

				taxa_metab_basal = ((655.0 + (9.6 * peso)) + (1.8 * altura) - (4.7 * idade));

				cabecalho();
				printf("\n\nInforme o seu grau de atividade diario\n\n");
				printf("[1] - Sedentário (Pouco ou nenhum exercicio + desk job)\n");
				printf("[2] - Pouco ativo (Pouco ativo no dia-a-dia & exercicios lights 1-3 dias por semana\n");
				printf("[3] - Moderamente ativo (Moderadamente ativo no dia-a-dia & exercicios em intensidade moderada 3-5 dias por semana)\n");
				printf("[4] - Muito ativo (Estilo de vida que exige esforco bruto & Exercicio intenso ou reliza algum esporte 6-7 dias por semana)\n\n");
				printf("Digite o numero de acordo com sua escolha");
				grau_ativ = getch();
				setbuf(stdin,NULL);

				switch (grau_ativ) {
					case 49:
						caloria_recom = taxa_metab_basal * 1.2;
						cabecalho();
						printf("\n\n\tNome: %s\tIdade: %d\n",nome,idade);
						printf("\tAltura: %.2f\tPeso: %.1f\n",altura,peso);
						printf("\tGasto de caloria diário: %.2f\n",caloria_recom);

		 				printf("\n----------------------------------------------------------------------\n");
		 				printf("Aperte qualquer tecla para usar a calculadora novamente ou S para sair\n");
		 				printf("----------------------------------------------------------------------\n");
		 				flag = getch();
		 				setbuf(stdin,NULL);
		 				if (flag == 83 || flag == 115) {
		 					return 0;
		 				}
					break;

					case 50:
						caloria_recom = taxa_metab_basal * 1.4;
						cabecalho();
						printf("\n\n\tNome: %s\tIdade: %d\n",nome,idade);
						printf("\tAltura: %.2f\tPeso: %.1f\n",altura,peso);
						printf("\tGasto de caloria diário: %.2f\n",caloria_recom);

		 				printf("\n----------------------------------------------------------------------\n");
		 				printf("Aperte qualquer tecla para usar a calculadora novamente ou S para sair\n");
		 				printf("----------------------------------------------------------------------\n");
		 				flag = getch();
		 				setbuf(stdin,NULL);
		 				if (flag == 83 || flag == 115) {
		 					return 0;
		 				}
					break;

					case 51:
						caloria_recom = taxa_metab_basal * 1.6;
						cabecalho();
						printf("\n\n\tNome: %s\tIdade: %d\n",nome,idade);
						printf("\tAltura: %.2f\tPeso: %.1f\n",altura,peso);
						printf("\tGasto de caloria diário: %.2f\n",caloria_recom);

		 				printf("\n----------------------------------------------------------------------\n");
		 				printf("Aperte qualquer tecla para usar a calculadora novamente ou S para sair\n");
		 				printf("----------------------------------------------------------------------\n");
		 				flag = getch();
		 				setbuf(stdin,NULL);
		 				if (flag == 83 || flag == 115) {
		 					return 0;
		 				}
					break;

					case 52:
						caloria_recom = taxa_metab_basal * 1.8;
						cabecalho();
						printf("\n\n\tNome: %s\tIdade: %d\n",nome,idade);
						printf("\tAltura: %.2f\tPeso: %.1f\n",altura,peso);
						printf("\tGasto de caloria diário: %.2f\n",caloria_recom);

		 				printf("\n----------------------------------------------------------------------\n");
		 				printf("Aperte qualquer tecla para usar a calculadora novamente ou S para sair\n");
		 				printf("----------------------------------------------------------------------\n");
		 				flag = getch();
		 				setbuf(stdin,NULL);
		 				if (flag == 83 || flag == 115) {
		 					return 0;
		 				}
					break;

					default:
						cabecalho();
						printf("\n\nInvalido !!!");

						printf("\n----------------------------------------------------------------------\n");
		 				printf("Aperte qualquer tecla para usar a calculadora novamente ou S para sair\n");
		 				printf("----------------------------------------------------------------------\n");
		 				flag = getch();
		 				setbuf(stdin,NULL);
		 				if (flag == 83 || flag == 115) {
		 					return 0;
		 				}
		 			break;
				}
			break;

			case 13:
				return 0;
			break;
		}
	} while (1);
}

int main () {

	char opt;

	do {
		system("clear");
		printf(" _______________________________________________________________________\n");
		printf("|   ****************************************************************    |\n");
		printf("|   ****************** Calculadora de calorias *********************    |\n");
		printf("|   ****************************************************************    |\n");
		printf("|                                                                       |\n");
		printf("|                       [1] Abrir calculadora                           |\n");
		printf("|                       [2] Créditos                                    |\n");
		printf("|                       [3] Sair                                        |\n");
		printf("|_______________________________________________________________________|\n");
		opt = getch();
		setbuf(stdin,NULL);
		system("clear");

		switch (opt) {
			case 49:
				calculadora();
			break;

			case 50:
				printf(" _______________________________________________________________________\n");
				printf("|  *******************************************************************  |\n");
				printf("|  ************** Created by Bruno Esteves de Paula ******************  |\n");
				printf("|  *******************************************************************  |\n");
				printf("|                                                     Copyright© 2017   |\n");
				printf("|_______________________________________________________________________|\n\n");
				printf(" Pressione qualquer tecla para retornar");
				getch();
				setbuf(stdin,NULL);
			break;

			case 51:
				exit(0);
			break;
		} 
	} while (1);

	return 0;
}

void init_attr(struct termios *old_attr,struct termios *new_attr)
{
    tcgetattr(0,&*old_attr);

    *new_attr=*old_attr;
    new_attr->c_lflag &=~ICANON;
    new_attr->c_cc[VMIN]=1;
    new_attr->c_cc[VTIME]=0;
}

int getch()
{
   struct termios old_attr, new_attr;
   int c;

   init_attr(&old_attr,&new_attr);

   new_attr.c_lflag &=~ECHO;

   tcsetattr(STDIN_FILENO,TCSANOW,&new_attr);

   c = getchar();

   tcsetattr(STDIN_FILENO,TCSANOW,&old_attr);

   return c;
}