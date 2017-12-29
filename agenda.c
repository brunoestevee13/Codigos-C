#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <termios.h>
#define TAM 100

void init_attr(struct termios *old_attr,struct termios *new_attr);
int getch();

struct endereco {
    char rua[50];
    int numero;
    char complemento[100];
    char bairro[50];
    int cep;
    char cidade[50];
    char estado[50];
    char pais[50];
};

struct telefone {
    int DDD;
    int numero;
};

struct data_aniversario {
    int dia;
    int mes;
    int ano;
};

typedef struct {
    char nome[60];
    char email[70];
    struct endereco ender;
    struct telefone tel;
    struct data_aniversario dat;
    char observacao[120];
} pessoa;

void ordenacao(pessoa *agenda) {
	int x, y;
	pessoa aux;

	for (x = 0; x < (TAM - 1); x++) {
		for (y = (x + 1); y < TAM; y++) {
			if (agenda[y].nome[0] < agenda[x].nome[0] && agenda[y].nome[0] != 0) {
				aux = agenda[y];
				agenda[y] = agenda[x];
				agenda[x] = aux;
			}
		}
	}
}

int inserir_contatos(pessoa agenda[], FILE *arq) {
	int cont = 0;
	int flag = 1;

	do {
		if (cont < TAM && (int)agenda[cont].nome[0] == 0) {
			printf("-------------------------------------------\n");
			printf("Dados Básicos\n\n");

			printf("Informe o nome: ");
			scanf(" %[^\n]s",agenda[cont].nome);

			printf("\nInforme o email: ");
			scanf(" %[^\n]s",agenda[cont].email);

			printf("\n------------------------------------------\n");
			printf("Endereço\n\n");

			printf("Informe o nome da rua: ");
			scanf(" %[^\n]s",agenda[cont].ender.rua);

			printf("Informe o nome do bairro: ");
			scanf(" %[^\n]s",agenda[cont].ender.bairro);

			printf("Informe o numero do endereço: ");
			scanf("%d",&agenda[cont].ender.numero);

			printf("Informe o complemento do endereço: ");
			scanf(" %[^\n]s",agenda[cont].ender.complemento);

			printf("Informe o CEP: ");
			scanf("%d",&agenda[cont].ender.cep);

			printf("Informe a cidade: ");
			scanf(" %[^\n]s",agenda[cont].ender.cidade);

			printf("Informe o estado: ");
			scanf(" %[^\n]s",agenda[cont].ender.estado);

			printf("Informe o País: ");
			scanf(" %[^\n]s",agenda[cont].ender.pais);

			printf("\n------------------------------------------\n");
			printf("Data nascimento\n\n");

			printf("Informe o dia: ");
			scanf("%d",&agenda[cont].dat.dia);

			printf("Informe o mês: ");
			scanf("%d",&agenda[cont].dat.mes);

			printf("Informe o ano: ");
			scanf("%d",&agenda[cont].dat.ano);

			printf("\n------------------------------------------\n");
			printf("Telefone\n\n");

			printf("Informe o DDD: ");
			scanf("%d",&agenda[cont].tel.DDD);

			printf("Informe o numero de telefone: ");
			scanf("%d",&agenda[cont].tel.numero);

			printf("\n------------------------------------------\n");
			printf("Escreva uma observação: ");
			scanf(" %[^\n]s",agenda[cont].observacao);

			system("clear");

			printf("------------------------------------------\n");
			printf("           Contato cadastrado !\n");
			printf("------------------------------------------\n\n");

			printf("Escolha uma opção abaixo: \n");
			printf("1 - Cadastrar outro Contato\n");
			printf("2 - Voltar ao menu principal\n");
			printf("Opção: ");
			scanf("%d",&flag);
			system("clear");
		}

		if (flag == 1) {
			cont++;
		} else {
			if (flag == 2) {
				if ((arq = fopen("dados.bin","wb")) == NULL) {
					printf("Erro ao abrir o arquivo !\n\n");
					exit(1);
				} else {
					ordenacao(agenda);
					fwrite(agenda,sizeof(pessoa),TAM,arq);
				}
				fclose(arq);
				return 0;
			}
		}
	} while (cont < TAM);
}

