#include<stdio.h>
#include<stdlib.h>

typedef struct tipoNo{
    int dado;
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

void insereFim(tipoLista *lista, int novoDado){
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
        printf("%d ", lista.prim->dado);
        lista.prim = lista.prim->prox;
    }
    printf("\n");    
}

tipoNo* inverte(tipoNo *no, tipoLista *lista2){
	if(!no->prox){
		insereFim(lista2, no->dado);
		return no;
	}
	inverte(no->prox, lista2);
	insereFim(lista2, no->dado);
	return no;
}
int main(){
	tipoLista lista1; 
	criaLista(&lista1);
	tipoLista lista2;	
	criaLista(&lista2);
	int x;
	
   	do {
			  scanf("%d", &x);
			if(x){
				insereFim(&lista1, x);
			}
		 } while (getchar() != '\n' && x != 0);
	inverte(lista1.prim, &lista2);
	imprimeLista(lista2);
	return 0;
}