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

int simetrico(int x){
	if(zero(x)) {
		return 0;
	}
	x = simetrico(decr(x));
	return decr(x);
}

int main () {
int n1;
	
	do {
		scanf ("%d", &n1);
		if (n1 == 0){
			break;
		}
		printf("%d ", simetrico(n1));
	}
	while(n1 != 0);
}