#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Define função
double funcao(double x){
  return (pow(x,2));
}

//Calcula a média aritmética de 2 números
double posicao_falsa(double a, double b){
  return (((a*funcao(b)) - (b*funcao(a)))/(funcao(a) - funcao(b)));
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
  double a, b, e1, e2, x, raiz;
  int k, int_max;

  k = 0;

  //Entrada de dados
  printf("Entre com os intervalos 'a e 'b:\n");
  scanf("%lf %lf", &a, &b);

  printf("Entre com as preciçoes: \n");
  scanf("%lf %lf", &e1, &e2);

  int_max = iteracoes_max(a, b, e1);
  printf("int max: %d\n", int_max);

//Iterações de aproximação
  while(k < int_max){
    printf("k: %d\n", k);
    if((b - a) < e1){
      raiz = media_aritimetica(a,b);
      break;
    }

    if((abs(funcao(a)) < e2) && (k == 0)){
      raiz = a;
      break;
    }

    if((abs(funcao(b)) < e2) && (k == 0)){
      raiz = b;
      break;
    }

    x = posicao_falsa(a, b);
    printf("x: %lf", x);

    if(abs(funcao(x)) < e2){
      raiz = x;
            printf("Aqui");
      break;
    }

    if(funcao(x) > 0){
      b = x;
    } else {
      a = x;
    }

    k++;
  }

  printf("A raiz do intervalo e: %lf", raiz);

}
