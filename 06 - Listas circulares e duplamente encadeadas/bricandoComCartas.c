#include<stdio.h>
#include<stdlib.h>

typedef struct tipoNo{
   int dado;
   struct tipoNo *prox;
	struct tipoNo *ante;
} tipoNo;

typedef struct tipoLista{
   int tamanho;
   tipoNo *prim;
	tipoNo *ult;
} tipoLista;

void criaLista(tipoLista *lista){
   lista->tamanho = 0;
   lista->prim = NULL;
	lista->ult = NULL;
}

int listaVazia(tipoLista lista){
    if(lista.prim == NULL && lista.ult == NULL){
        return 1;
    }else{
        return 0;
    }
}

void insereInicio(tipoLista *lista, int novoDado){
   tipoNo *novoNo = (tipoNo*) malloc(sizeof(tipoNo));
	novoNo->dado = novoDado;
	novoNo->prox = NULL;
	novoNo->ante = NULL;
	if (!listaVazia(*lista)){
		novoNo->prox = lista->prim;
		novoNo->prox->ante = novoNo;
		lista->prim = novoNo;
		lista->tamanho = lista->tamanho + 1;    
	}else{
		lista->prim = novoNo;
		lista->ult = novoNo;
		lista->tamanho = lista->tamanho + 1;
	}
}

void insereFim(tipoLista *lista, int novoDado){
   tipoNo *novoNo = (tipoNo*) malloc(sizeof(tipoNo));
	novoNo->dado = novoDado;
	novoNo->prox = NULL; 
	novoNo->ante = NULL;
	if (!listaVazia(*lista)){
		novoNo->ante = lista->ult;
		lista->ult->prox = novoNo;
		lista->ult = novoNo;
		lista->tamanho = lista->tamanho + 1;    
	}else{
		lista->ult = novoNo;
		lista->prim = novoNo;
		lista->tamanho = lista->tamanho + 1;
	} 
}

tipoNo* removeFim(tipoLista *lista){
	if (lista->tamanho>1){
		tipoNo* aux = lista->ult;
		lista->ult = lista->ult->ante;
		lista->ult->prox = NULL;
		lista->tamanho = lista->tamanho-1;
		return aux;
	}else{
		return NULL;
	}
	
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

void imprimeLista(tipoLista lista, char* pref){
    printf("%s", pref);
    while(lista.prim != NULL){
		 if (lista.prim->prox){
			 printf("%d, ", lista.prim->dado);
		 }else{
			 printf("%d", lista.prim->dado);
		 }
       lista.prim = lista.prim->prox;
    }
    printf("\n");    
}
void printl(tipoLista lista){
    while(lista.prim != NULL){
		 printf("%d, ", lista.prim->dado);		 
       lista.prim = lista.prim->prox;
    }
    printf("\n");
}
void play(tipoLista *lista){
	tipoLista lista_descartados; 
   criaLista(&lista_descartados);
	tipoNo *aux = (tipoNo*)malloc(sizeof(tipoNo));
	
	while (lista->tamanho > 1){
		aux = removeFim(lista);
		if(aux){insereFim(&lista_descartados, aux->dado);}
		aux = removeFim(lista);
		if(aux){insereInicio(lista, aux->dado);}
	}
	imprimeLista(lista_descartados, "Descartadas: ");
	imprimeLista(*lista, "Restou: ");
	limpaLista(lista); limpaLista(&lista_descartados);
}

void prep(int n){
   tipoLista lista; 
   criaLista(&lista);
	int i;
	for (i=1; i<=n; i++){
		insereInicio(&lista, i);
	}
	play(&lista);
	limpaLista(&lista);
}

int main(){ 
	int n;
	do{
		scanf("%d", &n);
		if(n){prep(n);}
	}while(n);

   return 0;
}