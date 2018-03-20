//CIC250 - Cálculo Bumérico para Computação
//Exercicio Pratico 03 - 21/03/18
//2016013442 - Luís Otávio Malta Conceição
//
//Calculo de raizes reais de funções reais - metodo das secantes

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Define função
double funcao(double x){
  //double y = (pow(2,x)-2*pow(x,2)+1); // <--Funcao a ser substituida ------- //EX1
  //double y = (-12 -21*x + 18*pow(x,2) - 2.4*pow(x,3)); // EX3
  double y = (sin(x) + cos(1 + pow(x,2)) -1); // EX4

  return y;
}

int main(){
  double x0, x1, x2, e;
  int k, int_max;

  printf("Entre com as aproximacoes iniciais:\n");
  scanf("%lf %lf", &x0, &x1);

  printf("Entre com a precisao:\n");
  scanf("%lf", &e);

  int_max = 4;
  while(k < int_max){
    x2 = (((x0*funcao(x1))-(x1*funcao(x0)))/(funcao(x1)-funcao(x0)));

    if((fabs(x2 - x1)/fabs(x2)) < e){
      break;
    } else {
      x0 = x1;
      x1 = x2;
      k++;
    }
  }

  printf("A raiz da funcao e: %lf", x2);
}
