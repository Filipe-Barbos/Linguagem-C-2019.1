# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

struct veiculo{
	char proprietario[100], modelo[30];
	char cor[20], placa[7];
	int combustivel, chassi, ano;
};
typedef struct veiculo Veiculo;

struct lista{
	Veiculo info;
	struct lista *prox;
};
typedef struct lista Lista;

Lista *inserir(Lista *l, Veiculo v);
Veiculo cadastrar();
void *verificar_ano(Lista *l);
void *exibir(Lista *l);
void *placas(Lista *l);
void *modelo(Lista *l);
void *mudar_prop(Lista *l);

main(){
	setlocale(LC_ALL,"Portuguese");
	Veiculo v;
	Lista *l, *p;
	l = NULL;
	int resp;
	
	do{
		puts("---------- Menu ----------");
		puts("1 - Cadastrar");
		puts("2 - Carros 2010 a diesel");
		puts("3 - Placas incio J final 0 2 4 ou 7");
		puts("4 - Modelo e cor");
		puts("5 - Troca proprietário");
		puts("6 - Exibir cadastros");
		puts("0 - Sair");
		scanf("%d", &resp);
		
		switch(resp){
			case 1:
				system("cls");
				v = cadastrar();
				l = inserir(l, v);
				system("cls");
				break;
				
			case 2:
				system("cls");
				verificar_ano(l);
				system("pause");
				system("cls");
				break;
				
			case 3:
				system("cls");
				placas(l);
				system("pause");
				system("cls");
				break;
				
			case 4:
				system("cls");
				modelo(l);
				system("pause");
				system("cls");
				break;
				
			case 5:
				system("cls");
				mudar_prop(l);
				system("pause");
				system("cls");
				break;
				
			case 6:
				system("cls");
				exibir(l);
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

Lista *inserir(Lista *l, Veiculo v){
	Lista *novo;
	novo = (Lista *)malloc(sizeof(Lista));
	novo -> info = v;
	novo -> prox = l;
	return novo;
}

Veiculo cadastrar(){
	Veiculo v;	
	printf("Proprietario(a): ");
	fflush(stdin);
	gets(v.proprietario);
	printf("Chassi nº: ");
	scanf("%d", &v.chassi);
	printf("Cor: ");
	fflush(stdin);
	gets(v.cor);
	printf("Ano: ");
	scanf("%d", &v.ano);
	printf("Modelo: ");
	fflush(stdin);
	gets(v.modelo);
	puts("Tipo de Combustível: ");
	puts("1 - Álcool");
	puts("2 - Gasolina");
	puts("3 - Diesel");
	scanf("%d", &v.combustivel);
	puts("A placa deve ter 3 letras e 4 numeros");
	puts("Ex: abc1234");
	printf("Placa: ");
	fflush(stdin);
	gets(v.placa);
	return v;
}

void *exibir(Lista *l){
	Lista *p;
	puts("-------- Veiculos cadastrados --------");
	for(p = l; p != NULL; p = p -> prox){
		puts("------------------------------------------");
		printf("Proprietario(a): %s \n", p -> info.proprietario);
		printf("Chassi nº: %d \n", p -> info.chassi);
		printf("Cor: %s \n", p -> info.cor);
		printf("Ano: %d \n", p -> info.ano);
		printf("Modelo: %s \n", p -> info.modelo);
		if (p -> info.combustivel == 1){
			puts("Combustível: Álcool");
		} else if(p -> info.combustivel == 2){
			puts("Combustível: Gasolina");
		} else if(p -> info.combustivel == 3){
			puts("Combustível: Diesel");
		}		
		printf("Placa: %s \n", p -> info.placa);	
	}	
}

void *verificar_ano(Lista *l){
	Lista *p;
	puts("Carros de 2010 ou posterior e movidos a diesel");
	puts("-------------------------------------------------");
	for (p = l; p != NULL; p = p -> prox){
		if ((p -> info.ano >= 2010) && (p -> info.combustivel == 3)){
			printf("Proprietário(a): %s \n", p -> info.proprietario);
			printf("Carro ano: %d \n", p -> info.ano);
			if (p -> info.combustivel == 1){
				puts("Combustível: Álcool");
			} else if(p -> info.combustivel == 2){
				puts("Combustível: Gasolina");
			} else if(p -> info.combustivel == 3){
				puts("Combustível: Diesel");
			}
			puts("-----------------------------------------");
		}
		
	}
}

void *placas(Lista *l){
	Lista *p;
	puts("-------- Placas de inicio J e final 0, 2, 4, ou 7 --------");	
	for(p = l; p != NULL; p = p -> prox){		
		if((p -> info.placa[0] == 106) || (p -> info.placa[0] == 74)){
			switch(p -> info.placa[6]){
				case 48:
				case 50:
				case 52:
				case 55:
					puts("------------------------------------------------------");
					printf("Proprietário(a): %s \n", p -> info.proprietario);
					printf("Placa: %s \n", p -> info.placa);					
					break;
			}
		}
	}
}

void *modelo(Lista *l){
	Lista *p;
	int soma;
	puts("---------- Modelo e Cor -----------");
	puts("placas com seugnda letra como vogal");
	puts("  e soma dos números igual a par   ");
	for(p = l; p != NULL; p = p -> prox){
		switch(toupper(p -> info.placa[1])){
			case 65:
			case 69:
			case 73:
			case 79:
			case 85:
				soma = p -> info.placa[3] + p -> info.placa[4] + p -> info.placa[5] + p -> info.placa[6];
				if(soma % 2 == 0){
					puts("-------------------------------");
					printf("Modelo: %s \n", p -> info.modelo);
					printf("Cor: %s \n", p -> info.cor);
					printf("Placa: %s \n", p -> info.placa);
				}
				break;
		}
	}
}

void *mudar_prop(Lista *l){
	Lista *p;
	int cont, i, chassi, flag;
	char placa[6];
	puts("--- Mudança de Proprietário(a) ----");
	puts("-----------------------------------");
	printf("Placa do veicúlo: ");
	fflush(stdin);
	gets(placa);
	cont = 0;
	for(i = 0; i < 4; i++){
		if(placa[i + 3] != 48){
			cont++;
		}
	}
	
	if(cont == 4){
		printf("Número do chassi: ");
		scanf("%d", &chassi);
		flag = 0;
		for(p = l; p != NULL; p = p -> prox){
			if(p -> info.chassi == chassi){
				flag = 1;
				printf("Nome do novo proprietario(a): ");
				fflush(stdin);
				gets(l -> info.proprietario);
				puts("Mudança concluida com sucesso.");
			}
		}
		
		if(flag == 0){
			puts("Não há nenhum vaículo cadastrado com esse chassi");
		}
	} else {
		puts("Não é possível a mudança de propriétario desse veiculo");
	}
}

