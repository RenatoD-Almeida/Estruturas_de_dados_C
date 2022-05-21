#include <stdio.h>
#include <stdlib.h>

/*
1 - criar uma var do tipo pilha e iniciar ela com o topo nulo (vazio)

2 - INCREMENTAR
2.1 - criar novo nó (pilha igual junção de nós empilhados)
2.2 - apontar o ptr do novo nó para o anterior
2.3 - apontar o topo da pilha (struct pilha) para o novo nó

3 - DECREMENTAR
3.1 - verificar se topo é diferente de nulo. (pilha->topo_da_pilha)
3.2 - Criar um ponteiro para nó e apontar ao ponteiro que mira no topo da lista
3.3 -
*/


// STRUCTS
struct Pessoa{
	char nome[50];
};

struct NO{
	struct Pessoa pessoa;
	struct NO *anterior;
};

struct Pilha{
	struct NO *topo_da_pilha;
};

// FUNCTIONS

struct Pessoa cadastrar_pessoa(){
	struct Pessoa p;
	printf("Digite o nome: ");
	fgets(p.nome, 50, stdin); fflush(stdin);
	return p;
}

void imprimir_pessoa(struct Pessoa p){
	printf("\tNome: %s", p.nome);
}

// STACK

void iniciar_pilha(struct Pilha *pilha){
	pilha->topo_da_pilha = NULL;
}

void push(struct Pilha *pilha){
	struct NO *novo_NO = NULL;
	novo_NO = (struct NO *)malloc(sizeof(struct NO));
	if(novo_NO){
		novo_NO->pessoa = cadastrar_pessoa();
		novo_NO->anterior = pilha->topo_da_pilha;
		pilha->topo_da_pilha = novo_NO;
	}else{
		printf("\nNao foi possivel criar um novo NO.\n");
	}
}

struct NO * pop(struct Pilha *pilha){	
	if(pilha->topo_da_pilha){
		struct NO *remover = pilha->topo_da_pilha;
		pilha->topo_da_pilha = pilha->topo_da_pilha->anterior;
		return remover;
	}else{
		printf("\nPilha ja esta vazia\n");
		return NULL;
	}
}

void imprimir_pilha(struct Pilha *pilha){
	  struct NO *aux = pilha->topo_da_pilha;
	  printf("\t====== Pilha ======\n");
	  while(aux){
	  	imprimir_pessoa(aux->pessoa);
	  	aux = aux->anterior;
	  }
	  printf("\t==== FIM PILHA ====");
}

int menu(){
	int opcao;
	printf("\n=======================\n");
	printf("         MENU            ");
	printf("\n=======================\n");
	printf("\n1 - Incrementar");
	printf("\n2 - Decrementar");
	printf("\n3 - Imprimir\n");
	printf("\n4 - Sair");
	printf("\n=======================\n");
	printf("\n-> ");
	scanf("%d", &opcao); fflush(stdin);
	return opcao;
}

	
int main(){
	
	struct Pilha pilha_generica;
	struct NO *removido = NULL;
	iniciar_pilha(&pilha_generica);
	
	
	int opcao = 0;
	while (opcao != 4){
		opcao = menu();
		switch(opcao){
			case 1:
				push(&pilha_generica);
				break;
			case 2:
				removido = pop(&pilha_generica);
				if(removido){
					printf("Item removido com sucesso");
					imprimir_pessoa(removido->pessoa);
				}else{
					printf("Nao foi possivel remover o item");
				}
				break;
			case 3:
				imprimir_pilha(&pilha_generica);
				break;
			case 4:
				break;
		}
	}
	
	return 0;
}
