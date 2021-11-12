#include <stdio.h>
#include <stdlib.h>

int zero(int x){
	return (x==0);
}

int incr(int x){
	return (x+1);
}

int decr(int x){
	return (x-1);
}

int negativo(int a) {
  if (a<0) {return 1;}
  else {return 0;}
}

int soma_neg(int x, int y){
	if(zero(x)) {
		return y;
	}
	x = soma_neg(incr(x), y);
	return decr(x);
}
int soma_pos(int x, int y){
	if(zero(x)) {
		return y;
	}
	x = soma_pos(decr(x), y);
	return incr(x);
}

int somatorio(int* vetor, int tam){
	if(zero(tam)) {
		return vetor[tam];
	}
	int x = vetor[tam];
	if (negativo(x)){
		return soma_neg(x, somatorio(vetor, decr(tam)));
	}else{
		return soma_pos(x, somatorio(vetor, decr(tam)));
	}
	
}

int main () {
	int tam, i;
	scanf ("%d", &tam);
	int *vetor = (int*)malloc(tam * sizeof(int));
	for (i = 0; i<tam; i++){
		scanf ("%d", &vetor[i]);
	}
	printf("%d", somatorio(vetor, tam-1));
}