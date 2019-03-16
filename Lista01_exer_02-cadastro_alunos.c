# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

struct aluno{
	int matricula; 
	char nome[50]; 
	int serie; 
	char turma[2]; 
	char sexo[2];
	float media;
	int situacao, ano_nasc;	
	char naturalidade[30];
};
typedef struct aluno Aluno;

struct lista{
	Aluno info;
	struct lista *prox;
};
typedef struct lista Lista;

// Prototipo das Funções
Lista *inserir(Lista *l, Aluno a);
Aluno cadastrar();
void *exibir(Lista *l);
void *aprovados(Lista *l);
void *genero(Lista *l);
void *calc_idade(Lista *l);

main(){
	setlocale(LC_ALL,"Portuguese");
	
	Aluno a;
	Lista *l, *p;
	l = NULL;
	int op;
	
	do{
		puts("----------- Menu ----------");
		puts("1 - Cadastrar aluno");
		puts("2 - Exibir lista de alunos");
		puts("3 - Porcentagem de alunos aprovados");
		puts("4 - Porcentagem de alunos por genero");
		puts("5 - Media de idade");
		puts("0 - Sair");
		scanf("%d",&op);
		
		switch(op){
			case 1:
				a = cadastrar();
				l = inserir(l, a);
				break;
			
			case 2:			
				system("cls");
				exibir(l);
				system("pause");
				system("cls");
				break;
				
			case 3:
				system("cls");
				aprovados(l);
				system("pause");
				system("cls");
				break;
				
			case 4:
				system("cls");
				genero(l);
				system("pause");
				system("cls");
				break;				
			
			case 5:
				system("cls");
				calc_idade(l);
				system("pause");
				system("cls");
				break;
				
			case 0:
				exit(1);
				break;
				
			default:
				puts("Opção Inválida.");
			break;
		}
	} while(1);
}

// Implementaçõa das funções

Lista *inserir(Lista *l, Aluno a){
	Lista *novo;
	novo = (Lista *)malloc(sizeof(Lista));
	novo -> info = a;
	novo -> prox = l;
	return novo;
}

Aluno cadastrar(){
	Aluno a;
	printf("Matricula Nº: ");
	scanf("%d", &a.matricula);	
	printf("Nome: ");
	fflush(stdin);
	gets(a.nome);
	printf("Série 1 2 ou 3: ");
	scanf("%d", &a.serie);
	printf("Turma A B ou C: ");
	fflush(stdin);
	gets(a.turma);
	printf("Sexo: ");
	fflush(stdin);
	gets(a.sexo);	
	printf("Media: ");
	scanf("%f", &a.media);
	if (a.media >= 6){
		a.situacao = 1;
	}else{
		a.situacao = 0;
	}
	printf("Ano Nascimento: ");
	scanf("%d", &a.ano_nasc);
	printf("Naturalidade: ");
	fflush(stdin);
	gets(a.naturalidade);
	return a;
}

void *exibir(Lista *l){
	Lista *p;
	puts("----- Lista de Alunos Cadastrados ----");
	for (p = l; p != NULL; p = p -> prox){
		puts("-----------------------------");
		printf("Matricula: %d \n", p -> info.matricula);
		printf("Nome: %s \n", p -> info.nome);
		printf("Serie: %d Turma: %s \n", p -> info.serie, p -> info.turma);
		printf("Sexo: %s \n", p -> info.sexo);
		printf("Média: %.2f \n", p -> info.media);
		printf("Situação: %s \n",  p -> info.situacao == 1 ? "APROVADO(A)" : "REPROVADO(A)");
		printf("Ano Nascimento: %d \n", p -> info.ano_nasc);
		printf("Naturalidade: %s \n", p -> info.naturalidade);
		puts("");		
	}
}

void *aprovados(Lista *l){
	Lista *p;
	int aprov[3][3], reprov[3][3];
	int alunos[3][3];
	int i, j, tot_alunos, tot_aprov, tot_reprov;
	float porcent_aprov, porcent_reprov;
	
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			alunos[i][j] = 0;
			aprov[i][j] = 0;
			reprov[i][j] = 0;
		}
	}	
	
	for (i = 0; i < 3; i++){
		for (p = l; p != NULL; p = p -> prox){
			if (p -> info.serie == i + 1){
				if (toupper(p -> info.turma[0]) == 'A' ){
					if (p -> info.situacao == 1){
						aprov[i][0] += 1;
					} else {
						reprov[i][0] += 1;
					}					
				} else if (toupper(p -> info.turma[0]) == 'B' ){
					if (p -> info.situacao == 1){
						aprov[i][1] += 1;
					} else {
						reprov[i][1] += 1;
					}						
				} else if (toupper(p -> info.turma[0]) == 'C' ){
					if (p -> info.situacao == 1){
						aprov[i][2] += 1;
					} else {
						reprov[i][2] += 1;
					}						
				}
			}
		}
	}
	
	puts(" ------- Porcentagem de Aprovados e Reprovados ----------");
	for (i = 0; i < 3; i++){
		
		puts("--------------------------------------");		
		printf("Alunos da Serie %d \n", i + 1);
		for (j = 0; j < 3; j++){			
			tot_alunos = aprov[i][j] + reprov[i][j];
			porcent_aprov = (float) 100 * aprov[i][j] / tot_alunos;
			porcent_reprov = (float) 100 * reprov[i][j] / tot_alunos;		
			
			 if (j == 0){
			 	puts("Turma A");
			 } else if (j == 1){
			 	puts("Turma B");
			 } else {
			 	puts("Turma C");
			 }
			printf("Aprovados: %.2f%% \n", porcent_aprov > 0 ? porcent_aprov : 0);
			printf("Rerovados: %.2f%% \n", porcent_reprov > 0 ? porcent_reprov : 0);			
		}
		
		tot_aprov = 0, tot_reprov = 0;
		for (j = 0; j < 3; j++){
			tot_aprov += aprov[i][j];
			tot_reprov += reprov[i][j];			
		}
		tot_alunos = tot_aprov + tot_reprov;
		porcent_aprov = (float) 100 * tot_aprov / tot_alunos;
		porcent_reprov = (float) 100 * tot_reprov / tot_alunos;	
		puts("");
		printf("Total na Serie: %d \n", i + 1);
		printf("Aprovados: %.2f%% \n", porcent_aprov > 0 ? porcent_aprov : 0);
		printf("Rerovados: %.2f%% \n", porcent_reprov > 0 ? porcent_reprov : 0);				
	}	
}

