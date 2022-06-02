#include <stdio.h>
#include <stdlib.h>

#define exit '4'

struct Pessoa{
	char nome[30];
};

struct NO{
	struct Pessoa pessoa;
	struct NO *proximo;
};

typedef struct Fila_Dinamica{
	struct NO *primeiro;
	struct NO *ultimo;
	int tamanho;
}FD;

void imprimir_pessoa(struct Pessoa p){
	printf("%s, ", p.nome);
}

struct Pessoa cadastrar_pessoa(){
	struct Pessoa p;
	printf("Nome: ");
	scanf("%30[^\n]", &p.nome); fflush(stdin);
	return p;
}

void push(FD *F){
	struct NO *novo = (struct NO *)malloc(sizeof(struct NO));
	if(novo){
		novo->pessoa = cadastrar_pessoa();
		novo->proximo = NULL;
		if(F->primeiro == NULL){
			F->primeiro = F->ultimo = novo;
		}else{
			F->ultimo->proximo = novo;
			F->ultimo = novo;
		}
		F->tamanho++;
	}else{
		printf("Erro ao alocar memoria.\n");
	}
}

struct NO * pop(FD *F){
	struct NO *deletar = F->primeiro;
	if(deletar == NULL){
		printf("Fila vazia.\n");
		getchar();
	}else{
		F->primeiro = F->primeiro->proximo;
		F->tamanho--;
	}
	return deletar;
}

void printR(FD *F){
	struct NO* aux;
	aux = F->primeiro;
	printf("Ha %d na fila:\n[ ", F->tamanho);
	while(aux){
		imprimir_pessoa(aux->pessoa);
		aux = aux->proximo;
	}
	printf("]");
}

void iniciar_fila(FD *F){
	F->primeiro = F->ultimo = NULL;
	F->tamanho = 0;
}
	
void desaloca_tudo(FD *F){
	struct NO *aux, *deletar;
	aux = deletar = F->primeiro;
	while(aux){
		aux = aux->proximo;
		free(deletar);
		deletar = aux;
	}
}

void continuar(){
	printf("\nPressione ENTER para continuar...\n");
	getchar(); fflush(stdin);
}

void menu_faz(char op, FD *fila){
	struct NO *deletar = NULL;
	switch(op){
		case '1':
			push(fila);
			break;
		case '2':
			deletar = pop(fila);
			printf("%s saiu da fila.\n", deletar->pessoa.nome);
			free(deletar);
			getchar();
			break;
		case '3':
			printR(fila);
			continuar();
			break;
		case '4':
			break;
		default:
			printf("\nOpcao invalida!");
			continuar();
	}
}

int menu(FD *fila){
	char opcao = '0';
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
	scanf("%c%*c", &opcao);
	menu_faz(opcao, fila);
	return opcao;
}
	
int main(){
	
	FD fila;
	iniciar_fila(&fila);
	
	char op;
	
	do{
		op = menu(&fila);
	}while(op != exit);
	
	
	desaloca_tudo(&fila);
	return 0;
}
