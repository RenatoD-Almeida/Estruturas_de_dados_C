#include <stdio.h>
#include <stdlib.h>
	
/* Simulação da utilização de uma pilha dinâmica em um sistema de cadastro de Pessoas (Nome, idade, peso e altura).*/

struct Pessoa{
	char nome[50];
	int idade;
	float peso, altura;
};

struct NO{
	struct Pessoa pessoa;
	struct NO *anterior;
};

typedef struct Pilha_Dinamica{
	struct NO * topo_da_pilha;
}PD;

// Função Pessoas:
struct Pessoa cadastro_pessoa();
void imprimir_pessoa(struct Pessoa p);

// Funções Pilha:
void iniciar_pilha(PD *pilha);
void push(PD *pilha);
void pop(PD *pilha);
void printS(PD pilha);

int menu(){
	int opcao = 0;
	printf("\n====================");
	printf("\n       MENU         ");
	printf("\n====================");
	printf("\n   1 - Push.        ");
	printf("\n   2 - Pop.         ");
	printf("\n   3 - PrintS.    \n");
	printf("\n   4 - Sair.        ");
	printf("\n====================");
	printf("\n-> "); scanf("%d%*c", &opcao);
	return opcao;
}

int main(){
	
	
	PD pilha_dinamica;
	iniciar_pilha(&pilha_dinamica);
	int op = 0;
	
	
	while(op != 4){
		op = menu();
		switch(op){
			case 1:
				push(&pilha_dinamica);
				break;
			case 2:
				pop(&pilha_dinamica);
				break;
			case 3:
				printS(pilha_dinamica);
				break;
			case 4:
			printf("\n~~~~~~ Ate logo ~~~~~~\n");
				break;
		}
	}
	
	

	
	return 0;
}

/* Função para cadastrar Pessoa */
struct Pessoa cadastro_pessoa(){
	struct Pessoa p;
	printf("\n\nNome: ");
	scanf("%50[^\n]%*c", &p.nome);
	printf("\nIdade: ");
	scanf("%d%*c", &p.idade);
	printf("\nPeso: ");
	scanf("%f%*c", &p.peso);
	printf("\nAltura: ");
	scanf("%f%*c", &p.altura);
	return p;
}

/* Função para imprimir Pessoa */
void imprimir_pessoa(struct Pessoa p){
	printf("\nNome: %s\tIdade: %d\nPeso: %.2f\tAltura: %.2f\n", p.nome, p.idade, p.peso, p.altura);
}

/* ~~~~~~~~ Conjunto de Funções para pilha dinâmica ~~~~~~~~ */

void iniciar_pilha(PD *pilha){
	pilha->topo_da_pilha = 0;
}

void push(PD *pilha){
	struct NO* novo;
	novo = (struct NO *)malloc(sizeof(struct NO));
	if(novo){
		novo->pessoa = cadastro_pessoa();
		novo->anterior = pilha->topo_da_pilha;
		pilha->topo_da_pilha = novo;
	}else{
		printf("Nao foi possivel alocar memoria para o novo NO\n");
	}
}

void pop(PD *pilha){
	struct NO *deletar;
	deletar = pilha->topo_da_pilha;
	if(!(deletar)){
		printf("Pilha ja vazia!");
		getchar();
	}else{
		pilha->topo_da_pilha = pilha->topo_da_pilha->anterior;
		free(deletar);
	}
}

void printS(PD pilha){
	struct NO *auxiliar;
	auxiliar = pilha.topo_da_pilha;
	if(auxiliar){
		while(auxiliar){
			imprimir_pessoa(auxiliar->pessoa);
			auxiliar = auxiliar->anterior;
		}
	}else{
		printf("\nNao ha o que imprimir: Pilha Vazia!");
		getchar();
	}
}




