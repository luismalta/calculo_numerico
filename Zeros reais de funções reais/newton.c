//CIC250 - Cálculo Bumérico para Computação
//Exercicio Pratico 03 - 21/03/18
//2016013442 - Luís Otávio Malta Conceição
//
//Calculo de raizes reais de funções reais - metodo de Newton

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Define função
double funcao(double x){
  //double y = (pow(2,x)-2*pow(x,2)+1); // <--Funcao a ser substituida ------- //EX1
  double y = (-1 + 5.5*x - 4*pow(x,2) + (0.5*pow(x,3))); //EX2

  return (y);
}

//Define derivada da função
double derivada(double x){
  //double y = logf(2)*pow(2,x)-4*x; // <-- Derivada da função ------ //EX1
  double y = (1.5*pow(x,2) -8*x + 5.5); //EX2

  return (y);
}

int main(){
  double e, x0, x1, raiz;
  int k, int_max;

  printf("Entre com o x inicial:\n");
  scanf("%lf", &x0);

  printf("Entre com a precisao:\n");
  scanf("%lf", &e);

  int_max = 100;

  k = 0;

  while(k < int_max){
    x1 = x0 - (funcao(x0)/derivada(x0));


    if(fabs(x1 - x0) / fabs(x1) < e){
      break;
    } else {
      x0 = x1;
      k++;
    }
  }

  printf("A raiz da funcao e: %lf", x1);

}
