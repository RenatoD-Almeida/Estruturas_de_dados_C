#include <stdio.h>
#include <stdlib.h>

struct Pessoa{
	char nome[50];
};

struct NO{
	struct Pessoa pessoa;
	struct NO *proximo;
};

typedef struct Fila_Dinamica{
	struct NO *inicio_da_fila;
}FD;

//função menu
void menu_faz(int op, FD *fila);
int menu(FD *fila);
void continuar();

// funções para struct Pessoa
struct Pessoa cadastrar_pessoa();
void imprimir_pessoa(struct Pessoa p);

// funções para Fila_Dinamica
void iniciar_fila(FD *fila);
void push(FD *fila);
void pop(FD *fila);
void printR(FD *fila);

	
int main(){
	
	FD fila;
	iniciar_fila(&fila);
	
	int op = 0;
	
	while(op != 4){
		op = menu(&fila);
	}
	
	
	return 0;
}

void iniciar_fila(FD *fila){
	fila->inicio_da_fila = NULL;
}

void push(FD *fila){
	struct NO *novo_NO = NULL;
	novo_NO = (struct NO*)malloc(sizeof(struct NO));
	novo_NO->pessoa = cadastrar_pessoa();
	novo_NO->proximo = NULL;
	if(!fila->inicio_da_fila){
		fila->inicio_da_fila = novo_NO;
	}else{
		struct NO *aux;
		aux = fila->inicio_da_fila;
		while(aux->proximo){
			aux = aux->proximo;
		}
		aux->proximo = novo_NO;
	}
}

void pop(FD *fila){
	if(!fila->inicio_da_fila){
		printf("\nFila atualmente vazia!\n");
		continuar();
	}else{
		struct NO *deletar;
		deletar = fila->inicio_da_fila;
		fila->inicio_da_fila = fila->inicio_da_fila->proximo;
		printf("\n%s saiu da fila\n", deletar->pessoa.nome);
		continuar();
		free(deletar);
	}
}

void printR(FD *fila){
	struct NO *auxiliar;
	auxiliar = fila->inicio_da_fila;
	if(!auxiliar){
		printf("\nFila atualmente vazia!\n");
		continuar();
	}else{
		printf("Fila: [ ");
		while(auxiliar){
			imprimir_pessoa(auxiliar->pessoa);
			auxiliar = auxiliar->proximo;
		}
		printf("]");
		continuar();
	}
}

struct Pessoa cadastrar_pessoa(){
	system("cls");
	struct Pessoa p;
	printf("============================\n");
	printf("Digite o nome da nova pessoa\n");
	printf("============================\n");
	printf("-> ");
	scanf("%50[^\n]%*c", &p.nome);
	return p;
}

void imprimir_pessoa(struct Pessoa p){
	printf("%s, ", p.nome);
}

int menu(FD *fila){
	int opcao = 0;
	system("cls");
	printf("+==========================+\n");	
	printf("|            MENU          |\n");
	printf("+==========================+\n");
	printf("|     1 - Push()           |\n");
	printf("|     2 - Pop()            |\n");
	printf("|     3 - Print Row()      |\n");
	printf("|                          |\n");
	printf("|     4 - Exit()           |\n");
	printf("+==========================+\n");
	printf("   -> ");
	scanf("%d%*c", &opcao);
	menu_faz(opcao, fila);
	return opcao;
}

void menu_faz(int op, FD *fila){
	switch(op){
		case 1:
			push(fila);
			break;
		case 2:
			pop(fila);
			break;
		case 3:
			printR(fila);
			break;
		case 4:
			printf("\n~~~~~~ Ate logo ~~~~~~\n");
			break;
		default:
			printf("\nOpcao invalida!");
	}
}

void continuar(){
	printf("\nPressione ENTER para continuar...\n");
	getchar(); fflush(stdin);
}






