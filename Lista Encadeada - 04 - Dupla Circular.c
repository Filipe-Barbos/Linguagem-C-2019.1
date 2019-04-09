# include <stdio.h>
# include <stdlib.h>

struct listaDuplaCircular{
	int info;
	struct listaDuplaCircular * prox;
	struct listaDuplaCircular * ant;
};
typedef struct listaDuplaCircular ListaDC;

ListaDC *inserir(ListaDC *l, int n);

main(){
	ListaDC *l,*p;
	l = NULL;	
	l = inserir(l, 600);
	l = inserir(l, 700);
	l = inserir(l, 800);
	l = inserir(l, 900);
	l = inserir(l, 1000);
	p = l -> prox;
	puts("Lista Encadeada Dupla Circular");
	do{
		printf("%d \n", p -> info);
		p = p -> prox;
	}while(p != l -> prox);	
	system("pause");		
}

ListaDC *inserir(ListaDC *l, int n){
	ListaDC *novo;
	novo = (ListaDC *)malloc(sizeof(ListaDC));
	novo -> info = n;
	if(l == NULL){
		novo -> prox = novo;
		novo -> ant = novo;
	} else {
		novo -> prox = l -> prox;
		l -> prox = novo;
		novo -> ant = l;
		novo -> prox -> ant = novo;		
	}
	return novo;
}
