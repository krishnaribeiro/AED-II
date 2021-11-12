#include <stdio.h>
#include <stdlib.h>

int zero(int num){
	return num == 0;
}

int incr(int num){
	return num + 1;
}

int decr(int num){
	return num - 1;
}
int diferente(int x, int y){
	if (zero(y)){ 
		if(zero(x)){
			return 0;	
		}
	}
	if (zero(y)){
		return 1;
	}
	if (zero(x)){
		return 1;
		}
	return diferente(decr(x),decr(y));
}

int main () {
int n1, n2;
	
	do {
		scanf ("%d %d", &n1, &n2);
		if (n1 == 0 && n2 == 0){
			break;
		}
		if (diferente(n1,n2)) {
			printf ("SIM\n");
		}
		else {
	printf ("NAO\n");
		}
	}
	while(n1 != 0 && n2 != 0);
}