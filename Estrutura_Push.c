#include <stdio.h>

//Estrutura Push!!!

struct Data{
	int dia, mes, ano;
};

struct Pessoa{
	char nome[50];
	struct Data data;
};

struct No{
	struct Pessoa p;
	struct No *proximo;
};

	
int main(){
	// Declaração das funções:
	struct Pessoa ler_pessoa();
	void imprimir_pessoa(struct Pessoa p);
	
	// Declaração das variáveis:
	struct No *topo = NULL;
	struct Pessoa pessoa;
	int opcao;
	
	// Script:	
	
	do{
		printf("--------------------\n");
		printf("0 - Sair");
		printf("\n1 - Empilhar");
		printf("\n2 - Desempilhar");
		printf("\n3 - Imprimir");
		printf("\n--------------------\n");
		scanf("%d", &opcao); fflush(stdin);
		
		switch(opcao){
		
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 0:
				break;
				
		}
		
	}while(opcao != 0);
	
	return 0;
}

struct Pessoa ler_pessoa(){
	struct Pessoa p;
	printf("Digite o nome da nova pessoa: ");
	fgets(p.nome, 50, stdin); fflush(stdin);
	printf("Digite a data de nascimento: [dd mm aa]: ");
	scanf("%d%d%d", &p.data.dia, &p.data.mes, &p.data.ano); fflush(stdin);
	return  p;
}

void imprimir_pessoa(struct Pessoa p){
	printf("\tNome: %s", p.nome);
	printf("\tData de nascimento: %d/%2d/%d", p.data.dia, p.data.mes, p.data.ano);
}

// FUNÇÃO PARA A OPERAÇÃO PUSH (empilhar):

// *** empilhar(No *topo)

