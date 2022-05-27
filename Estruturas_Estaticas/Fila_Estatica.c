#include <stdio.h>

#define tamanho 10

struct Pessoa{
	char nome[50];
};	

typedef struct Fila_Estatica{
	struct Pessoa pessoa[tamanho];
	int fim_da_fila;	
}FE;

 // Funções para Struct Pessoa
 struct Pessoa cadastrar_pessoa();
 void imprimir_nome(struct Pessoa p);
 
 // Funções para Filha_Estática (FE)
 void iniciar_fila(FE *f);
 void push(FE *f);
 void pop(FE *f);
 void printR(FE f);
 
 // função menu
 int menu(){
	int opcao;
		printf("==============\n");
		printf("     MENU     \n");
		printf("==============\n");
		printf(" 1 - Push     \n");	
		printf(" 2 - Pop      \n");	
		printf(" 3 - PrintS   \n");	
		printf("\n 4 - Sair   \n");	
		printf("==============\n");
		printf("->");
		scanf("%d%*c", &opcao);
		return opcao;
 }
 
 int menu_utilidade(int opcao, FE *f){
 	switch(opcao){
 		case 1:
 			push(f);
 			return opcao;
 		case 2:
 			pop(f);
 			return opcao;
 		case 3:
 			printR(*f);
 			return opcao;
 		case 4:
 			printf("\n~~~~~~ Ate logo ~~~~~~\n");
 			return opcao;
	 }
 }
 
int main(){
	
	int op;
	
	FE fila;
	iniciar_fila(&fila);
	
	while(op != 4){
		op = menu_utilidade(menu(), &fila);
	}
	
	return 0;
}

void iniciar_fila(FE *f){
	f->fim_da_fila = 0;
}

void push(FE *f){
	if(f->fim_da_fila > tamanho){
		printf("\nFila cheia! ");
		getchar();
	}else{
		f->pessoa[f->fim_da_fila] = cadastrar_pessoa();
		++f->fim_da_fila;
	}
}

void pop(FE *f){
	int i = 0;
	
	if(f->fim_da_fila == 0){
		printf("\nFila Atualmente vazia!");
		getchar();
	}else{
		f->fim_da_fila--;
		for( i ; i < f->fim_da_fila; ++i){
			f->pessoa[i] = f->pessoa[i + 1];
		}
	}
}

void printR(FE f){
	int i = 0;
	printf("Fila atual: [ ");
	for( i ; i < f.fim_da_fila; ++i){
		imprimir_nome(f.pessoa[i]);
	}
	printf("].\n");
}

struct Pessoa cadastrar_pessoa(){
	struct Pessoa p;
	printf("\nNome da nova pessoa: ");
	scanf("%50[^\n]%*c", &p.nome);
	return p;
}

void imprimir_nome(struct Pessoa p){
	printf("%s, ", p.nome);
}
