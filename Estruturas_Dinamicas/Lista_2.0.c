#include <stdio.h>
#include <stdlib.h>
	
/*
Faça uma lista que adicione no inicio e no final da lista, e que busque que busque o item para remover,
por incide e por nome.
*/	
	

struct Pessoa{
	char nome[30];
};
		
struct NO{
	struct Pessoa pessoa;
	struct NO *proximo;
};

struct Lista{
	struct NO *inicio;
	struct NO *ultimo;
};

void iniciar_lista(struct Lista *L){
	L->inicio = NULL;
	L->ultimo = NULL;
}

struct Pessoa cadastrar_pessoa();
void imprimir_pessoa(struct Pessoa p);

void backpush(struct Lista *L);
void frontpush(struct Lista *L);
void imprimir_lista(struct Lista *L);
void desalocar_tudo(struct Lista *L);

int main(){
	
	struct Lista lista;	
	iniciar_lista(&lista);
	
	frontpush(&lista);
	frontpush(&lista);
	frontpush(&lista);
	backpush(&lista);
	imprimir_lista(&lista);
	
	desalocar_tudo(&lista);
	return 0;
}

void backpush(struct Lista *L){
	struct NO *novo = (struct NO *)malloc(sizeof(struct NO));
	if(novo){
		novo->pessoa = cadastrar_pessoa();
		if(L->inicio == NULL){
			novo->proximo = NULL;
			L->inicio = L->ultimo = novo;
		}else{
			novo->proximo = L->inicio;
			L->inicio = novo;
		}
	}else{
		printf("\nErro ao alocar memoria para um novo NO.\n");
	}
}

void frontpush(struct Lista *L){
	struct NO *novo = (struct NO *)malloc(sizeof(struct NO));
	if(novo){
			novo->pessoa = cadastrar_pessoa();
			novo->proximo = NULL;
		if(L->inicio){
			L->ultimo->proximo = novo;
			L->ultimo = novo;
		}else{
			L->inicio = L->ultimo = novo;
		}
	}else{
		printf("\nErro ao alocar memoria para um novo NO.\n");
	}
}

void imprimir_lista(struct Lista *L){
	struct NO *aux;
	aux = L->inicio;
	printf("Inicio da lista: \n");
	while(aux){
		imprimir_pessoa(aux->pessoa);
		aux = aux->proximo;
	}
	printf("\n\tFim da lista.\n");
}

void desalocar_tudo(struct Lista *L){
	struct NO *aux, *deletar;
	aux = deletar = L->inicio;
	while(aux){
		aux = aux->proximo;
		free(deletar);
		deletar = aux;
	}
}

struct Pessoa cadastrar_pessoa(){
	struct Pessoa p;
	printf("Nome: ");
	scanf("%30[^\n]%*c", &p.nome);
	return p;
}

void imprimir_pessoa(struct Pessoa p){
	printf("%s, ", p.nome);
}
