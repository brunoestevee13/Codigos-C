#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <time.h>
#include <ctype.h>

void init_attr(struct termios *old_attr,struct termios *new_attr);
int getch();

int main () {
	system("clear");

	int computador;
	int jogador;
	char flag;

	srand(time(NULL));
	do {	
		computador = rand() % 2;
		printf("Suas opções:\n");
		printf("[ 0 ] PEDRA\n");
		printf("[ 1 ] PAPEL\n");
		printf("[ 2 ] TESOURA\n");
		printf("Qual é a sua jogada ? ");
		scanf("%d",&jogador);
		setbuf(stdin,NULL);

		printf("\nJO\n");
		sleep(1);
		printf("KEN\n");
		sleep(1);
		printf("PO!!!\n\n");

		printf("-=-=-=-=-=-=-=-=-=-=-=\n");
		switch (jogador) {
			case 0:
				if (computador == 0) {
					printf("Computador jogou Pedra\n");
					printf("Jogador jogou Pedra\n");
					printf("-=-=-=-=-=-=-=-=-=-=-=\n");
					printf("EMPATE\n");
				} else {
					if (computador == 1) {
						printf("Computador jogou Papel\n");
						printf("Jogador jogou Pedra\n");
						printf("-=-=-=-=-=-=-=-=-=-=-=\n");
						printf("COMPUTADOR VENCE\n");
					} else {
						if (computador == 2) {
							printf("Computador jogou Tesoura\n");
							printf("Jogador jogou Pedra\n");
							printf("-=-=-=-=-=-=-=-=-=-=-=\n");
							printf("JOGADOR VENCE\n");
						}
					}
				}
			break;

			case 1:
				if (computador == 0) {
					printf("Computador jogou Pedra\n");
					printf("Jogador jogou Papel\n");
					printf("-=-=-=-=-=-=-=-=-=-=-=\n");
					printf("JOGADOR VENCE\n");
				} else {
					if (computador == 1) {
						printf("Computador jogou Papel\n");
						printf("Jogador jogou Papel\n");
						printf("-=-=-=-=-=-=-=-=-=-=-=\n");
						printf("EMPATE\n");
					} else {
						if (computador == 2) {
							printf("Computador jogou Tesoura\n");
							printf("Jogador jogou Papel\n");
							printf("-=-=-=-=-=-=-=-=-=-=-=\n");
							printf("COMPUTADOR VENCE\n");
						}
					}
				}
			break;

			case 2: 
				if (computador == 0) {
					printf("Computador jogou Pedra\n");
					printf("Jogador jogou Tesoura\n");
					printf("-=-=-=-=-=-=-=-=-=-=-=\n");
					printf("COMPUTADOR VENCE\n");
				} else {
					if (computador == 1) {
						printf("Computador jogou Papel\n");
						printf("Jogador jogou Tesoura\n");
						printf("-=-=-=-=-=-=-=-=-=-=-=\n");
						printf("JOGADOR VENCE\n"); 
					} else {
						if (computador == 2) {
							printf("Computador jogou Tesoura\n");
							printf("Jogador jogou Tesoura\n");
							printf("-=-=-=-=-=-=-=-=-=-=-=\n");
							printf("EMPATE\n");
						}
					}
				}
			break;
		}

		printf("\n");
		printf(" _________________________________________________________\n");
		printf("|                                                         |\n");
		printf("|Aperte ENTER para jogar novamente ou aperte S para sair  |\n");
		printf("|_________________________________________________________|\n");
		flag = getch();
		setbuf(stdin,NULL);

		if ((int)(toupper(flag)) == 83) {
			return 0;
		} else {
			system("clear");
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