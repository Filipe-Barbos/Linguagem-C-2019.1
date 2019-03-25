# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

struct lista{
	int info;
	struct lista *prox;
};
typedef struct lista Lista;

Lista *inserir(Lista *l, int num);
void *inserir2(Lista *l, Lista *p, Lista *i);
void exibir(Lista *l);


main(){
	setlocale(LC_ALL,"Portuguese");
	
	Lista *l, *par, *impar;
	l = NULL;
	int num, op;
	do{
		puts("1 - Inserir número na lista");
		puts("2 - Exibir lista");
		puts("3 - Exibir lista par e impar");
		puts("0 - Sair");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				system("cls");
				printf("Digite um número: ");
				scanf("%d", &num);
				l = inserir(l, num);
				system("cls");
				break;
				
			case 2:
				system("cls");
				exibir(l);
				system("pause");
				system("cls");
				break;
				
			case 3:
				system("cls");
				par = NULL, impar = NULL;
				inserir2(l, par, impar);
				system("pause");
				system("cls");
				break;
				
			case 0:
				exit(1);
				break;
				
			default:
				system("cls");
				puts("Opção inválida.");
				break;
		}
	}while(1);
	
}

Lista *inserir(Lista *l, int num){
	Lista *novo;
	novo = (Lista *)malloc(sizeof(Lista));
	novo -> info = num;
	novo -> prox = l;
	return novo;			
}

void *inserir2(Lista *l, Lista *par, Lista *impar){
	Lista *novo, *p;
	for(p = l; p != NULL; p = p -> prox){
		if(p -> info % 2 == 0){
			par = inserir(par, p -> info);
		} else {
			impar = inserir(impar, p -> info);
		}
	}
	
	puts("--------- Lista Par ---------");
	exibir(par);
	puts("");
	puts("-------- Lista Impar --------");
	exibir(impar);				
}

void exibir(Lista *l){
	Lista *p;
	puts("------ Números na Lista ------");
	for(p = l; p != NULL; p = p -> prox){
		printf("%d ", p -> info);
	}
	puts("");
}

