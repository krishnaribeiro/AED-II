#include <stdio.h>
#include <stdlib.h>

void print_matriz(int **matriz, int n){
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++) {
        printf("%d ", matriz[i][j]);
        }
    printf("\n");
	}
	printf("\n");
}

int check101 (int **matriz, int i, int j, int n){
	int changed = 0;
	if (matriz[i][j] == 2) {
		
		if(i+1 < n && i-1 >= 0){
			if (matriz[i+1][j] == matriz[i-1][j] && matriz[i+1][j] != 2) {
				matriz[i][j] = !matriz[i+1][j];
				changed = 1;
			}
		}
	   if(j+1 < n && j-1 >= 0){
			if (matriz[i][j+1] == matriz[i][j-1] && matriz[i][j+1] != 2) {
				matriz[i][j] = !matriz[i][j+1];
				changed = 1;
			}
		}
}
	return changed;
}
int checkpair (int **matriz, int i, int j, int n){
	int changed = 0;
	if(i+1 < n && matriz[i][j] != 2){
		if (matriz[i+1][j] == matriz[i][j]){
			if(i+2 < n) {
				if(matriz[i+2][j] == 2) {
					matriz[i+2][j] = !matriz[i][j];
					changed = 1;
				}
			}
		}
	} if(j+1 < n && matriz[i][j] != 2){
		if (matriz[i][j+1] == matriz[i][j]){
			if(j+2 < n) {
				if(matriz[i][j+2] == 2) {
					matriz[i][j+2] = !matriz[i][j];
					changed = 1;
				}
			}
		}
	} if(i-1 >= 0 && matriz[i][j] != 2){
		if (matriz[i-1][j] == matriz[i][j]){
			if(i-2 >= 0) {
				if(matriz[i-2][j] == 2) {
					matriz[i-2][j] = !matriz[i][j];
					changed = 1;
				}
			}
		}
	} if(j-1 >= 0 && matriz[i][j] != 2){
		if (matriz[i][j-1] == matriz[i][j]){
			if(j-2 >= 0) {
				if(matriz[i][j-2] == 2) {
					matriz[i][j-2] = !matriz[i][j];
					changed = 1;
				}
			}
		}
	}
	return changed;
}
	
void binarypuzzle (int **matriz, int n){
	int run = 1;
	int changed = 0;
	int i, j;
	while(run) { 
		changed = 0;
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++) {
				changed = checkpair(matriz, i, j, n);
				if (changed){break;}
				changed = check101(matriz, i, j, n);
				if (changed){break;}
			}
			if (changed){break;}
      } 
	if (changed){continue;}
	if (!changed){break;}
	}
}



int main() {
	
int i, j, count = 0;
int n = 6;

	
int **matriz1 = (int **)malloc(n * sizeof(int*));
	for(i = 0; i < n; i++){
		matriz1[i] = (int *)malloc(n * sizeof(int));
	}
	
	for(i = 0; i < n; i++){
		do {
			  scanf("%d", &matriz1[i][count++]);
		 } while (getchar() != '\n' && count < n);
		count = 0;
	}

	binarypuzzle(matriz1, n);
	printf("\n");
	print_matriz(matriz1, n);
}


