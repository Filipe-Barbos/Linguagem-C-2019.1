# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

struct produto{
	char nome[50];
	int quantidade;
	float preco;
};
typedef struct produto Produto;

struct listaDupla{
	Produto info;
	struct listaDupla *prox;
	struct listaDupla *ant;
};
typedef struct listaDupla ListaD;

Produto cadastrar();
ListaD *inserir(ListaD *l, Produto prod);
void exibir(ListaD *l);
ListaD *remover(ListaD *l);

main(){
	setlocale(LC_ALL,"Portuguese");
	Produto prod;
	ListaD *l;
	l = NULL;
	int op;
	do{
		puts("1 - Cadastrar produto");
		puts("2 - Exibir produtos cadastrados");
		puts("3 - Excluir produto");
		puts("0 - Sair");
		scanf("%d", &op);
		switch(op){
			case 1:
				system("cls");
				prod = cadastrar();				
				l = inserir(l, prod);
				system("cls");
				break;
				
			case 2:
				system("cls");
				if(l != NULL){
					exibir(l);	
				} else {
					puts("A lista está vazia.");
				}				
				system("pause");
				system("cls");
				break;
			
			case 3:
				system("cls");
				if(l != NULL){
					l = remover(l);
				} else {
					puts("A lista está vazia.");
				}				
				system("pause");
				system("cls");
				break;
				
			case 0:
				exit(1);
				break;
				
			default:
				puts("Opção inválida");
				break;
		}
	}while(1);	
}

Produto cadastrar(){
	Produto p;
	printf("Nome do produto: ");
	fflush(stdin);
	gets(p.nome);
	printf("Quantidade: ");
	scanf("%d", &p.quantidade);
	printf("Preço: ");
	scanf("%f", &p.preco);
	return p;
}

ListaD *inserir(ListaD *l, Produto prod){
	ListaD *novo;
	novo = (ListaD *)malloc(sizeof(ListaD));
	novo -> info = prod;
	novo -> prox = l;
	novo -> ant = NULL;
	if(l != NULL){
		l -> ant = novo;
	}
	return novo;
}

void exibir(ListaD *l){
	ListaD *p;
	p = l;
	puts("---------- Itens Cadastrados ------------");
	do{
		printf("Produto: %s \n",  p -> info.nome);
		printf("Quantidade: %d \n", p -> info.quantidade);
		printf("Preço: %.2f \n", p -> info.preco);
		puts("---------------------------------------");
		p = p -> prox;
	}while(p != NULL);
}

ListaD *remover(ListaD *l){
	ListaD *p, *r;
	char nome[50];
	int comp, resp = 0;
	printf("Nome do produto a remover: ");
	fflush(stdin);
	gets(nome);
	p = l; 

	if(p -> prox == NULL){
		resp = 2;
		comp = strcmp(nome, p -> info.nome);    
	    if(comp == 0){
	        resp = 1;
	        l = NULL;
	        free(p);
		}
	} else {
		comp = strcmp(nome, p -> info.nome);    
	    if(comp == 0){
	        resp = 1;            
	        l = p -> prox;           
		    l -> ant = NULL;	        
		    free(p);
		}
	
		if(resp == 0){
	       do{
	       	if(p -> prox == NULL){
		    	resp = 2;
			} else {
				comp = strcmp(nome, p -> prox -> info.nome);       
		        if(comp == 0){
		            resp = 1;       
		            r = p -> prox;
		            if (r -> prox != NULL){
						p -> prox = r -> prox;
					   	p -> prox -> ant = p;			    
			           	free(r);                	
					} else {
						p -> prox = NULL;
						free(r);
					}
			    }				
			}
			p = p -> prox;
	       }while(resp == 0);
	   	}
	}
    
	if(resp == 1){
		puts("Item removido com sucesso!");
		if(l != NULL){
			exibir(l);	
		}		
	} else if (resp == 2){
		puts("Item não encontrado na lista.");
	}
	return l;
}

