#include <stdio.h>
#include <stdlib.h>

int hash (int key, int N){
	return (key%N);
}
int* insere (int *tab, int key, int N){
	int h = hash(key, N);
	int rounds = 0;
	while (tab[h] != 0) {
		if (tab[h] == key)
			return tab;
		h = (h+1) % N;
		rounds++;
		if (N < rounds)
			break;
	}
	if (tab[h] == 0) { 
		tab[h] = key;
		return tab;
	} else
		return tab;
}
void imprimeTabelaHash(int* tab, int m){
	int i;
	for (i=0; i< m; i++){
		if (tab[i] == 0)
			printf("%d null\n", i);
		else
			printf("%d %d\n", i, tab[i]);
	}
}
int busca (int *tab, int key, int N) {
	int h = hash(key, N);
	int rounds = 0;
	while (tab[h] != 0) {
		if (tab[h] == key)
			return h;
		h = (h+1) % N;
		rounds++;
		if (N < rounds)
			break;
	}
	return -1;
}

int main(){
	int m, i, key, x;
	scanf("%d%*c", &m);
	int *tabelahash = (int*)malloc(sizeof(int)*m);
	for (i=0; i < m; i++){
		tabelahash[i] = 0;
	}
	do{
		scanf("%d%*c", &key);
		if(key)
			insere(tabelahash, key, m);
	}while(key);
	
	do{
		scanf("%d%*c", &key);
		if(key){
			x = busca(tabelahash, key, m);
			if (x == -1){
				printf("%d not found\n", key);
			} else {
				printf("%d %d\n", key, x);
			}
		}
	}while(key);
	
	return 0;
}