void remover_contatos(pessoa agenda[], FILE *arq) {
	char remov[60];
	int iguais, opt, quant, flag = 1;

	do {
		quant = 0;
		printf("-----------------------------------------------------------\n");
		printf("			Contatos cadastrados: \n");
		printf("-----------------------------------------------------------\n\n");
		for (int cont = 0; cont < TAM; cont++) {
			if (agenda[cont].nome[0] != 0) {
				printf("Nome = %s\n",agenda[cont].nome);
			}
		}
		printf("-----------------------------------------------------------\n\n");

		printf("Informe o nome do contato que quer remover: ");
		scanf(" %[^\n]s",remov);

		for (int cont = 0; cont < TAM; cont++) {
			system("clear");
			iguais = 0;
			for (int x = 0; x < strlen(remov); x++) {
				if (tolower(agenda[cont].nome[x]) == tolower(remov[x])) {
					iguais++;
				}
			}

			if (iguais == strlen(remov)) {
				printf("%s",agenda[cont].nome);

				printf("\nQuer remover esse contato ?\n");
				printf("1 - sim\n");
				printf("2 - Não\n");
				printf("Opção ");
				scanf("%d",&opt);

				if (opt == 1) {
					quant++;

					for (int y = 0; y < 60; y++) {
						agenda[cont].nome[y] = 0;
					}
				}
			}
		}

		system("clear");
		if (quant != 0) {
			printf("Foi removido %d contatos !\n\n",quant);
		} else {
			printf("Não foi encontrado contatos com o nome %s !\n\n",remov);
		}
		printf("1 - Remover mais contatos\n");
		printf("2 - Voltar ao menu principal\n");
		printf("Opção: ");
		scanf("%d",&flag);
		system("clear");
	} while (flag != 2);

	if ((arq = fopen("dados.bin","wb")) == NULL) {
		printf("Erro ao abrir o arquivo !\n\n");
		exit(1);
	} else {
		ordenacao(agenda);
		fwrite(agenda,sizeof(pessoa),TAM,arq);
	}
	fclose(arq);
}

void busca_nome(pessoa agenda[]) {
	char busca[60];
	int quant, iguais, flag = 1;

	do {
		quant = 0;
		system("clear");
		printf("Informe o nome do contato que quer procurar: ");
		scanf(" %[^\n]s",busca);

		system("clear");
		for (int cont = 0; cont < TAM; cont++) {
			iguais = 0;
			for (int x = 0; x < strlen(busca); x++) {
				if (tolower(agenda[cont].nome[x]) == tolower(busca[x])) {
					iguais++;
				}
			}

			if (iguais == strlen(busca)) {
				quant++;

				printf("Nome: %s\tTelefone: (%d) %d\n",agenda[cont].nome, agenda[cont].tel.DDD, agenda[cont].tel.numero);
	            printf("Data de nascimento: %d/%d/%d\temail: %s\n",agenda[cont].dat.dia, agenda[cont].dat.mes, agenda[cont].dat.ano, agenda[cont].email);
	            printf("Bairro: %s    Rua: %s    Numero: %d    CEP: %d\n",agenda[cont].ender.bairro, agenda[cont].ender.rua, agenda[cont].ender.numero, agenda[cont].ender.cep);
	            printf("Complemento: %s\n",agenda[cont].ender.complemento);
	            printf("Cidade: %s       Estado: %s        País: %s\n",agenda[cont].ender.cidade, agenda[cont].ender.estado, agenda[cont].ender.pais);
	            printf("Observação: %s\n",agenda[cont].observacao);
	            printf("----------------------------------------------------------\n\n");
			}
		}

		if (quant > 0) {
			printf("Foi encontrado(s) %d contato(s) com o nome %s !\n\n",quant,busca);
		} else {
			printf("Não foi encontrado nenhum contato com o nome %s !\n\n",busca);
		}

		printf("1 - Procurar mais contatos\n");
		printf("2 - Voltar ao menu principal\n");
		printf("Opção: ");
		scanf("%d",&flag);
	} while (flag != 2);
}

