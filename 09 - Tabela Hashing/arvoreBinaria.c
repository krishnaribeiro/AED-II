#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct dado{
	int key;
	char nome[20];
};typedef struct dado TipoDado;

struct arv {
	TipoDado info;
	struct arv* esq;
	struct arv* dir;
};typedef struct arv Arv;

Arv* cria_arv(TipoDado v){
	Arv* a = (Arv*)malloc(sizeof(Arv));
	a->info = v;
	a->esq = NULL;
	a->dir = NULL;
	return a;
}

Arv* busca_arv(Arv* r, int v){
	if (r == NULL) return NULL;
	else if (r->info.key > v) return busca_arv(r->esq,v);
	else if (r->info.key < v) return busca_arv(r->dir,v);
	else return r;
}

Arv* insere_arv(Arv* a, TipoDado v){
	if (a==NULL) {
		a = (Arv*)malloc(sizeof(Arv));
		a->info = v;
		a->esq = a->dir = NULL;
	}
	else if (v.key < a->info.key)
		a->esq = insere_arv(a->esq,v);
	else /* v > a->info */
		a->dir = insere_arv(a->dir,v);
	return a;
}

void imprime_arv(Arv *no){
	if (no == NULL)
		return;
	imprime_arv(no->esq);
	printf("%d %s ", no->info.key, no->info.nome);
	imprime_arv(no->dir);
}

struct hashtab {
	Arv* abb;
};typedef struct hashtab HashTab;

int hash (int key, int N){
	return (key%N);
}

void insere (HashTab *tab, int N, int key, char nome[]){
	int h = hash(key, N);
	TipoDado dado;
	dado.key = key;
	strcpy(dado.nome, nome);
	if (tab[h].abb)
		insere_arv(tab[h].abb, dado);
	else
		tab[h].abb = cria_arv(dado);
}

void imprimeTabelaHash_abb(HashTab* tab, int m){
	int i;
	for (i=0; i< m; i++){
		if (tab[i].abb == NULL)
			printf("%d null\n", i);
		else{
			printf("%d ", i);
			imprime_arv(tab[i].abb);
			printf("\n");
		}
	}
	printf("- - -\n");
}
TipoDado* busca (HashTab *tab, int key, int N, int*index) {
	int h = hash(key, N);
	Arv* aux = busca_arv(tab[h].abb, key);
	if (aux){
		*index = h;
		return &aux->info;
	}
	else{
		*index = -1;
		return NULL;
	}
		
}

int main(){
	int m, i, key;
	TipoDado* x = malloc(sizeof(TipoDado));
	char nome[20];
	
	scanf("%d%*c", &m);
	HashTab *tabelahash = (HashTab*)malloc(sizeof(HashTab)*m);
	for (i=0; i < m; i++){
		tabelahash[i].abb = NULL;
	}
	do{
		scanf("%d%*[ ]%[^\n]%*c", &key, nome);
		if(key){
			//printf("%d %s\n", key, nome);
			insere(tabelahash, m, key, nome);
				//printf("%d %s", tmp->mat, tmp->nome);
			
		}
	}while(key);
	imprimeTabelaHash_abb(tabelahash, m);
	int *index = malloc(sizeof(int));
	do{
		scanf("%d%*c", &key);
		if(key){
			x = busca(tabelahash, key, m, index);
			if (!x){
				printf("%d not found\n", key);
			} else {
				printf("%d %d %s\n", *index, x->key, x->nome);
			}
		}
	}while(key);
	return 0;
}