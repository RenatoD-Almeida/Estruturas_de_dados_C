#include <stdio.h>
#include <stdlib.h>
	
#define tam 10
#define exit 0

struct Dado{
	int valor;
};

struct Lista_Estatica{
	struct Dado dado[tam];
	int tamanho;
};

void iniciar_lista(struct Lista_Estatica *fila){
	fila->tamanho = 0;
}

void inserir_inicio(struct Lista_Estatica *lista){
	system("cls");
	printf("================\n");
	printf(" Insira o valor \n");
	printf("================\n"); 
		
	if(lista->tamanho == 0){
		scanf("%d%*c", &lista->dado[0]);
	}else{
		int i, aux;
		for(i = 0; i < lista->tamanho; ++i){
			lista->dado[i + 1].valor = lista->dado[i].valor;
		}
		scanf("%d%*c", &lista->dado[0]);
	}
	lista->tamanho++;
}

void imprimir_lista(struct Lista_Estatica lista){
	int i = 0;
	printf("=============\n");
	printf("    LISTA    \n");
	printf("=============\n");
	while(i < lista.tamanho){
		printf("Item %d: %d\n", i, lista.dado[i]);
		++i;
	}
	printf("=============\n");
}
int main(){
	
	struct Lista_Estatica lista;
	iniciar_lista(&lista);
	
	inserir_inicio(&lista);
	inserir_inicio(&lista);
	inserir_inicio(&lista);
	
	imprimir_lista(lista);
	return 0;
}
