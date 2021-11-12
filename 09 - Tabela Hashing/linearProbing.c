#include <stdio.h>
#include <stdlib.h>

int hash (int key, int N){
	return (key%N);
}
int* insere (int *tab, int key, int N){
	int h = hash(key, N);
	while (tab[h] != 0 && h<=N) {
		if (tab[h] == key)
			break;
		h = (h+1) % N;
	}
	if (tab[h]==0) { /* não encontrou o elemento */
		tab[h] = key;
		return tab;
	}else
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

int main(){
	int m, i, key;
	scanf("%d%*c", &m);
	int *tabelahash = (int*)malloc(sizeof(int)*m);
	for (i=0; i<m;i++){
		tabelahash[i] = 0;
	}
	do{
		scanf("%d%*c", &key);
		if(key)
			insere(tabelahash, key, m);
	}while(key);
	imprimeTabelaHash(tabelahash, m);
	
	return 0;
}