#include <stdio.h>
#include <stdlib.h>

int multiplica_recursiva(int *vetor, int tam){
	if (tam == 0){
		return vetor[tam];
	}
	int x = vetor[tam];
	return x*multiplica_recursiva(vetor, tam-1);
}

int main(){
	int tam, i;
	scanf("%d", &tam);
	int *v =(int*)malloc(tam*sizeof(int));
	for (i = 0; i<tam; i++){
		scanf("%d", &v[i]);
	}
	printf("%d", multiplica_recursiva(v, tam-1));
}