#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tipoNo{
	float dado;
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
		printf("|%f|\n", pilha.topo->dado);
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

void push(tipoPilha *pilha, float novoDado){
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

float calcula(char operacao[100]){
	tipoPilha pilha;
	criaPilha(&pilha);
	char delim[] = " ";
	char *ptr = strtok(operacao, delim);
	float n;
	float n1, n2;
	while(ptr != NULL)
	{
		if (strlen(ptr) > 1){
			n = atof(ptr);
			push(&pilha, n);
		}else{
			if(ptr[0] >= 48 && ptr[0] <= 57){
				n = atof(ptr);
				push(&pilha, n);
			}else{
				switch (ptr[0]){
					case '#':
						//soma
						n1 = pop(&pilha)->dado;
						n2 = pop(&pilha)->dado;
						push(&pilha, n2+n1);
						break;
					case '*':
						//multiplica
						n1 = pop(&pilha)->dado;
						n2 = pop(&pilha)->dado;
						push(&pilha, n2*n1);
						break;
					case '-':
						//subtrai
						n1 = pop(&pilha)->dado;
						n2 = pop(&pilha)->dado;
						push(&pilha, n2-n1);
						break;
					case '/':
						//divide
						n1 = pop(&pilha)->dado;
						n2 = pop(&pilha)->dado;
						push(&pilha, n2/n1);
						break;
					default:
						break;
				}
			}
		}
		ptr = strtok(NULL, delim);
	}
	return pilha.topo->dado;
}

int main(){
	
	char operacao[100];
	int n, i;
	scanf("%d%*c", &n);

	for(i = 0; i < n; i++){
		scanf("%[^'.']%*c", operacao);
		printf("\n%.2f\n", calcula(operacao));
	}
}