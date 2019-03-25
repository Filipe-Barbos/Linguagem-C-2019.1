# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

struct pessoa{
	char nome[100];
	int telefone;
	char email[100];
};
typedef struct pessoa Pessoa;

struct lista{
	Pessoa info;
	struct lista *prox;
};
typedef struct lista Lista;

Lista *inserir(Lista *l, Pessoa p);
Pessoa cadastrar();
void exibir(Lista *l);

main(){
	setlocale(LC_ALL,"Portuguese");
	Pessoa p;
	Lista *l;
	l = NULL;
	int op;
	char resp;
	do{
		puts("1 - Novo Cadastro");		
		puts("2 - Exibir Cadastros");
		puts("0 - Sair");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				system("cls");
				p = cadastrar();
				printf("Desejar gravar o cadastro (S / N): ");
				fflush(stdin);
				resp = getchar();
				if (toupper(resp) == 'S'){
					l = inserir(l, p);
				}
				system("pause");
				system("cls");
				break;
				
			case 2:
				system("cls");
				exibir(l);
				system("pause");
				system("cls");
				break;
			
			case 0:
				exit(1);
				break;
				
			default:
				system("cls");
				puts("Opção inválida");
				break;
		}
	}while(1);	
}

Lista *inserir(Lista *l, Pessoa p){
	Lista *novo;
	novo = (Lista *)malloc(sizeof(Lista));
	novo -> info = p;
	if(l == NULL){
		novo -> prox = novo;
	}else{
		novo -> prox = l -> prox;
		l -> prox = novo;
	}
	puts("Cadastro gravado com sucesso.");
	return novo;
}

Pessoa cadastrar(){
	Pessoa p;
	char resp;
	printf("Nome: ");
	fflush(stdin);
	gets(p.nome);
	printf("Telefone: ");
	scanf("%d", &p.telefone);
	printf("Email: ");
	fflush(stdin);
	gets(p.email);	
	return p;
}

void exibir(Lista *l){
	Lista *p;
	p = l -> prox;
	puts("------ Pessoas Cadastradas -------");
	do{
		printf("Nome: %s \n", p -> info.nome);
		printf("Telefone: %d \n", p -> info.telefone);
		printf("Email: %s \n", p -> info.email);
		puts("----------------------------------");
		p = p -> prox;
	}while(p != l -> prox);
}

