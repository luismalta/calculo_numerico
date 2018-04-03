#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main(){
  int k = 0, coluna, linha, pare = 0;
  double e, somatorio;

  //Leitura da matriz
  printf("Entre com o tamnho da matriz e a precisao:\n");
  scanf("%d %d %lf", &linha, &coluna, &e);
  double x_anterior[coluna -1], x_atual[coluna -1], matriz[linha][coluna];

  printf("Entre com a matriz\n");
  for(int i = 0; i < linha; i++){
    for(int j = 0; j < coluna; j++){
      scanf("%lf", &matriz[i][j]);
    }
  }
  //Leitura da estimativa inicial
  printf("Entre com a estimativa inicial.\n");
  for(int i = 0; i < coluna -1; i++){
      scanf("%lf", x_anterior[i]);
  }

  //Iterações
  while(1){
    printf("Entrou.\n");
    for(int i = 0; i <= linha; i++){
      somatorio = 0;
      for(int j = 0; j < coluna -1; j++){
        if(i != j){
          somatorio -= matriz[i][j] * x_anterior[j];
        }
      }
      x_atual[i] = (matriz[i][coluna] - somatorio)/matriz[i][i];
    }

    pare = 0;
    for(int i = 0; i < coluna - 1; i++){
      if(((fabs(x_atual[i] - x_anterior[i]))/fabs(x_atual[i])) > e){
        pare = 1;
      }
    }

    if(pare == 0){
      break;
    }

    for(int i = 0; i < coluna; i++){
      x_anterior[i] = x_atual[i];
      matriz[i][0] = x_atual[0];
    }

    for(int i = 0; i < linha; i++){
      for(int j = 0; j < coluna - 1; j++){
        matriz[i][j] = x_atual[j];
      }
    }

  }

  printf("\nMatriz na forma triangular:\n");
  for(int i = 0; i < linha; i++){
    for(int j = 0; j < coluna; j++){
      printf("%lf ", matriz[i][j]);
    }
    printf("\n");
  }

}
