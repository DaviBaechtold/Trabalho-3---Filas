//Davi Baechtold Campos
//Trabalho 3 - Filas

/*
Sua  tarefa  será  construir  um  código  capaz de  somar,  item  a  item,  todos os  inteiros  entre  1  e 1.000.000. Existe, pelo menos uma fórmula matemática que pode ser usada para validar o resultado. 
Contudo, você deverá criar uma fila, armazenar este inteiros nesta fila, depois percorrer  fila somando estes valores. A tarefa é para exercitar o uso de algoritmos, não da matemática.  

Atenção: use a mesma plataforma que usou no Trabalho 1 – pilhas. 
Seu  objetivo  será  medir  o  tempo  para  inserção  de  1.000.000  milhão  de  inteiros  em  uma estrutura de dados, o tempo para percorrer e somar 1.000.000 de inteiros em uma estrutura de dados, e o  tempo para garantir que um determinado  inteiro  já está na  fila (busca). Finalmente você deverá 
medir estes tempos percorrendo a fila em dois sentidos. De cima para baixo e de baixo para cima. 

Seu resultado será a média dos tempos gastos para as operações citadas acima em, no mímino 50 operações de cada tipo. As saídas apresentadas devem seguir o seguinte padrão: operação: tempo conforme pode ser visto no exemplo a seguir:  

Preenchimento da Fila: 1.234s 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  
  clock_t tic = clock();
  
  int isValidaded,isValidaded2 = 0;
  int n=1000000;
  long int arr[n];
  int i,j,k,l,m;
  long int soma = 0;
  long int soma2 = 0;
  int inputUser =-1;
  
   for ( i = 0; i < n+1; i++ ) {
      arr[ i ] = i + 1;
   }
  
  clock_t toc = clock();
  printf("\n");
  printf("Tempo de geracao da lista:   %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
  printf("\n");
  printf("Type a number: \n");
  scanf("%d", &inputUser);
  printf("\n");

  clock_t tic2 = clock();
  
  for (k = 0 ;k <= n; k++) {
    if (k == inputUser) {
      isValidaded = 1;
    }
  }
  clock_t toc2 = clock();

  printf("[UP]Tempo de verificacao:   %f seconds\n", (double)(toc2 - tic2) / CLOCKS_PER_SEC);
  printf("\n");
  clock_t tic3 = clock();
  
  for (k = n-1 ;k >= 0; k--) {
    if (k == inputUser) {
      isValidaded2 = 1;
    }
  }
  clock_t toc3 = clock();

  printf("[DOWN]Tempo de verificacao:   %f seconds\n", (double)(toc3 - tic3) / CLOCKS_PER_SEC);
  printf("\n");
  clock_t tic6 = clock();
  
  int comprimento = sizeof arr / sizeof *arr;
  
  if (isValidaded == 1 & isValidaded==isValidaded2){
    j=0;
    while(j < n-1) {
      
      arr[j+1] = arr[j+1]+arr[j];
      k=0;
      j=j+1;
    }

  }
  else{
    printf("ERRO!");
    printf("\n");
  }
  
  clock_t toc6 = clock();
  printf("Tempo de soma:   %f seconds\n", (double)(toc6 - tic6) / CLOCKS_PER_SEC);
  printf("\n");
 
  printf("RESULTADO DA SOMA: \n");
  printf("%ld\n",arr[comprimento-1]);
  printf("\n");
  clock_t toc5 = clock();
  printf("Tempo total  de execucao:    %f seconds\n", (double)(toc5 - tic) / CLOCKS_PER_SEC);
}
