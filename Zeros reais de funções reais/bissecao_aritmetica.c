//CIC250 - Cálculo Bumérico para Computação
//Exercicio Pratico 02 - 14/03/18
//2016013442 - Luís Otávio Malta Conceição
//
//Calculo de raizes reais de funções reais - bisseção

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Define função
double funcao(double x){
  double N_E;
  return ((2*x)-pow(N_E,-x)); //<---- Equacao a ser substituida---------
}

//Calcula a média aritmética de 2 números
double media_aritimetica(double a, double b){
  return ((b + a)/2);
}

//Calcula a estimativa da quantidade maxima de iteraçoes
int iteracoes_max(double a, double b, double e){
  return ceil(((log10(b - a) - log10(e))/log10(2.0))-1);
}

int main(){
  double a, b, e, x, raiz;
  int k, int_max;

  k = 0;

  //Entrada de dados
  printf("Entre com os intervalos 'a e 'b:\n");
  scanf("%lf %lf", &a, &b);

  printf("Entre com a precisao: \n");
  scanf("%lf", &e);

  int_max = 50;
  //iteracoes_max(a, b, e);

//Iterações de aproximação
  while(k < int_max){
    printf("K: %d\n", k);
    if((b - a) < e){
      break;
    }

    x = media_aritimetica(a, b);


    if(fabs(funcao(x)) < e){
      printf("x: %lf\n", x);
      printf("A raiz do intervalo e: %lf\n", x);
      return 0;
    }

    if((funcao(a))*(funcao(x)) <= 0){
      b = x;
    } else {
      a = x;
    }

    k++;
  }

  raiz = media_aritimetica(a,b);
  printf("A raiz do intervalo e: %lf\n", raiz);

}
