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



void insereInicio(tipoLista *lista, int novoDado){
    tipoNo *novoNo = (tipoNo*) malloc(sizeof(tipoNo));
    novoNo->dado = novoDado;
    novoNo->prox = NULL;    
    novoNo->prox = lista->prim;
    lista->prim = novoNo;
    lista->tamanho = lista->tamanho + 1;    
}

//Função limpaLista: libera o espaço alocado por cada nó da lista
void limpaLista(tipoLista *lista){
    tipoNo *aux = lista->prim; //Variável auxiliar para percorrer a lista
    while(aux != NULL){
        lista->prim = lista->prim->prox; //Guarda a referência para o próximo elemento
        free(aux); //Libera o espaço de memória ocupado pelo nó
        lista->tamanho = lista->tamanho - 1; //Diminui o tamanho da lista       
        aux = lista->prim; //aux aponta para o próximo nó (se houver)
    }
}

 
int listaVazia(tipoLista lista){
    if(lista.prim == NULL){
        return 1;
    }else{
        return 0;
    }
}

//Função buscaDado: busca um elemento na lista
int buscaDado(tipoLista lista, int dado){
    tipoNo *noAtual = lista.prim;
    while(noAtual != NULL){
        if(noAtual->dado == dado){
            return 1; //Encontrou o elemento
        }else{
            noAtual = noAtual->prox;
        }
    }
    return 0; //Não Achou o elemento     
}
int buscaLista(tipoLista *lista1, tipoLista *lista2){
	tipoNo *aux = lista1->prim;
	
	while(aux != NULL){
		if(buscaDado(*lista2, aux->dado)){
		 return 1;
		}
		aux = aux->prox;
	} return 0;
}
void imprimeLista(tipoLista lista){
    printf("Lista: ");
    while(lista.prim != NULL){
        printf("%d ", lista.prim->dado);
        lista.prim = lista.prim->prox;
    }
    printf("\n");    
}

int main(){
	tipoLista lista1, lista2; 
	criaLista(&lista1); 
	criaLista(&lista2);
	int x;
	
   	do {
			  scanf("%d", &x);
			if(x){
				insereInicio(&lista1, x);
			}
		 } while (getchar() != '\n' && x != 0);
	
		do {
				  scanf("%d", &x);
				if(x){
					insereInicio(&lista2, x);
				}
			 } while (getchar() != '\n' && x !=0);
	if (buscaLista(&lista1, &lista2)){
		printf("SIM");
	} else {
		printf("NAO");
	}
	return 0;
}