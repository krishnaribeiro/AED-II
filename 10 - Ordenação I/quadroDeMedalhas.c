#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipoPais {
	char nomes[100];
	int medalhaOuro, medalhaPrata, medalhaBronze;
} tipoPais;

void imprime(tipoPais num[], int tam) {
	int i;
	
	for (i = 0; i < tam; i++){
		printf("%s %d %d %d\n", num[i].nomes, num[i].medalhaOuro, num[i].medalhaPrata, num[i].medalhaBronze);
	}
}

void selection_sort(tipoPais num[], int tam) {
	tipoPais aux;
	int i, j, max;

	for (i = 0; i < (tam-1); i++) {
		max = i;
		for (j = (i+1); j < tam; j++) {
			if(num[j].medalhaOuro > num[max].medalhaOuro)
				max = j;
			else if(num[j].medalhaOuro == num[max].medalhaOuro) {
				if(num[j].medalhaPrata > num[max].medalhaPrata)
					max = j;
				else if (num[j].medalhaPrata == num[max].medalhaPrata){
					if (num[j].medalhaBronze > num[max].medalhaBronze)
						max = j;
					else if(num[j].medalhaBronze == num[max].medalhaBronze) {
						if (strcmp(num[j].nomes, num[max].nomes) < 0) 
							max = j;
					}
				} 
			}
		}
		if (i != max) {
			aux = num[i];
			num[i] = num[max];
			num[max] = aux;
		}
	}
}

int main(){
	int ouro, prata, bronze, m, i;
	tipoPais* x = malloc(sizeof(tipoPais));
	char nome[100];
	
	scanf("%d%*c", &m);
	tipoPais *paises = (tipoPais*)malloc(sizeof(tipoPais)*m);
	
	for (i = 0; i < m; i++) {
		scanf("%[^ ]%*[ ]%d%*[ ]%d%*[ ]%d%*c", nome, &ouro, &prata, &bronze);
		strcpy(paises[i].nomes, nome);
		paises[i].medalhaOuro = ouro;
		paises[i].medalhaPrata = prata;
		paises[i].medalhaBronze = bronze;
	}	
	selection_sort(paises, m);
	imprime(paises, m);
	
}