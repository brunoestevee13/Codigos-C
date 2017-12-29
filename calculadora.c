#include <stdio.h>
#define N 999999
int main () {
    
    int op,max_dado,max,cont,num;
    int soma=0,sub=0,prod=1,pos;
    float div=1;
    int n[N];
    int res=1;
     
    while (res!=2) {
    printf("Informe o operador aritmético:\n1 - Adição\n2 - Subtração\n3 - Multiplicação\n4 - Divisão\nOpção: ");
    scanf("%d",&op);
    if (op<1 || op>4) {
       while (op<1 || op>4) {
          printf("Invalido, informe a opção novamente: ");
          scanf("%d",&op);
       }
    }
    printf("Informe a quantidade de numeros: ");
    scanf("%d",&max_dado);
    max=max_dado-1;
    printf("\n\n");
   
    switch (op) {

        case 1: 
          for (cont=0; cont<=max; cont++) {
              pos=cont+1;
              printf("Informe o %d.° numero: ",pos);
              scanf("%d",&n[cont]);
              soma=soma+n[cont];
          }
          printf("A soma entre esses numeros é %d.\n\n",soma);
        break;

        case 2:
          for (cont=0; cont<=max; cont++) {
               pos=cont+1;
               printf("Informe o %d.° numero: ",pos);
               scanf("%d",&n[cont]);
               sub=n[cont]-sub;
          }
          printf("A subtração entre esses numeros é %d.\n\n",sub);
        break;
     
        case 3:
          for (cont=0; cont<=max; cont++) {
              pos=cont+1;
              printf("Informe o %d.° numero: ",pos);
              scanf("%d",&num);
              prod=prod*num;
          }
          printf("O produto desses numeros é %d.\n\n",prod);
        break;
        
        case 4: 
          for (cont=0; cont<=max; cont++) {
              pos=cont+1;
              printf("Informe o %d.° numero: ",pos);
              scanf("%d",&num);
              div=num/div;
          }
          printf("O resultado da divisão desses numeros é %.2f.\n\n",div);
        break;
       
    }
    printf("Quer continuar?\n");
    printf("1 - Sim\n");
    printf("2 - Não\n");
    printf("Opção: ");
    scanf("%d",&res);
    if (res<1 || res>2) {
        while (res<1 || res>2) {
            printf("Invalido, informe a opção novamente: ");
            scanf("%d",&res);
        }
    }
    printf("\n\n");
    }
    return 0;
}
          
               
