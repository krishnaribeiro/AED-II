#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct dado{
	int key;
	char nome[20];
};typedef struct dado tipoDado;

typedef struct tipoNo{
    tipoDado dado;
    struct tipoNo *prox;
} tipoNo;

typedef struct tipoLista{
    int tamanho;
    tipoNo *prim;
} tipoLista;

void criaLista(tipoLista *lista){
    lista->tamanho = 0;
    lista->prim = NULL;
}

void insereFim(tipoLista *lista, tipoDado novoDado){
    tipoNo *novoNo = (tipoNo*) malloc(sizeof(tipoNo));
	 novoNo->dado = novoDado;
	 if (lista->prim){
		 tipoNo *aux = lista->prim;
		 while (aux->prox != NULL){
			 aux = aux->prox;
		 }
		 novoNo->prox = aux->prox;
		 aux->prox = novoNo;
	 }else{
		 lista->prim = novoNo;
		 novoNo->prox = NULL;
	 }
	 lista->tamanho = lista->tamanho + 1;     
}

int listaVazia(tipoLista lista){
    if(lista.prim == NULL){
        return 1;
    }else{
        return 0;
    }
}

void imprimeLista(tipoLista *lista){
	tipoNo *aux = lista->prim;
	while(aux){
		printf("%d %s\n", aux->dado.key, aux->dado.nome);
		aux = aux->prox;
	}
}

struct hashtab {
	tipoLista* lista;
};typedef struct hashtab HashTab;

int hash (int key, int N){
	return (key%N);
}

void insere (HashTab *tab, int N, int key, char nome[]){
	int h = hash(key, N);
	tipoDado dado;
	dado.key = key;
	strcpy(dado.nome, nome);
	if (tab[h].lista)
		insereFim(tab[h].lista, dado);
	else{
		tipoLista *lista = malloc(sizeof(tipoLista));
		criaLista(lista);
		tab[h].lista = lista;
		insereFim(tab[h].lista, dado);
	}	
}

void imprimeTabelaHash_lista(HashTab* tab, int m){
	int i;
	for (i=0; i< m; i++){
		if (tab[i].lista == NULL)
			printf("%d null null\n", i);
		else{
			tipoNo *aux = tab[i].lista->prim;
			while(aux){
				printf("%d %d %s\n", i, aux->dado.key, aux->dado.nome);
				aux = aux->prox;
			}
		}
	}
	printf("- - -\n");
}

tipoNo* buscaLista(tipoLista *lista, int key){
	tipoNo* aux = lista->prim;
	while(aux){
		if (aux->dado.key == key)
			return aux;
		aux = aux->prox;
	}
	return NULL;
}

tipoDado* busca (HashTab *tab, int key, int N, int*index) {
	int h = hash(key, N);
	tipoNo* aux = malloc(sizeof(tipoNo));
	if (tab[h].lista)
		aux = buscaLista(tab[h].lista, key);
	else
		aux = NULL;
	if (aux != NULL){
		*index = h;
		return &aux->dado;
	}else{
		*index = -1;
		return NULL;
	}
}

int main(){
	int m, i, key;
	tipoDado* x = malloc(sizeof(tipoDado));
	char nome[20];
	
	scanf("%d%*c", &m);
	HashTab *tabelahash = (HashTab*)malloc(sizeof(HashTab)*m);
	for (i=0; i < m; i++){
		tabelahash[i].lista = NULL;
	}
	do{
		scanf("%d%*[ ]%[^\n]%*c", &key, nome);
		if(key){
			insere(tabelahash, m, key, nome);
		}
	}while(key);
	imprimeTabelaHash_lista(tabelahash, m);
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