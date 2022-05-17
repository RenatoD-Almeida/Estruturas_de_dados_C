#include <stdio.h>
#include <stdlib.h>
	
int main(){
	int* p;
	
	p = (int*)malloc(sizeof(int));
	
	if(p){
		printf("Memoria alocada com sucesso\n");
		*p = 40;
		printf("\tValor inserido em p:\n\t%d", *p);
		
	}else{
		printf("Erro ao alocar memoria");
	}
	
	free(p);
	return 0;
}
