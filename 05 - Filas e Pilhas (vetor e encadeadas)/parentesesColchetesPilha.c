#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tipoNo{
	char dado;
	struct tipoNo *prox;
} tipoNo;
typedef struct tipoPilha{
	int tamanho;
	tipoNo *topo;
} tipoPilha;

void criaPilha(tipoPilha *pilha){
	pilha->tamanho = 0;
	pilha->topo = NULL;
}
int pilhaVazia(tipoPilha pilha){
	if(pilha.topo == NULL){
		return 1;
	}else{
		return 0;
	}
}

void imprimePilha(tipoPilha pilha){
	printf("Pilha:\n");
	while(pilha.topo != NULL){
		printf("|%s|\n", pilha.topo->dado);
		pilha.topo = pilha.topo->prox;
	}
}

void limpaPilha(tipoPilha *pilha){
	tipoNo *aux = pilha->topo;
	while(aux != NULL){
		pilha->topo = pilha->topo->prox;
		free(aux);
		pilha->tamanho = pilha->tamanho -1;
		aux = pilha->topo;
	}
}

void push(tipoPilha *pilha, char novoDado){
	tipoNo *novoNo = (tipoNo*) malloc(sizeof(tipoNo));
	novoNo->dado = novoDado;
	novoNo->prox = pilha->topo;
	pilha->topo = novoNo;
	pilha->tamanho = pilha->tamanho + 1;
}

tipoNo *pop(tipoPilha *pilha){
	if(!pilhaVazia(*pilha)){
		tipoNo *noDesempilhado = pilha->topo;
		pilha->topo = pilha->topo->prox;

		if(noDesempilhado->prox != NULL){
			noDesempilhado->prox = NULL;
		}
		pilha->tamanho = pilha->tamanho - 1;
		return noDesempilhado;
	}else{
		return NULL;
	}
}

int verifica(char operacao[]){
	tipoPilha pilha;
	criaPilha(&pilha);
	int i;
	int tam = strlen(operacao);
	tipoNo *aux;
	for (i = 0; i < tam; i++){
		if(operacao[i] == '(' || operacao[i] == '[' || operacao[i] == '{'){
			push(&pilha, operacao[i]);
		} else {
			if(operacao[i] == ')'){
				aux = pop(&pilha);
				if (aux){
					if ((aux->dado)+1 != operacao[i]){
						return 0;
					}
				}else{
						return 0;
					}
			} else{
				aux = pop(&pilha);
				if (aux){
					if ((aux->dado)+2 != operacao[i]){
						return 0;
					}
				}else{
						return 0;
				}
			}
		}
	}	if(pilha.tamanho == 0)  {return 1;}
	else {return 0;}
	free(aux);
}

int main(){
	char S[101];
	
	do{
		scanf("%s", S);
		if(strcmp(S, "###") != 0){
			if (verifica(S)){
				printf("SIM\n");
			}else{
				printf("NAO\n");
			}	
		}
	}while(strcmp(S, "###") !=0 );
	
}