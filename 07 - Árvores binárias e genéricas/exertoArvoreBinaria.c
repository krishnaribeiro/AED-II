#include<stdio.h>
#include<stdlib.h>
struct arv {
	int info;
	struct arv* esq;
	struct arv* dir;
};typedef struct arv Arv;

Arv* cria(int v){
	Arv* a = (Arv*)malloc(sizeof(Arv));
	a->info = v;
	a->esq = NULL;
	a->dir = NULL;
	return a;
}

Arv* busca (Arv* r, int v){
	if (r == NULL) return NULL;
	else if (r->info > v) return busca(r->esq,v);
	else if (r->info < v) return busca(r->dir,v);
	else return r;
}

Arv* insere (Arv* a, int v){
	if (a==NULL) {
		a = (Arv*)malloc(sizeof(Arv));
		a->info = v;
		a->esq = a->dir = NULL;
	}
	else if (v < a->info)
		a->esq = insere(a->esq,v);
	else /* v > a->info */
		a->dir = insere(a->dir,v);
	return a;
}

void insere_arvore (Arv* a, Arv* a2){
	if (a2->info < a->info)
		a->esq = a2;
	else /* v > a->info */
		a->dir = a2;
	return;
}

void imprime(Arv *no){
	if (no == NULL)
		return;
	imprime(no->esq);
	printf("%d\n", no->info);
	imprime(no->dir);
}

Arv* popula_arvore(Arv *raiz){
	int n;
	do{
		scanf("%d%*c", &n);
		if(n){
			if (!raiz){
				raiz = cria(n);
			}else{
				insere(raiz, n);
			}
		}
	}while(n != 0);
	return raiz;
}

void enxerto(Arv* raiz1, Arv* raiz2, int chave){
	//busca chave na raiz1
	Arv *aux = busca(raiz1, chave);
	//inserir raiz2 na arvore encontrada na raiz1
	insere_arvore(aux, raiz2);
	return;
}

int main(){
	int chave;
	Arv* raiz1 = NULL;
	Arv* raiz2 = NULL;
	raiz1 = popula_arvore(raiz1);
	raiz2 = popula_arvore(raiz2);
	scanf("%d%*c", &chave);
	//Arv *aux = busca(raiz1, chave);
	//printf("busca-chave-result: %d\n", aux->info);
	enxerto(raiz1, raiz2, chave);
	imprime(raiz1);
	return 1;
}