#include <stdio.h>
#include <stdlib.h>
#include <math.h>
w


int main(){
  int k = 0, coluna, linha, pare = 0;
  double e, somatorio1, somatorio2;

  //Leitura da matriz
  printf("Entre com o tamnho da matriz e a precisao:\n");
  scanf("%d %d %lf", &linha, &coluna, &e);
  double x[coluna], x_inicial[coluna], matriz[linha][coluna], erro[coluna-1];

  printf("Entre com a matriz\n");
  for(int i = 0; i < linha; i++){
    for(int j = 0; j < coluna; j++){
      scanf("%lf", &matriz[i][j]);
    }
  }

  //Leitura da estimativa inicial
  printf("Entre com a estimativa inicial.\n");
  for(int i = 0; i < coluna; i++){
      scanf("%lf", x_inicial[i]);
      printf("........");
      x[i] = x_inicial[i];
      printf("i: %d", i);
  }

  //Iterações
  while(1){
    printf("........");
    somatorio1 = 0;
    somatorio2 = 0;

    for(int i = 0; i < coluna-1; i++){
        x_inicial[i] = x[i];
    }

    for(int i = 0; i < coluna-1; i++){
      for(int j = 1; j < i ; i++){
        somatorio1 += -matriz[i][j] * x[j];
      }

      for(int j = i + 1; j <= coluna -1; j++){
        somatorio2 = -matriz[i][j] * x[j];
      }

      x[i] = (somatorio1 + somatorio2) / (matriz[i][i] + (x[coluna] / matriz[i][i]));
    }

    for(int i = 0; i < coluna -1; i++){
      if((fabs(x[i] - x_inicial[i]) / fabs(x[i])) > e){
        pare = 1;
      }
    }
    if(pare == 0){
      break;
    } else {
      k++;
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
