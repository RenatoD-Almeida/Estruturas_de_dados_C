#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int* p;
	
	p = (int*)calloc(2, sizeof(int)); // parametro (quantidade de "inteiros", tamanho em bytes)
	
	if(p){
		printf("Memoria alocada com sucesso\n");
		*p = 30;
		printf("\tValor para p: %d", *p);
	}else{
		printf("Erro ao alocar memoria");
	}
	
	free(p);
	return 0;
}
