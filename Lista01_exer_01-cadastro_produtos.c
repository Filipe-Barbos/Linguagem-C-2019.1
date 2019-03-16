# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

// Cirando estrutra com as caracteristicas do protudo
struct produto{
	char cod[6], nome[20];
	float preco;
	int baixa_tot, mat[2][2];	
};
typedef struct produto Prod;

// criando estrutura da lista encadeada
struct lista{
	Prod info;
	struct lista *prox;
};
typedef struct lista Lista;

// Prototipo da função inserir
Lista *inserir(Lista *l, Prod p);

// Prototipo da função cadastrar
Prod cadastrar();

// Prototipo da função exibir
Prod exibir(Prod p);

main(){
	setlocale(LC_ALL,"");
	Prod prod;
	Lista *l, *p, *maior;
	l = NULL;
	maior = NULL;
	int op;
	
	do{
		puts("1 - Cadastrar Produto.");
		puts("2 - Produto com maior baixa.");
		puts("3 - Sair.");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				prod = cadastrar();
				l = inserir(l, prod);
				system("cls");
				break;
			case 2:
 
				for (p = l; p != NULL; p = p -> prox){
					if ( maior == NULL){
                       maior = p;
                    }else{
                          if (p -> info.baixa_tot > maior -> info.baixa_tot){
                             maior = p;                
                          }
                    }
				}
				system("cls");
				puts("Produto com maior baixa");
				printf("Nome: %s \n", maior -> info.nome);
				printf("Total de baixas %d \n", maior -> info.baixa_tot);
				break;
				system("pause");
				system("cls");
				
			case 3:
				exit(1);
				break;
		}
	} while (1);
}

// Função inserir
Lista *inserir(Lista *l, Prod p){
	Lista *novo;	
	novo = (Lista *)malloc(sizeof(Lista));
	novo -> info = p;
	novo -> prox = l;
	return novo;
}


// Função cadastrar
Prod cadastrar(){	
	Prod p;
	int i, j;
	printf("Código do produto: ");
	fflush(stdin);
	gets(p.cod);
	printf("Nome do produto: ");
	fflush(stdin);
	gets(p.nome);
	printf("Preço do produto: ");
	scanf("%f", &p.preco);
	
	p.baixa_tot = 0;
	for (i = 0; i < 2; i++){		
		for (j = 0; j < 2; j++){
			printf("Baixa do protudo Semana %d dia %d: ", i + 1, j + 1);
			scanf("%d", &p.mat[i][j]);
			p.baixa_tot = p.baixa_tot + p.mat[i][j];
		}
	}
	
	return p;	
}

// Função exibir
Prod exibir(Prod p){
	int i, j;
	puts("Exibindo informações do produto");
	printf("Código: %s \n", p.cod);
	printf("Nome: %s \n", p.nome);
	printf("Preço: %.2f \n", p.preco);
	puts("Tabela de baixas");
	for (i = 0; i < 2; i++){
		for (j = 0; j < 2; j++){
			printf("Semana %d Dia %d: %d \n", i+1, j+1, p.mat[i][j]);
		}
	}
	printf("Total de baixas: %d \n", p.baixa_tot);
}
