#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tipoPrograma{
	char nome[80];
	int cost;
}tipoPrograma;

typedef struct tipoNo{
	tipoPrograma dado;
	struct tipoNo *prox;
}tipoNo;

typedef struct tipoListaCircularEncadeada{
	tipoNo *inicio;
	tipoNo *fim;
	int tamanho;
}tipoListaCircularEncadeada;

void imprimeListaCircularEncadeada(tipoListaCircularEncadeada listaCircularEncadeada){
	tipoNo *noAtual = listaCircularEncadeada.inicio;
	if(noAtual != NULL){
		do{
			printf("%s\t", noAtual->dado.nome);
			noAtual = noAtual->prox;
		}while(noAtual != listaCircularEncadeada.inicio);
		printf("\n");
	}
}

void criaLista(tipoListaCircularEncadeada *lista){
   lista->tamanho = 0;
   lista->inicio = NULL;
	lista->fim = NULL;
}

int listaVazia(tipoListaCircularEncadeada lista){
    if(lista.inicio == NULL){
        return 1;
    }else{
        return 0;
    }
}

void insere(tipoListaCircularEncadeada *lista, tipoPrograma novoDado){
	tipoNo *novoNo = (tipoNo*) malloc(sizeof(tipoNo));
	novoNo->dado = novoDado;
	novoNo->prox = NULL;
	if (!listaVazia(*lista)){
		novoNo->prox = lista->inicio;
		lista->fim->prox = novoNo;
		lista->fim = novoNo;
	}else{
		lista->inicio = novoNo;
		lista->fim = novoNo;
		novoNo->prox = novoNo;
	}
	lista->tamanho = lista->tamanho + 1;
}

int removeNo(tipoListaCircularEncadeada *lista, tipoPrograma dado){
	tipoNo *noAtual = lista->inicio;
	tipoNo *noPost;
	int found = 0;
	if(noAtual != NULL){
		do{
			noPost = noAtual->prox;
			//Procura dado na lista
			if (strcmp(noPost->dado.nome, dado.nome) == 0){found = 1;break;}
			noAtual = noAtual->prox;
		}while(noAtual != lista->inicio);
		if (found){
			if (lista->tamanho == 1){
				free(lista->inicio);
				lista->inicio = NULL;
				lista->fim = NULL;
			}else{
				
				noAtual->prox = noPost->prox;
				if (noPost == lista->inicio){
					lista->inicio = noPost->prox;
				}
			}
			lista->tamanho --;
			return 1;
		}
	}return 0;
}


void processa(tipoListaCircularEncadeada *lista, int q){
	tipoNo* noAtual = lista->inicio;
	int current_time = 0;
	while(lista->tamanho > 0){
		if (noAtual->dado.cost - q > 0){
			noAtual->dado.cost -= q;
			current_time += q;
		}else{
			current_time += noAtual->dado.cost;
			printf("%d us: %s finalizou\n", current_time, noAtual->dado.nome);
			removeNo(lista, noAtual->dado);
		}
		noAtual = noAtual->prox;
	}
}

int main(){
   tipoListaCircularEncadeada lista;
   criaLista(&lista);
	int q, n;
	scanf("%d %d%*c", &q, &n);
	char nome[81];
	int t;
	tipoPrograma *prog = (tipoPrograma*)malloc(sizeof(tipoPrograma));
	while(n>0){
		scanf("%[^ ]%*c%d%*c", &nome, &t);
		strcpy(prog->nome, nome);
		prog->cost = t;
		insere(&lista, *prog);
		n--;
	}
	processa(&lista, q);
   return 0;
}
