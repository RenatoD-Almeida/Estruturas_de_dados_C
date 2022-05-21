#include <stdio.h>
#include <stdlib.h>

struct Pessoa{
	char nome[50];
	int idade;
	float peso, altura;
};

struct Pilha_Estatica{
	struct Pessoa clientes[10];
	int topo_da_pilha;
};
	
void iniciar_pilha(struct Pilha_Estatica * p);
void push(struct Pilha_Estatica * p);
void imprimir_pilha(struct Pilha_Estatica p);
void pop(struct Pilha_Estatica * p);

struct Pessoa cadastrar_pessoa();
void ler_pessoa(struct Pessoa p);

int main(){
	
	struct Pilha_Estatica p1;
	struct Pessoa removido;
	iniciar_pilha(&p1);
	push(&p1);
	push(&p1);
	imprimir_pilha(p1);
	pop(&p1);
	imprimir_pilha(p1);
	pop(&p1);
	
	
	return 0;
}

struct Pessoa cadastrar_pessoa(){
	struct Pessoa p;
	printf("---------- Cadastro ----------\n");
	printf("Nome:\n");
	scanf("%50[^\n]%*c", &p.nome);
	printf("Idade:\n");
	scanf("%d%*c", &p.idade);
	printf("Peso:\n");
	scanf("%f%*c", &p.peso);
	printf("Altura:\n");
	scanf("%f%*c", &p.altura);
	return p;
}

void ler_pessoa(struct Pessoa p){
	printf("\n\tNome: %s", p.nome);
	printf("\tIdade: %d\n", p.idade);
	printf("\tPeso: %.2f", p.peso);
	printf("\tAltura: %.2f\n", p.altura);
}

void iniciar_pilha(struct Pilha_Estatica * p){
	p->topo_da_pilha = 0;
}

void push(struct Pilha_Estatica * p){
	p->clientes[p->topo_da_pilha] = cadastrar_pessoa();
	++p->topo_da_pilha;
}

void pop(struct Pilha_Estatica * p){
	if(p->topo_da_pilha){
		--p->topo_da_pilha;
	}else{
		printf("\n\tPilha ja vazia.\n");
	}
	
}

void imprimir_pilha(struct Pilha_Estatica p){
	int i = p.topo_da_pilha - 1;
	printf("\t---------- Inicio Pilha ----------\n");
	while(i >= 0){
		ler_pessoa(p.clientes[i]);
		i--;
	}
	printf("\t---------- Fim da Pilha ----------\n");
}

