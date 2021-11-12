#include <stdio.h>
#include <stdlib.h>


int main() {
	
int i, j, linhas, colunas, count = 0;

scanf("%d %d", &linhas, &colunas);
	
int **matriz1 = (int **)malloc(linhas * sizeof(int*));
	for(i = 0; i < linhas; i++){
		matriz1[i] = (int *)malloc(colunas * sizeof(int));
	}
	
int **matriz2 = (int **)malloc(linhas * sizeof(int*));
	for(i = 0; i <  linhas; i++){
		 matriz2[i] = (int *)malloc(colunas * sizeof(int));
	}
	
	for(i = 0; i < linhas; i++){
		do {
			  scanf("%d", &matriz1[i][count++]);
		 } while (getchar() != '\n' && count < colunas);
		count = 0;
	}
	for(i = 0; i < linhas; i++){
		do {
			  scanf("%d", &matriz2[i][count++]);
		 } while (getchar() != '\n' && count < colunas);
		count = 0;
	}
	
int **matrizR = (int **)malloc(linhas * sizeof(int*));
	for(i = 0; i <  linhas; i++){
		 matrizR[i] = (int *)malloc(colunas * sizeof(int));
	}
	for(i = 0; i < linhas; i++){
		for(j = 0; j < colunas; j++) {
			matrizR[i][j] = matriz1[i][j] + matriz2[i][j]; 
		}
	}
	for(i = 0; i < linhas; i++){
		for(j = 0; j < colunas; j++) {
        printf("%d ", matrizR[i][j]);
        }
    printf("\n");
	}
}

