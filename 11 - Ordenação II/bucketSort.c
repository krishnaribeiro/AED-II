#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tipoDado{
	int key;
} tipoDado;

typedef struct tipoNo{
    tipoDado dado;
    struct tipoNo *prox;
} tipoNo;

typedef struct tipoLista{
    int tamanho;
    tipoNo *prim;
} tipoLista;

typedef struct bucket {
	tipoLista* lista;
} bucket;


void criaLista(tipoLista *lista){
    lista->tamanho = 0;
    lista->prim = NULL;
}

void insereFim(tipoLista *lista, tipoDado novoDado){
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


int indice (int key, int N, int m){
	return (key*m)/(N+1);
}

void insere (bucket *listaBuckets, int tamMax, int key, int tamBucket){
	int h = indice(key, tamMax, tamBucket);
	tipoDado dado;
	dado.key = key;
	if (listaBuckets[h].lista)
		insereFim(listaBuckets[h].lista, dado);
	else{
		tipoLista *lista = malloc(sizeof(tipoLista));
		criaLista(lista);
		listaBuckets[h].lista = lista;
		insereFim(listaBuckets[h].lista, dado);
	}	
}
void sort(tipoLista *lista)
{
    int i,j,a;

    tipoNo *temp1;
    tipoNo *temp2;

    for(temp1=lista->prim;temp1!=NULL;temp1=temp1->prox)
      {
        for(temp2=temp1->prox;temp2!=NULL;temp2=temp2->prox)
          { 
            if(temp2->dado.key < temp1->dado.key)
              {
                a = temp1->dado.key;
                temp1->dado.key = temp2->dado.key;
                temp2->dado.key = a;
              }
           }
       }
}

void bucketSort(bucket *listaDeBuckets, int *vet, int tamBucket){
	int i;
	int j = 0;
	tipoNo *aux;
	
	for(i = 0; i < tamBucket; i++){
		if(listaDeBuckets[i].lista){
			sort(listaDeBuckets[i].lista);	
		}
	} for(i = 0; i < tamBucket; i++){
		if (listaDeBuckets[i].lista){
			aux = listaDeBuckets[i].lista->prim;
			while(aux){
				vet[j] = aux->dado.key;
				aux = aux->prox;
				j++;			
			}
		}
	} 
}


void imprimeBucketSort(bucket* tab, int m){
	int i;
	for (i=0; i< m; i++){
		if (tab[i].lista == NULL)
			printf("%d NULL\n", i);
		else{
			tipoNo *aux = tab[i].lista->prim;
			printf("%d ", i);
			while(aux){
				printf("%d ", aux->dado.key);
				aux = aux->prox;
			}
			printf("\n");
		}
	}
}


int main(){
	int tamBucket, tamLista, tamMax, key, i, count;
	
	tipoDado* x = malloc(sizeof(tipoDado));
	
	scanf("%d %d %d%*c", &tamBucket, &tamLista, &tamMax);
	
	bucket *listaDeBuckets = (bucket*)malloc(sizeof(bucket)*tamBucket);
	
	int *vet = malloc(sizeof(int)*tamLista);
	
	for (i=0; i < tamBucket; i++){
		listaDeBuckets[i].lista = NULL;
	}
	do{
		scanf("%d", &key);
		vet[count] = key;
		count++;
		
	} while (getchar() != '\n' && count < tamLista);
	for(i = 0; i < tamLista; i++) {
		insere(listaDeBuckets, tamMax, vet[i], tamBucket);
	}
	bucketSort(listaDeBuckets, vet, tamBucket);
	imprimeBucketSort(listaDeBuckets, tamBucket);
	for (i = 0; i < tamLista; i++){
		printf("%d ", vet[i]);
	}
	return 0;
}