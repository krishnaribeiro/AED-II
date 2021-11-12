#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipoNome{
	char nome[100];
} tipoNome;

void swap(tipoNome a[], int inicio, int fim){
	tipoNome aux;
	aux = a[inicio];
	a[inicio] = a[fim];
	a[fim] = aux;
}

void quicksort(tipoNome A[], int inicio, int fim) {
	tipoNome pivo;
	int i, j, meio;
	tipoNome aux;
	while(inicio < fim){
		meio = (inicio+fim)/2;
		pivo = A[meio];
		i = inicio;
		j = fim;
		while(i <= j){
			while(strcmp(A[i].nome, pivo.nome) < 0) 
				i++;
			while(strcmp(A[j].nome, pivo.nome) > 0){
				j--;
			} if(i <= j){
					aux = A[i];
					A[i] = A[j];
					A[j] = aux;
					i++; j--;
				}
		}
		if(j < meio){
			quicksort(A, inicio, j);
			inicio = i;
		} else{
			quicksort(A, i, fim);
			fim = j;
		}
	}
}

int main(){
	int pos, neg, m, i;
	char nome[100];
	char sinal;
	
	scanf("%d%*c", &m);
	tipoNome *vetorNomes = (tipoNome*)malloc(sizeof(tipoNome)*m);
	
	for (i = 0; i < m; i++) {
		scanf("%c%*[ ]%[^\n]%*c", &sinal, nome);
		strcpy(vetorNomes[i].nome, nome);
		if (sinal == '+'){
			pos++;
		}
		else if (sinal == '-'){
			neg++;
		}
	}
	quicksort(vetorNomes, 0, m-1);
	for (i = 0; i < m; i++){
		printf("%s\n", vetorNomes[i].nome);
	}
	printf("Se comportaram: %d | Nao se comportaram: %d\n", pos, neg);
	
}