void busca_mes(pessoa agenda[]) {
	int busca_mes, flag = 1, quant;

	do {
		system("clear");
		printf("Informe o numero correspondente ao mês que quer buscar: ");
		scanf("%d",&busca_mes);

		system("clear");
		quant = 0;
		for (int cont = 0; cont < TAM; cont++) {
			if ((int)agenda[cont].nome[0] != 0) {
				if (agenda[cont].dat.mes == busca_mes) {
					quant++;

					printf("Nome: %s\tTelefone: (%d) %d\n",agenda[cont].nome, agenda[cont].tel.DDD, agenda[cont].tel.numero);
	            	printf("Data de nascimento: %d/%d/%d\temail: %s\n",agenda[cont].dat.dia, agenda[cont].dat.mes, agenda[cont].dat.ano, agenda[cont].email);
	            	printf("Bairro: %s    Rua: %s    Numero: %d    CEP: %d\n",agenda[cont].ender.bairro, agenda[cont].ender.rua, agenda[cont].ender.numero, agenda[cont].ender.cep);
	            	printf("Complemento: %s\n",agenda[cont].ender.complemento);
	            	printf("Cidade: %s       Estado: %s        País: %s\n",agenda[cont].ender.cidade, agenda[cont].ender.estado, agenda[cont].ender.pais);
	            	printf("Observação: %s\n",agenda[cont].observacao);
	            	printf("----------------------------------------------------------\n\n");
				}
			}
		}

		if (quant > 0) {
			printf("Foram encontrados %d contatos !\n\n",quant);
		} else {
			printf("Não foi encontrado nenhum contato !\n");
		}

		printf("1 - Procurar outro contato\n");
		printf("2 - Voltar ao menu principal\n");
		printf("Opção: ");
		scanf("%d",&flag);
	} while (flag != 2);
}

void busca_mes_dia(pessoa agenda[]) {
	int busca_mes, busca_dia, flag = 1, quant;

	do {
		system("clear");
		printf("Informe o numero correspondente ao mês que quer buscar: ");
		scanf("%d",&busca_mes);

		printf("Infome o numero correspondente ao dia que quer buscar: ");
		scanf("%d",&busca_dia);

		system("clear");
		quant = 0;
		for (int cont = 0; cont < TAM; cont++) {
			if ((int)agenda[cont].nome[0] != 0) {
				if (agenda[cont].dat.mes == busca_mes) {
					if (agenda[cont].dat.dia == busca_dia) {
						quant++;

						printf("Nome: %s\tTelefone: (%d) %d\n",agenda[cont].nome, agenda[cont].tel.DDD, agenda[cont].tel.numero);
		            	printf("Data de nascimento: %d/%d/%d\temail: %s\n",agenda[cont].dat.dia, agenda[cont].dat.mes, agenda[cont].dat.ano, agenda[cont].email);
		            	printf("Bairro: %s    Rua: %s    Numero: %d    CEP: %d\n",agenda[cont].ender.bairro, agenda[cont].ender.rua, agenda[cont].ender.numero, agenda[cont].ender.cep);
		            	printf("Complemento: %s\n",agenda[cont].ender.complemento);
		            	printf("Cidade: %s       Estado: %s        País: %s\n",agenda[cont].ender.cidade, agenda[cont].ender.estado, agenda[cont].ender.pais);
		            	printf("Observação: %s\n",agenda[cont].observacao);
		            	printf("----------------------------------------------------------\n\n");
		            }
				}
			}
		}

		if (quant > 0) {
			printf("Foram encontrados %d contatos !\n\n",quant);
		} else {
			printf("Não foi encontrado nenhum contato !\n");
		}

		printf("1 - Procurar outro contato\n");
		printf("2 - Voltar ao menu principal\n");
		printf("Opção: ");
		scanf("%d",&flag);
	} while (flag != 2);
}

