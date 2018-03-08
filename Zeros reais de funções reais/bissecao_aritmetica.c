#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Define função
double funcao(double x){
  return (pow(x,2));
}

//Calcula a média aritmética de 2 números
double media_aritimetica(double a, double b){
  return ((b + a)/2);
}

//Calcula a estimativa da quantidade maxima de iteraçoes
int iteracoes_max(double a, double b, double e){
  return ceil(((log10f(b - a) - log10f(e))/log10f(2.0))-1);
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

  int_max = iteracoes_max(a, b, e);

//Iterações de aproximação
  while(k < int_max){
    if((b - a) < e){
      break;
    }

    x = media_aritimetica(a, b);

    if(funcao(x) > 0){
      b = x;
    } else {
      a = x;
    }

    k++;
  }
  
  raiz = media_aritimetica(a,b);
  printf("A raiz do intervalo e: %lf", raiz);

}
