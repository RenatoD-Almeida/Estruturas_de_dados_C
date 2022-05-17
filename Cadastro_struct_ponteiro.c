#include <stdio.h>
	
struct Pessoa{
	char nome[50];
	int idade;
};	
	
int main(){
	
	// Functions
	void cadastrar_pessoa(struct Pessoa x[], int* total);
	void imprimir_pessoa(struct Pessoa x[], int* i);
	
	// Vars
	struct Pessoa pessoas[10];
	int i = 0;
	
	// Scripts
	cadastrar_pessoa(pessoas, &i);
	cadastrar_pessoa(pessoas, &i);
	cadastrar_pessoa(pessoas, &i);
	cadastrar_pessoa(pessoas, &i);
	imprimir_pessoa(pessoas, &i);
	
	
	
	return 0;
}

void cadastrar_pessoa(struct Pessoa x[], int* total){
	printf("Digite o nome da pessoa %d: ", *total);
	fgets(x[*total].nome, 50, stdin); fflush(stdin);
	printf("\nDigite a idade do(a) %s", x[*total].nome);
	scanf("%i", &x[*total].idade); fflush(stdin);
	++*total;
}

void imprimir_pessoa(struct Pessoa x[], int* i){
	int j;
	for (j = 0; j < *i; ++j){
		printf("\n");
		printf("\n\tNome:%s", x[j].nome);
		printf("\tIdade:%i", x[j].idade);
	}
}

/*
void tamanho_vetorial(struct Pessoa x[]){
	int i;
	while(x[i].nome != '\0');
}
*/

