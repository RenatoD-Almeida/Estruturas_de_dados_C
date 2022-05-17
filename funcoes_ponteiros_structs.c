#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pessoa{
	int idade;
	char nome[50];
};

	
int main(){
	struct Pessoa * preencher_pessoa();
	struct Pessoa *p1;
	
	p1 = preencher_pessoa();
	
	if(p1){
		printf("Memoria alocada dinamicamente correta, valores preenchidos:");
		printf("\n\n\tNome: %s\n", p1->nome);
		printf("\tIdade: %d\n", p1->idade);
	}
	
	free(p1);
	return 0;
}

struct Pessoa * preencher_pessoa(){
	struct Pessoa *ponteiro = NULL;
	ponteiro = (struct Pessoa*)malloc(sizeof(struct Pessoa));
	
	if(ponteiro){
		strcpy(ponteiro->nome, "Renato Mateus");
		ponteiro->idade = 22;
		return ponteiro;
	}else{
		printf("Erro ao alocar memoria no ponteiro, Retornando NULO;");
		return NULL;
	}
	
	
}
