//CIC250 - Cálculo Numérico para Computação
//Exercicio Pratico 04 - 28/03/18
//2016013442 - Luís Otávio Malta Conceição
//Resolução de sistemas lineares pelo método de Eliminação de Gaus

#include <stdio.h>
#include <stdlib.h>



int main(){

    int linha, coluna;

    printf("Entre com a quantidade de linhas e colunas\n");
    scanf("%d %d", &linha, &coluna);

    double matriz[linha][coluna];
    double m;

    printf("Entre com a matriz\n");
    for(int i = 0; i < linha; i++){
      for(int j = 0; j < coluna; j++){
        scanf("%lf", &matriz[i][j]);
      }
    }

    for(int k = 0; k < linha - 1; k++){
      for(int i = k + 1; i < linha; i++){
        m = matriz[i][k]/matriz[k][k];

        for(int j = k; j < linha + 1; j++){
          matriz[i][j] = matriz[i][j] - m * matriz[k][j];
        }
      }
      printf("\nMatriz parcial:\n");
      for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
          printf("%lf ", matriz[i][j]);
        }
        printf("\n");
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
