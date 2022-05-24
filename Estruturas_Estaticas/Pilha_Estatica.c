#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	
/* Estruturas estáticas não utilizam alocação de memória, Então o tamanho da pilha é pre-definido

Pilha na estrutura de dados são um conjunto funções que seguem determinadas regras: 

- Empilhar (push) - para acrescentar um item a pilha
- Desempilhar (pop) - para decrescentar um item a pilha
- Mostrar pilha (printS) - para imprimir os itens da pilha*/	

#define tamanho 10

struct Pessoa{
	char nome[50];
};
	
typedef struct Pilha_Estatica{
	struct Pessoa nome[tamanho];
	int topo_da_pilha;				// Variável que guarda aonde será cadastrado o nome na pilha
}PE;

void iniciar_pilha(PE *pilha){		// Inicia o topo da pilha = 0, sinalizando que a pilha agora está vazia.
	pilha->topo_da_pilha = 0;
	printf("\nPilha Criada com sucesso\n");
}

// Função de cadastro

struct Pessoa cadastrar_pessoa(){
	struct Pessoa p;
	printf("Digite o nome: ");
	scanf("%50[^\n]%*c", &p.nome);
	return p;
}

// Funções da pilha:

void push(PE *pilha){
	if(pilha->topo_da_pilha > tamanho){
		printf("Pilha Cheia.\n");
		getchar();
	}else{
		pilha->nome[pilha->topo_da_pilha] = cadastrar_pessoa();
		++pilha->topo_da_pilha; 
	}
}

void pop(PE *pilha){
	if(pilha->topo_da_pilha == 0){
		printf("Pilha ja esta vazia.\n");
		getchar();
	}else{
		--pilha->topo_da_pilha;
		strcpy(pilha->nome[pilha->topo_da_pilha].nome, "\0");
	}
}

void printS(PE pilha){
	int i = 0;
	printf("Nomes cadastrados:\n\n");
	while(i < pilha.topo_da_pilha){
		printf("\t%s\n", pilha.nome[(pilha.topo_da_pilha - 1) - i].nome);
		++i;
	}
	getchar();
}
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

int main(){
		
	PE pilha;
	int opcao = 0;
	
	iniciar_pilha(&pilha);
	
	while(opcao != 4){
		opcao = menu();
		switch(opcao){
			case 1:
				push(&pilha);
				break;
			case 2:
				pop(&pilha);
				break;
			case 3:
				printS(pilha);
				break;
			case 4:
				break;								
		}
	}
	
	
	
	return 0;
}
