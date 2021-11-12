#include <stdio.h>
#include <stdlib.h>

struct arvgen{
  char info;
  struct arvgen *prim;
  struct arvgen *prox;
};
typedef struct arvgen ArvGen;

ArvGen* cria (char c){
   ArvGen* a =(ArvGen*)malloc(sizeof(ArvGen));
   a->info = c;
	a->prim = NULL;
   a->prox = NULL;
   return a;
}

/*void insere(ArvGen* a, ArvGen* f)
{
  f->prox = a->prim;
  a->prim = f;
}*/
void insere(ArvGen* pai, ArvGen* filho){
	ArvGen* aux;
	if(!pai->prim){
		pai->prim = filho;
	}else{
		aux = pai->prim;
		while(aux->prox){
			aux = aux->prox;
		}
		aux->prox = filho;
	}
}


void imprime(ArvGen* a){
  ArvGen* p;
  printf("%c\n", a->info);
  for (p = a->prim; p != NULL; p = p->prox)
    imprime(p);
}

ArvGen* busca(ArvGen* a, char c){
  	ArvGen* p, *aux;
	if (a->info == c){
		//printf("%c, %c\n", a->info, c);
		return a;
	}
		
	else{
		for (p = a->prim; p != NULL; p = p->prox){
			//printf("%c, %c\n", p->info, c);
			aux = busca(p, c);
			if (aux)
				return aux;
		}
	}
  return NULL;
}


void libera(ArvGen* a){
  ArvGen* p = a->prim;
  while (p != NULL)
  {
    ArvGen* t = p->prox;
    libera(p);
    p = t;
  }
  free(a);
}

int main(){
	char a, b, c;
	scanf("%c%*c", &a);
	ArvGen *raiz = cria(a);
	ArvGen *pai, *filho;
	do{
		scanf("%c %c%*c", &b, &c);
		if (b != '#' && c != '#'){
			pai = busca(raiz, c);
			//printf("Pai para inserir: %c -- Filho para inserir: %c ---- ", c, b);
			if (pai){
				filho = cria(b);
				//printf("%c inserido em %c\n", filho->info, pai->info);
				insere(pai, filho);
				
			}
		}
	} while (b != '#' || c != '#');
	imprime(raiz);
   return 0;
}