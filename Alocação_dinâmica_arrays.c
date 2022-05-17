#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	int tam;
	int* vet;
	int i = 0;
	srand(time(NULL));
	
	printf("Digite o tamanho do nosso vetor: ");
	scanf("%d", &tam);
	
	vet = (int*)calloc(tam, sizeof(int));
	
	if(vet){
		
		printf("Memoria alocada com sucesso\n\n");
		for(i = 0; i < tam; ++i){
			*(vet + i) = rand() / 100;
		}
		printf("[ ");
		for(i = 0; i < tam; ++i){
			printf("%d ",*(vet + i));
		}
		printf("]");
	}else{
		printf("Erro ao alocar memoria");
	}
	
	free(vet);
	
	return 0;
}
