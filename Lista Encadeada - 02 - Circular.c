# include <stdio.h>
# include <stdlib.h>

struct listaCirc{
	int info;
	struct listaCirc *prox;
};
typedef struct listaCirc ListaC;

ListaC *inserir(ListaC *l, int n);

main(){
	ListaC *l, *p;
	l = NULL;
	l = inserir(l, 10);
	l = inserir(l, 20);
	l = inserir(l, 30);
	l = inserir(l, 40);
	p = l -> prox;
	puts("Lista Encadeada Circulasr");
	do{
		printf("%d \n", p -> info);
		p = p -> prox;
	}while(p != l -> prox);
	system("pause");
}

ListaC *inserir(ListaC *l, int n){
	ListaC *novo;
	novo = (ListaC *)malloc(sizeof(ListaC));
	novo -> info = n;	
	if(l == NULL){
		novo -> prox = novo;
	} else {
		novo -> prox = l -> prox;
		l -> prox = novo;
	}
	return novo;
}
