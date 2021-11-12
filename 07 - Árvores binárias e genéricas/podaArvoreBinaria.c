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

void imprime(Arv *no){
	if (no == NULL)
		return;
	imprime(no->esq);
	printf("%d\n", no->info);
	imprime(no->dir);
}

Arv* removeEmCascata(Arv* r){
	if(r == NULL){
		return NULL;
	}else{
		removeEmCascata(r->dir);
		removeEmCascata(r->esq);
		free(r);
	}
	return NULL;
}

void poda(Arv* raiz, int chave){
	Arv *aux = busca(raiz, chave);
	if (aux){
		removeEmCascata(aux->dir);
		aux->dir = NULL;
	}
}

int main(){
	int n;
	Arv* raiz = NULL;
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
	int chave;
	scanf("%d%*c", &chave);
	poda(raiz, chave);
	imprime(raiz);
	return 1;
}