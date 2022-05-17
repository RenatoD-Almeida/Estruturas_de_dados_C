#include <stdio.h>
	
int main(){
	// Functions
	int tamanho_vetorial(int vetor[]);
	void ordenar_crescente(int vetor[], int tam);
	void imprimir_vetor(int vetor[]);
	
	// Vars
	int array[] = {3, 10, 5, 6, 9, 15, 23, 41, 16, 2, 0};
	
	// Script
	ordenar_crescente(array, tamanho_vetorial(array));
	imprimir_vetor(array);
	return 0;
}

int tamanho_vetorial(int vetor[]){
	int i = 0;
	while(vetor[i] != '\0'){
		++i;
	}
	return i;
}


void ordenar_crescente(int vetor[], int tam){
	int i, j, aux;
	i = j = 0;
	for( i ; i < tam; ++i){
		for ( j = i; j < tam; ++j){
			if(vetor[i] > vetor[j]){
				aux = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = aux;
			}
		}
	}
}

void imprimir_vetor(int vetor[]){
	int i = 0;
	printf("[");
	while(vetor[i] != '\0'){
		printf(" %d ", vetor[i]);
		++i;	
	}
	printf("]");
}
