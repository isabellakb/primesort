#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

/*Verifica se um número tem 1, 2 ou mais divisores*/
int divisores (int num){
  int divisor=0;
  int i=0;
  while(i<num){
    int a=i+1;
    if (num%a==0)
      divisor++;
    if (divisor>2)
      break;
    i++;
  }
  return divisor;
}

int main(){
  FILE *ordenar;
  int numero;
  int nao_primo[200000];
  int i=0, j=0, k=0, aux;

  scanf ("%d", &numero); //Lê número digitado
  while (numero!=-1){
    if (divisores(numero)!=2){ //Se o número de dividores for diferente de 2, não é primo
      nao_primo[k]=numero;     //Salva os não primos em um vetor
      k++;
    }
    scanf ("%d", &numero); //Lê número digitado
  }
  if((ordenar=popen("sort -n -r", "w"))==NULL){ // Ordena números do maior para menor
  perror("popen");
  exit(1);
  }
  for (i=0; i<k; i++)
    fprintf(ordenar, "%d\n", nao_primo[i]); //Imprime números não primos ordenados
}
