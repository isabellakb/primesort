#include <stdio.h>

/*Calcula quantos divisores tem um determinado número*/
int divisores (int num){
  int divisor=0;
  int i;
  for(i=0; i<num; i++){
    int a=i+1;
    if (num%a==0)
      divisor++;
  }
  return divisor;
}

/*Verifica se um número é primo ou não*/
int primo (int n){
  int d=divisores(n);
  if(d==2)
    return 1;
  else
    return 0;
}

int main(){
  int numero;
  int nao_primo[200000];
  int i=0, j=0, k=0, aux
  scanf ("%d", &numero); //Lê número digitado  
  while (numero!=-1){
    if (primo(numero)==0){ //Salva os números da sequência digitada que não são primos
      nao_primo[k]=numero;
      k++;
    }
    scanf ("%d", &numero); //Lê número digitado
  }
  for (i=0; i<k; i++){ //Ordena por ordem de tamanho os números não primos
    j=i+1;
    if (nao_primo[i]<nao_primo[j]){
      aux=nao_primo[i];
      nao_primo[i]=nao_primo[j];
      nao_primo[j]=aux;
    }
  }
  for (i=0; i<k; i++){ //Imprime todos os números não primos ordenados
    printf ("%d", nao_primo[i]);
    printf ("\n");
  }
}
