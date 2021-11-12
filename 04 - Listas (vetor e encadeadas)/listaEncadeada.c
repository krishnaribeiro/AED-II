#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tipoPessoa{
	char nome[15];
	char endereco[20];
	float altura;
} tipoPessoa;

typedef struct tipoNo{
    tipoPessoa dado;
    struct tipoNo *prox;
} tipoNo;

typedef struct tipoLista{
    int tamanho;
    tipoNo *prim;
} tipoLista;


float criaMedia(tipoLista *lista){
	int i;
	float media = 0;
	tipoNo *aux = (tipoNo*) malloc(sizeof(tipoNo));
	aux = lista->prim;
	while(aux != NULL){
		media += aux->dado.altura;
		aux = aux->prox;
		}
	
	return (media/lista->tamanho);
}
void criaLista(tipoLista *lista){
    lista->tamanho = 0;
    lista->prim = NULL;
}

void insereInicio(tipoLista *lista, tipoPessoa novoDado){
    tipoNo *novoNo = (tipoNo*) malloc(sizeof(tipoNo));
    novoNo->dado = novoDado;
    novoNo->prox = NULL;    
    novoNo->prox = lista->prim;
    lista->prim = novoNo;
    lista->tamanho = lista->tamanho + 1;    
}

int listaVazia(tipoLista lista){
    if(lista.prim == NULL){
        return 1;
    }else{
        return 0;
    }
}


int main(){
   tipoLista lista; 
   criaLista(&lista);
	int i, tamanhoLista;
	tipoPessoa *novaPessoa = (tipoPessoa*) malloc(sizeof(tipoPessoa));
		
		do   {
			scanf("%[^\n]%*c", &novaPessoa->nome);
			if (strcmp(novaPessoa->nome,"XXX") == 0) {
				break;
			} else {
			scanf("%[^\n]%*c", &novaPessoa->endereco);
			scanf("%f%*c", &novaPessoa->altura);
			insereInicio(&lista, *novaPessoa);
			} 
		} 
		while(1);
		if(listaVazia(lista)){
			printf("0.00");
		} else{
			printf("%.2f", criaMedia(&lista));
			}
   return 0;
}