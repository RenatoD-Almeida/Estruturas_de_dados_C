#include <stdio.h>
#include <stdlib.h>

//Estrutura Push!!!

struct Pessoa{
	char nome[50];
	int idade;
};

struct No{
	struct Pessoa p;
	struct No *anterior;
};

struct Pessoa ler_pessoa();
void imprimir_pessoa(struct Pessoa p);

struct No * push(struct No *topo);



int main(){
		
	struct No *topo = NULL;

	topo = push(topo);
	
	
	
	return 0;
}

void imprimir_pessoa(struct Pessoa p){
	printf("\tNome: %s", p.nome);
	printf("\tIdade: %d\n", p.idade);
}

struct Pessoa ler_pessoa(){
	struct Pessoa p;
	printf("Digite o nome da pessoa:\n");
	fgets(p.nome, 50, stdin); fflush(stdin);
	printf("\nDigite a idade do(a) %s",p.nome);
	scanf("%d", &p.idade);
	return p;
}

struct No * push(struct No *topo){
	struct No *novo = NULL;
	novo = (struct No *)malloc(sizeof(struct No));
	if(novo){
		novo->p = ler_pessoa();
		novo->anterior = topo;
		return novo;
	}else{
		printf("Erro ao alocar memoria");
		return NULL;
	}
}



