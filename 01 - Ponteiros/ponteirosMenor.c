#include <stdio.h>
#include <stdlib.h>

void menorElemento(int *v, int n, int *menor){
	int i = 0;
	*menor = v[0];
	for (i = 1; i < n; i++){
		if (v[i] < *menor) {
			*menor = v[i];
		}
	}
}		
int main(){
	int tamanho = 0;
	int count = 0;
	int *menor = (int*)malloc(sizeof(int));
	int* v;
	scanf("%d", &tamanho);
	v = (int*) malloc(sizeof(int)*tamanho);
	do {
			  scanf("%d", &v[count++]);
		 } while (getchar() != '\n' && count < tamanho);
	*menor = v[0];
	menorElemento(v, tamanho, menor);
	printf("%d", *menor);
}