void *genero(Lista *l){
	Lista *p;
	int masc[3][3], fem[3][3];
	int alunos[3][3];
	int i, j, tot_alunos, tot_masc, tot_fem;
	float porcent_masc, porcent_fem;
	
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			alunos[i][j] = 0;
			masc[i][j] = 0;
			fem[i][j] = 0;
		}
	}	
	
	for (i = 0; i < 3; i++){
		for (p = l; p != NULL; p = p -> prox){
			if (p -> info.serie == i + 1){
				if (toupper(p -> info.turma[0]) == 'A' ){
					if (toupper(p -> info.sexo[0])== 'M'){
						masc[i][0] += 1;
					} else {
						fem[i][0] += 1;
					}					
				} else if (toupper(p -> info.turma[0]) == 'B' ){
					if (toupper(p -> info.sexo[0])== 'M'){
						masc[i][1] += 1;
					} else {
						fem[i][1] += 1;
					}						
				} else if (toupper(p -> info.turma[0]) == 'C' ){
					if (toupper(p -> info.sexo[0])== 'M'){
						masc[i][2] += 1;
					} else {
						fem[i][2] += 1;
					}						
				}
			}
		}
	}
	
	puts(" ------- Porcentagem de Alunos Por Genero ----------");
	for (i = 0; i < 3; i++){
		puts("--------------------------------------");		
		printf("Alunos da Serie %d \n", i + 1);
		for (j = 0; j < 3; j++){			
			tot_alunos = masc[i][j] + fem[i][j];
			porcent_masc = (float) 100 * masc[i][j] / tot_alunos;
			porcent_fem = (float) 100 * fem[i][j] / tot_alunos;		
			
			 if (j == 0){
			 	puts("Turma A");
			 } else if (j == 1){
			 	puts("Turma B");
			 } else {
			 	puts("Turma C");
			 }
			printf("Homens: %.2f%% \n", porcent_masc > 0 ? porcent_masc : 0);
			printf("Mulheres: %.2f%% \n", porcent_fem > 0 ? porcent_fem : 0);
		}
		
		tot_masc = 0, tot_fem = 0;
		for (j = 0; j < 3; j++){
			tot_masc += masc[i][j];
			tot_fem += fem[i][j];			
		}
		tot_alunos = tot_masc + tot_fem;
		porcent_masc = (float) 100 * tot_masc / tot_alunos;
		porcent_fem = (float) 100 * tot_fem / tot_alunos;
		puts("");	
		printf("Total na Serie: %d \n", i + 1);
		printf("Homens: %.2f%% \n", porcent_masc > 0 ? porcent_masc : 0);
		printf("Mulheres: %.2f%% \n", porcent_fem > 0 ? porcent_fem : 0);			
	}	
}

void *calc_idade(Lista *l){
	Lista *p;
	float m1, m2, m3;
	int s1, s2, s3, cont1 = 0, cont2 = 0, cont3 = 0, ano_atual = 2019;
	
	
	for (p = l; p != NULL; p = p -> prox){
		if( p -> info.serie == 1){
			s1 = s1 + (ano_atual - p -> info.ano_nasc);
			cont1++;
		} else if (p -> info.serie == 2){
			s2 = s2 + (ano_atual - p -> info.ano_nasc);
			cont2++;
		}else{
			s3 = s3 + (ano_atual - p -> info.ano_nasc);
			cont3++;
		}
	}
	
	m1 = (float) s1 / cont1;
	m2 = (float) s2 / cont2;
	m3 = (float) s3 / cont3;
	puts("Media de idade");
	printf("Serie 1: %.0f anos\n", m1 >= 0 ? m1 : 0);
	printf("Serie 2: %.0f anos\n", m2 >= 0 ? m2 : 0);
	printf("Serie 3: %.0f anos\n", m3 >= 0 ? m3 : 0);
}
