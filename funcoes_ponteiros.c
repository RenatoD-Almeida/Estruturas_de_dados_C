#include <stdio.h>
	
int main(){
	void imprimir_vetor(int* p);
	int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	imprimir_vetor(vetor);
	
	
	return 0;
}

void imprimir_vetor(int* p){
	int i=0;
	printf("[ ");
	for (i; i < 10; ++i){
		printf("%d ", *(p + i));
	}
	printf("]");
}
