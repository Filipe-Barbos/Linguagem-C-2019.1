# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

struct dieta{
	char comida[100];
	float peso, calorias;
};
typedef struct dieta Dieta;

struct lista{
	Dieta info;
	struct lista *prox;
};
typedef struct lista Lista;

Lista *inserir(Lista *l, Dieta d);
Dieta cadastrar();
void *exibir(Lista *l);
void *pesquisar(Lista *l);

main(){
	setlocale(LC_ALL,"Portuguese");
	Dieta d;
	Lista *l, *p;
	l = NULL;
	int resp;
	
	do{
		puts("-------- Menu --------");
		puts("1 - Cadastrar");
		puts("2 - Exibir lista");
		puts("3 - Pesquisar por iten");
		puts("0 - Sair");
		scanf("%d", &resp);
		
		switch(resp){
			case 1:
				d = cadastrar();
				l = inserir(l, d);
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
	} while(1);
	
}

Lista *inserir(Lista *l, Dieta d){
	Lista *novo;
	novo = (Lista *)malloc(sizeof(Lista));
	novo -> info = d;
	novo -> prox = l;
	return novo;
}

Dieta cadastrar(){
	Dieta d;
	printf("Nome da comidao: ");
	fflush(stdin);
	gets(d.comida);
	printf("Peso: ");
	scanf("%f", &d.peso);
	printf("Calorias: ");
	scanf("%f", &d.calorias);
	return d;		
}

void *exibir(Lista *l){
	Lista *p;
	system("cls");
	puts("------ Exibindo Itens da Lista -------");
	for (p = l; p != NULL; p = p -> prox){
		printf("Nome: %s \n", p -> info.comida);
		printf("Peso Kg: %.2f \n", p -> info.peso);
		printf("Calorias: %.0f \n", p -> info.calorias);
		puts("---------------------------------------");
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
		puts("1 - Nome");
		puts("2 - Peso");
		puts("3 - Calorias");
		puts("0 - Sair");
		scanf("%d", &resp);
		
		if (resp != 0){
			system("cls");
			switch(resp){
				case 1:
					puts("----- Lista das comidas cadastradas -------");
					for(p = l; p != NULL; p = p -> prox){
						printf("%s \n", p -> info.comida);
					}
					break;
				
				case 2:
					puts("----- Lista dos pesos -------");
					for(p = l; p != NULL; p = p -> prox){
						printf("Kg: %.2f \n", p -> info.peso);
					}
					break;
					
				case 3:
					puts("----- Lista dae calorias -------");
					for(p = l; p != NULL; p = p -> prox){
						printf("%.0f Cal\n", p -> info.calorias);
					}
					break;
					
				default:
					puts("Opção inválida");
					break;
			}
		}
		system("pause");
		system("cls");
	}while(resp != 0);
}

