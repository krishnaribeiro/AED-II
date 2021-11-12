#include <stdio.h>
#include <stdlib.h>
int soma_recursiva_vetor(int * vetor, int tam){
	if (tam == 0){
		return vetor[tam];
	}
	int x = vetor[tam];
	return x+soma_recursiva_vetor(vetor, tam-1);
}

int soma_recursiva_matriz(int ** matriz, int m, int n){
	if (m == 0){
		return soma_recursiva_vetor(matriz[m], n);
	}
	int x = soma_recursiva_vetor(matriz[m], n);
	
	return x+soma_recursiva_matriz(matriz, m-1, n);	
}

int main(){
	int i, j, count = 0;
	int m, n;
	scanf("%d %d", &m ,&n);

	int **matriz1 = (int **)malloc(m * sizeof(int*));
	for(i = 0; i < m; i++){
		matriz1[i] = (int *)malloc(n * sizeof(int));
	}
	
	for(i = 0; i < m; i++){
		do {
			  scanf("%d", &matriz1[i][count++]);
		 } while (getchar() != '\n' && count < n);
		count = 0;
	}
	
	printf("%d", soma_recursiva_matriz(matriz1, m-1, n-1));
}