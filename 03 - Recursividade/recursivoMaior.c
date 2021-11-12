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

int igual (int x, int y){
	if (zero(y)){ 
		if(zero(x)){
			return 1;
		}
	}
	if (zero(y)){
		return 0;
	}
	if (zero(x)){
		return 0;
	}
	return igual(decr(x),decr(y));
}

int main () {
int n1, n2;
	
	do {
		scanf ("%d %d", &n1, &n2);
		if (n1 == 0 && n2 == 0){
			break;
		}
		if (igual(n1,n2)) {
			printf ("SIM\n");
		}
		else {
	printf ("NAO\n");
		}
	}
	while(n1 != 0 && n2 != 0);
}