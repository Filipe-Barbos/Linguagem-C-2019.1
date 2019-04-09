# include <stdio.h>
# include <stdlib.h>

struct listaDupla{
	int info;
	struct listaDupla *prox;
	struct listaDupla *ant;
};
typedef struct listaDupla ListaD;

ListaD *inserir(ListaD *l, int n);

main(){
	ListaD *l, *p;
	l = NULL;
	l = inserir(l, 100);
	l = inserir(l, 200);
	l = inserir(l, 300);
	l = inserir(l, 400);
	l = inserir(l, 500);
	p = l;
	puts("Lista Encadeada Dupla");
	do{
		printf("%d \n", p -> info);		
		p = p -> prox;
	}while(p != NULL);	
	system("pause");
}

ListaD *inserir(ListaD *l, int n){
	ListaD *novo;
	novo = (ListaD *)malloc(sizeof(ListaD));
	novo -> info = n;
	novo -> prox = l;
	novo -> ant = NULL;
	if(l != NULL){
		l -> ant = novo;		
	}
	return novo;
}
