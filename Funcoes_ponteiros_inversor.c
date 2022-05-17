#include <stdio.h>
#include <stdlib.h>

	
int main(){
	void imprimir_crescente(int *p, int tam);
	void imprimir_decrescente(int *p, int tam);
	int* preenche_vetor(int tam);
	
	int tamanho, *ponteiro;
	
	printf("Digite o tamanho do seu vetor: ");
	scanf("%d", &tamanho);
	
	ponteiro = preenche_vetor(tamanho);
	imprimir_crescente(ponteiro, tamanho);
	imprimir_decrescente(ponteiro, tamanho);
	
	free(ponteiro);
	return 0;
}


int* preenche_vetor(int tam){
	int i = 0;
	int* p = NULL;
	
	p = (int*)malloc(sizeof(int) * tam);
	
	if(p){
		while(i < tam){
			printf("Digite o valor da posicao %i: ", i);
			scanf("%d", (p + i));
			++i;
		}
		return p;	
	}else{
		printf("Erro ao alocar memória, returnando NULO");
		return NULL;
	}
}

void imprimir_crescente(int *p, int tam){
	int i;
	printf("vetor: ( ");
	for(i = 0; i < tam; ++i){
		printf("%d ", *(p + i));
	}
	printf(")");
}

void imprimir_decrescente(int *p, int tam){
	int i;
	printf("\nvetor inverso: ( ");
	for(i = 0; i < tam; ++i){
		printf("%d ", *(p + ((tam-1) - i))); // igual a p[(tam - 1) - i]
	}
	printf(")");
}
