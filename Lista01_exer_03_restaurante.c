# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

struct restaurante{
	char nome[100], endereco[100], comida[100];
	float preco;	
};
typedef struct restaurante Restaurante;

struct lista{
	Restaurante info;
	struct lista *prox;
};
typedef struct lista Lista;

Lista *inserir(Lista *l, Restaurante rest);
Restaurante cadastrar();
void *exibir(Lista *l);
void *pesquisar(Lista *l);

main(){
	setlocale(LC_ALL,"Portuguese");
	
	Restaurante rest;
	Lista *l, *p;
	l = NULL;
	int op;
	
	do{
		puts("-------------- Menu -------------");
		puts("1 - Cadastrar tipo de comida");
		puts("2 - Listar todos os itens cadastradas");
		puts("3 - Pesquisar por elemento");
		puts("0 - Sair");
		scanf("%d", &op);
		
		switch (op){
			case 1:
				rest = cadastrar();
				l = inserir(l, rest);
				break;
			
			case 2:				
				exibir(l);
				break;
				
			case 3:
				pesquisar(l);
				break;
				
			case 0:
				exit(1);
				break;
				
			default:
				puts("Opção inválida");
				break;
		}
		
	}while(1);
	
	system("pause");
}

// Funções

Lista *inserir(Lista *l, Restaurante rest){
	Lista *novo;
	novo = (Lista *)malloc(sizeof(Lista));
	novo -> info = rest;
	novo -> prox = l;
	return novo;
}

Restaurante cadastrar(){
	Restaurante rest;
	puts("----------- Cadastrar ----------");
	printf("Nome do restaurante: ");
	fflush(stdin);
	gets(rest.nome);
	printf("Endereço: ");
	fflush(stdin);
	gets(rest.endereco);
	printf("Tipo de comida: ");
	fflush(stdin);
	gets(rest.comida);
	printf("Preço: ");
	scanf("%f", &rest.preco);
	return rest;	
}

void *exibir(Lista *l){
	Lista *p;
	system("cls");
	puts("------ Listando Todos Itens Cadastrados ------");
	for (p = l; p != NULL; p = p -> prox){
		puts("--------------------------------------------");
		printf("Restaurante %s \n", p -> info.nome);
		printf("Endereço: %s \n", p -> info.endereco);
		printf("Tipo de comida: %s \n", p -> info.comida);
		printf("Preço: %.2f \n", p -> info.preco);
	}
	system("pause");
	system("cls");
}

void *pesquisar(Lista *l){
	Lista *p;
	int resp;
	
	system("cls");
	do{
		puts("Pesquisar por: ");
		puts("1 - Restaurante");
		puts("2 - Tipo comida");
		puts("3 - Preço");
		puts("0 - Sair");
		scanf("%d", &resp);
		
		if (resp != 0){
			switch (resp){
			case 1:
				puts("------ Lista de Restaurantes -----");
				for(p = l; p != NULL; p = p -> prox){
					printf("%s \n", p -> info.nome);
				}
				system("pause");
				system("cls");
				break;
				
			case 2:
				puts("------ Lista de Tipps de Comida -----");
				for(p = l; p != NULL; p = p -> prox){
					printf("%s \n", p -> info.comida);
				}
				system("pause");
				system("cls");
				break;
				
			case 3:
				puts("------ Lista de Preço -----");
				for(p = l; p != NULL; p = p -> prox){
					printf("%.2f \n", p -> info.preco);
				}
				system("pause");
				system("cls");
				break;
								
			default:
				puts("Opção inválida");
				break;
			}	
		}		

	}while(resp != 0);
	system("cls");
}

