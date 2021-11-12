#include<stdio.h>
#include<stdlib.h>

typedef struct tipoNo{
    float dado;
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

void insereInicio(tipoLista *lista, float novoDado){
    tipoNo *novoNo = (tipoNo*) malloc(sizeof(tipoNo));
    novoNo->dado = novoDado;
    novoNo->prox = NULL;    
    novoNo->prox = lista->prim;
    lista->prim = novoNo;
    lista->tamanho = lista->tamanho + 1;    
}

void limpaLista(tipoLista *lista){
    tipoNo *aux = lista->prim; 
    while(aux != NULL){
		lista->prim = lista->prim->prox; 
		free(aux); 
		lista->tamanho = lista->tamanho - 1;        
      aux = lista->prim; 
    }
}

void insereFim(tipoLista *lista, float novoDado){
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

void imprimeLista(tipoLista lista){
    while(lista.prim != NULL){
        printf("%.1f ", lista.prim->dado);
        lista.prim = lista.prim->prox;
    }
}

float npop(tipoLista *lista){
	float dado;
	dado = lista->prim->dado;
	free(lista->prim);
	lista->prim = lista->prim->prox;
	lista->tamanho--;
	
	return dado;
}

int par(int i){
	if (i%2==0){
		return 1;
	}
	else{
		return 0;
	}
}

void merge(tipoLista *lista1, tipoLista *lista2, tipoLista *lista3){
	int i;
	int tam3 = lista1->tamanho + lista2->tamanho;
	float aux;
	for (i = 0; i < tam3; i++){
		if (lista1->tamanho && lista2->tamanho){
			if(par(i)){
				aux = npop(lista1);
				insereFim(lista3, aux);
			}else{
				aux = npop(lista2);
				insereFim(lista3, aux);
			}
		}else if (!lista1->tamanho){
			aux = npop(lista2);
			insereFim(lista3, aux);
		}else{
			aux = npop(lista1);
			insereFim(lista3, aux);
		}
	}
}

int main(){
	tipoLista lista1, lista2, lista3; 
	criaLista(&lista1); 
	criaLista(&lista2);
	criaLista(&lista3);
	float x;
	int tam1, tam2;
	int count = 0;
	scanf("%d", &tam1);
	if (tam1){
			do {
				scanf("%f", &x);
				insereInicio(&lista1, x);
				count++;
			 } while (getchar() != '\n' && count < tam1);
	}
	scanf("%d", &tam2);
	count = 0;
	if (tam2){
		do {
			scanf("%f", &x);
			insereInicio(&lista2, x);
			count++;
			 } while (getchar() != '\n' && count < tam2);
	}
	merge(&lista1, &lista2, &lista3);
	imprimeLista(lista3);
	limpaLista(&lista1);
	limpaLista(&lista2);
	limpaLista(&lista3);
	return 0;
}