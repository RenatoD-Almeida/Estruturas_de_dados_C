#include <stdio.h>
#include <stdlib.h>
	
int main(){
	int* preenche_vetor(int tamanho);
	void imprimir_ponteiro(int* p, int tamanho);
	
	int *p = NULL;
	int tamanho = 0;
	
	printf("Digite o tamanho de seu vetor: ");
	scanf("%d", &tamanho);
	
	p = preenche_vetor(tamanho);
	imprimir_ponteiro(p, tamanho);	
	
	free(p);
	return 0;
}

int* preenche_vetor(int tamanho){
	int* p;
	p = (int*)malloc(tamanho * sizeof(int));
	
	if(p){
		int i = 0;
		printf("Tamanho de memoria alocada com sucesso: %d posicoes", tamanho);
		printf("\nTotalizando %d bytes", (tamanho * sizeof(int)));
		printf("\n\n\tPreenchendo o vetor com 1...\n");
		
		while(i < tamanho){
			*(p + i) = 1;
			++i;
		}
		return p;
	}else{
		printf("Erro ao alocar memoria");
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
