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

int soma(int x, int y){
	if(zero(x)) {
		return y;
	}
	x = soma(decr(x), y);
	return incr(x);
}

int main () {
int n1, n2;
	
	do {
		scanf ("%d %d", &n1, &n2);
		if (n1 == 0 && n2 == 0){
			break;
		}
		printf("%d \n", soma(n1, n2));
	}
	while(n1 != 0 && n2 != 0);
}