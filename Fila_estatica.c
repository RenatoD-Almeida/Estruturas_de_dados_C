#include <stdio.h>
#include <stdlib.h>

struct Data_nascimento{
	int dia;
	int mes;
	int ano;
};

struct Pessoa{
	char nome[50];
	struct Data_nascimento data;
};

struct NO{
	struct Pessoa pessoa;
	struct NO *anterior;
};

struct Stack{
	struct NO * topo_da_pilha;
	int tamanho;
};



void cadastra_pessoa(struct Pessoa * p);
void imprimir_pessoa(struct Pessoa p);
void iniciar_stack(struct Stack * pilha);

	
int main(){
	
	struct Pessoa p1;
	cadastra_pessoa(&p1);
	imprimir_pessoa(p1);
	
	return 0;
}

struct Pessoa cadastra_pessoa(){
	struct Pessoa p;
	printf("\n------- CADASTRO -------\n");
	printf("Nome: ");
	fgets(p.nome, 50, stdin); fflush(stdin);
	printf("\nData de nascimento: [dd mm aaaa]: ");
	scanf("%d %d %d", &p.data.dia, &p.data.mes, &p.data.ano); fflush(stdin);
	printf("\n----- FIM CADASTRO -----\n");
	
}

void imprimir_pessoa(struct Pessoa p){
	printf("\nNome: %s", p.nome);
	printf("Data de nascimento: %d/%d/%d", p.data.dia, p.data.mes, p.data.ano);
}

void iniciar_stack(struct Stack * pilha){
	pilha->topo_da_pilha = NULL;
	pilha->tamanho = 0;
}

void push(struct Stack * pilha){
	struct No *novo_NO;
	novo_NO = (struct NO *)malloc(sizeof(struct NO));
	if(novo_NO){
		
	}else{
		
	}
}

