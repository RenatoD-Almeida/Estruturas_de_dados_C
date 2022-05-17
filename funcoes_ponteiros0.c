#include <stdio.h>
#include <stdlib.h>
	
int main(){
	int* preenche_vetor(int tam);
	void imprimir_ponteiro(int* p, int tamanho);
	int* ponteiro;
	
	ponteiro = preenche_vetor(10);
	imprimir_ponteiro(ponteiro, 10);
	
	return 0;
}


int* preenche_vetor(int tam){
	int *p = NULL;
	
	p = (int*)malloc(sizeof(int) * tam);
	
	if(p){
		int i = 0;
		while(i < tam){
			printf("Digite o valor da posicao %d: ", i);
			scanf("%d", (p + i));
			++i;
		}
		return p;
	}else{
		printf("Erro ao alocar memoria: Retorno nulo");
		return NULL;
	}
}

void imprimir_ponteiro(int* p, int tamanho){
	int i = 0;
	printf("\nVetor: [ ");
	while(i < tamanho){
		printf("%d ",*(p + i));
		++i;
	}
	printf("]");
}