void ver_agenda(pessoa agenda[]) {
	int flag = 1, cont, x;

	do {
		printf("1 - Ver nome, telefone e e-mail\n");
		printf("2 - Ver todos os dados\n");
		printf("3 - Voltar ao menu principal\n");
		printf("Opção: ");
		scanf("%d",&flag);
		system("clear");

		switch (flag) {

			case 1:
				for(x = 65; x <= 90; x++) {
					for (cont = 0; cont < TAM; cont++) {
						if ((int)toupper(agenda[cont].nome[0] == x)) {
							printf("Nome: %s\t",agenda[cont].nome);
							printf("Telefone: (%d) %d\n",agenda[cont].tel.DDD,agenda[cont].tel.numero);
							printf("E-mai: %s\n",agenda[cont].email);
							printf("----------------------------------------------\n\n");
						}
					}
				}
			break;

			case 2:
				for(x = 65; x <= 90; x++) {
					for (cont = 0; cont < TAM; cont++) {
						if ((int)toupper(agenda[cont].nome[0] == x)) {
							printf("Nome: %s\tTelefone: (%d) %d\n",agenda[cont].nome, agenda[cont].tel.DDD, agenda[cont].tel.numero);
		            		printf("Data de nascimento: %d/%d/%d\temail: %s\n",agenda[cont].dat.dia, agenda[cont].dat.mes, agenda[cont].dat.ano, agenda[cont].email);
		            		printf("Bairro: %s    Rua: %s    Numero: %d    CEP: %d\n",agenda[cont].ender.bairro, agenda[cont].ender.rua, agenda[cont].ender.numero, agenda[cont].ender.cep);
		            		printf("Complemento: %s\n",agenda[cont].ender.complemento);
		            		printf("Cidade: %s       Estado: %s        País: %s\n",agenda[cont].ender.cidade, agenda[cont].ender.estado, agenda[cont].ender.pais);
		            		printf("Observação: %s\n",agenda[cont].observacao);
		            		printf("----------------------------------------------------------\n\n");
						}
					}
				}
			break;
		}
	} while (flag != 3);
}


int main () {

	FILE *arq;
	pessoa *agenda = (pessoa*) malloc(TAM * sizeof(pessoa));
	char opt;
	int cont;
	char flag;

	memset(agenda,0,(TAM * sizeof(pessoa))); // função que zera todos os valores da estrutura

	do {
		if ((arq = fopen("dados.bin","rb")) == NULL) {
			if ((arq = fopen("dados.bin","wb")) == NULL) {
				printf("Erro ao abrir o arquivo !\n\n");
				exit(1);
			} else {
				fwrite(agenda,sizeof(pessoa),TAM,arq);
			}
		} else {
			fread(agenda,sizeof(pessoa),TAM,arq);
		}
		fclose(arq);

		system("clear");
		printf(" _______________________________________________________________________\n");
		printf("|   ****************************************************************    |\n");
		printf("|   ********************* AGENDA DE TELEFONES **********************    |\n");
		printf("|   ****************************************************************    |\n");
		printf("|                                                                       |\n");
		printf("|                       [1] Abrir o Menu                                |\n");
		printf("|                       [2] Créditos                                    |\n");
		printf("|                       [3] Sair                                        |\n");
		printf("|_______________________________________________________________________|\n");
		opt = getch();
		setbuf(stdin,NULL);
		system("clear");

		switch (opt) {
			case 49:
				do {
					system("clear");
					printf("----------------------------------------------\n");
					printf("\tAGENDA DE TELEFONES\n");
					printf("----------------------------------------------\n\n");
					printf("[1] Inserir contatos\n");
					printf("[2] Remover contatos\n");
					printf("[3] Busca por nome\n");
					printf("[4] Busca por mês de aniversário\n");
					printf("[5] Busca por mês e dia de aniversário\n");
					printf("[6] Ver agenda\n");
					printf("[7] Voltar a tela inicial\n");
					printf("Opção: ");
					flag = getch();
					setbuf(stdin,NULL);

					switch (flag) {
						case '1':
							system("clear");
							inserir_contatos(agenda,arq);
						break;

						case '2':
							system("clear");
							remover_contatos(agenda,arq);
						break;

						case '3':
							system("clear");
							busca_nome(agenda);
						break;

						case '4':
							system("clear");
							busca_mes(agenda);
						break;

						case '5':
							system("clear");
							busca_mes_dia(agenda);
						break;

						case '6':
							system("clear");
							ver_agenda(agenda);
						break;

					}

				} while(flag != 55);
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
				free(agenda);
				return 0;
			break;
		}
	} while (1);

}

void init_attr(struct termios *old_attr,struct termios *new_attr) {
    tcgetattr(0,&*old_attr);

    *new_attr=*old_attr;
    new_attr->c_lflag &=~ICANON;
    new_attr->c_cc[VMIN]=1;
    new_attr->c_cc[VTIME]=0;
}

int getch() {
   struct termios old_attr, new_attr;
   int c;

   init_attr(&old_attr,&new_attr);

   new_attr.c_lflag &=~ECHO;

   tcsetattr(STDIN_FILENO,TCSANOW,&new_attr);

   c = getchar();

   tcsetattr(STDIN_FILENO,TCSANOW,&old_attr);

   return c;
}