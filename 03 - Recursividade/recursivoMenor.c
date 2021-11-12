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

int menor (int x, int y){
	if (zero(y)){ 
		return 0;
	}
	if (zero(x)){ 
		return 1;
	}
	
	return menor(decr(x),decr(y));
}

int main () {
int n1, n2;
	
	do {
		scanf ("%d %d", &n1, &n2);
		if (n1 == 0 && n2 == 0){
			break;
		}
		if (menor(n1,n2)) {
			printf ("SIM\n");
		}
		else {
	printf ("NAO\n");
		}
	}
	while(n1 != 0 && n2 != 0);
}