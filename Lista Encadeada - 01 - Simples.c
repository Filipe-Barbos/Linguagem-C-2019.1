# include <stdio.h>
# include <stdlib.h>

struct lista{
	int info;
	struct lista *prox;
};
typedef struct lista Lista;

Lista *inserir(Lista *l, int n);

main(){
	Lista *l, *p;	
	l = NULL;	
	l = inserir(l, 10);	
	l = inserir(l, 20);
	l = inserir(l, 30);
	l = inserir(l, 40);
	l = inserir(l, 50);
	p = l;
	puts("Lista Encadeada Simples");
	do{
		printf("%d \n", p -> info);
		p = p -> prox;
	}while(p != NULL);
	system("pause");
}

Lista *inserir(Lista *l, int n){
	Lista *novo;
	novo = (Lista *)malloc(sizeof(Lista));
	novo -> info = n;
	novo -> prox = l;
	return novo;
}
