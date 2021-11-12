#include<stdio.h>
#include<stdlib.h>

typedef struct tipoListaVetor{
    int *dados;
    int tamanho;
}tipoListaVetor;

#define MAX 15

void inicializaListaVetor(tipoListaVetor *listaVetor, int tam){
    listaVetor->dados = (int*) malloc(sizeof(int)*tam);
    listaVetor->tamanho = 0;
}


void imprimeListaVetor(tipoListaVetor listaVetor){
    int i;
    for(i = 0; i < listaVetor.tamanho; i++){
        printf("%d ", listaVetor.dados[i]);
    }
    printf("\n");
}

int insereFimListaVetor(tipoListaVetor *listaVetor, int dado, int tam){
    if(listaVetor->tamanho == tam){
        return 0; //A lista está cheia
    }
    listaVetor->dados[listaVetor->tamanho] = dado;
    listaVetor->tamanho = listaVetor->tamanho + 1;
    return 1; //Inserção concluída
}

int limpaListaVetor(tipoListaVetor *listaVetor){
    if(listaVetor->dados != NULL){
        free(listaVetor->dados);
        listaVetor->tamanho = 0;
        return 1; //Operação concluída
    }
    return 0; //A lista não está inicializada
}

void concatenaListaVetor(tipoListaVetor *listaVetor1, tipoListaVetor *listaVetor2, tipoListaVetor *listaVetor3) {
    int i;
    for(i = 0; i < listaVetor1->tamanho; i++){
        insereFimListaVetor(listaVetor3, listaVetor1->dados[i], listaVetor1->tamanho+listaVetor2->tamanho);
    }
    for(i = 0; i < listaVetor2->tamanho; i++){
        insereFimListaVetor(listaVetor3, listaVetor2->dados[i], listaVetor1->tamanho+listaVetor2->tamanho);
    }
}

int main(){
    int count = 0;
    int aux, tam1, tam2;
    tipoListaVetor listaVetor1, listaVetor2, listaVetor3;

    scanf("%d", &tam1);
    inicializaListaVetor(&listaVetor1, tam1);
    do {
        scanf("%d", &aux);
        count++;
        if (count <= MAX){
            insereFimListaVetor(&listaVetor1, aux, tam1);
        }
    } while (getchar() != '\n' && count < tam1);

    scanf("%d", &tam2);
    count = 0;
    inicializaListaVetor(&listaVetor2, tam2);
    do {
        scanf("%d", &aux);
        count++;
		 if (count <= MAX){
        insereFimListaVetor(&listaVetor2, aux, tam2);
		 }
        } while (getchar() != '\n' && count < tam2);

    inicializaListaVetor(&listaVetor3, tam1+tam2);
    concatenaListaVetor(&listaVetor1, &listaVetor2, &listaVetor3);
    imprimeListaVetor(listaVetor3);

    return 0;
}