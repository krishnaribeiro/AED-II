#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tipoNo{
    char dado[8];
    struct tipoNo *prox;
} tipoNo;

typedef struct tipoFila{
    int tamanho;
    tipoNo *prim; 
    tipoNo *ult; 
} tipoFila;

void criaFila(tipoFila *fila){
    fila->tamanho = 0;
    fila->prim = NULL;
    fila->ult = NULL;
}

void enqueue(tipoFila *fila, char novoDado[8]){
    tipoNo *novoNo = (tipoNo*) malloc(sizeof(tipoNo));
    strcpy(novoNo->dado, novoDado);
    novoNo->prox = NULL;
    if(fila->prim == NULL){
        fila->prim = novoNo;
        fila->ult = novoNo;    
    }else{
        fila->ult->prox = novoNo;
        fila->ult = novoNo;                
    }
    fila->tamanho = fila->tamanho + 1;
}
 
int filaVazia(tipoFila fila){
    if(fila.prim == NULL){
        return 1;
    }else{
        return 0;
    }
}

tipoNo *dequeue(tipoFila *fila){
    if(!filaVazia(*fila)){
        tipoNo *noDesenfileirado = fila->prim;
        fila->prim = fila->prim->prox;
        noDesenfileirado->prox = NULL;
        if(filaVazia(*fila)){
            fila->ult = NULL;
        }
        fila->tamanho = fila->tamanho - 1;
        return noDesenfileirado;
    }else{
        return NULL;
    }    
}


void limpaFila(tipoFila *fila){
    tipoNo *aux = fila->prim; 
    while(aux != NULL){
        fila->prim = fila->prim->prox; 
        free(aux); 
        fila->tamanho = fila->tamanho - 1;        
        aux = fila->prim; 
    }
}

void tamanhoFila(tipoFila fila){
    printf("Tamanho da Fila: %d\n", fila.tamanho);
}


void imprimeFila(tipoFila fila){
    while(fila.prim != NULL){
        printf("%s\n", fila.prim->dado);
        fila.prim = fila.prim->prox;
    } 
}

void controle_decolagem(tipoFila *fila, char command[10]){
	char *aviao;
	int i = 0;
	switch(command[0]){
	
		case 'Q':
			printf("%d\n", fila->tamanho);
		break;
			
		case 'D':
			dequeue(fila);
		break;
			
		case 'L':
			imprimeFila(*fila);
		break;
			
		case 'A':
			aviao = (char*) malloc(sizeof(char)*(strlen(command)-2));
			for (i = 2; i < strlen(command); i++){
				aviao[i-2] = command[i];	
			}
		enqueue(fila, aviao);
		break;
			
		case 'P':
			if(!filaVazia(*fila)){
				printf("%s\n", fila->prim->dado);
			}
		break;
	
		case 'S':
		limpaFila(fila);
		break;
			
		default:
		break;
	}
}

int main(){
	tipoFila fila; 
	criaFila(&fila); 
	char command[10];
	
	do{
		scanf("%[^\n]%*c", &command);
		controle_decolagem(&fila, command);
	}while(command[0] != 'S');

    return 0;
}