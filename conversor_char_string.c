#include <stdio.h>
#include <stdlib.h>	

int main(){
	
	char* caractere_string(char letra);
	
	char c;
	char* p = NULL;
	
	printf("Digite um caractere: ");
	scanf("%c", &c);
	
	 /*Apontador p recebe o endereço do vetor alocado.*/
	 
	p = caractere_string(c);
	
	printf("Char agora string: %s", p);
	free(p);
	return 0;
}

char* caractere_string(char letra){
	
	char* t = NULL;
	
	/* Aloca um vetor (string) com dois caracteres (2 bytes) 
    na heap. O endereço do vetor alocado fica armazenado 
    no apontador t. */
	
	t = (char*)calloc(2, sizeof(char));
	
	/* Preenche o vetor alocado a partir do apontador
    usando notação convencional de vetores.
    O segundo byte é usado para armazenar o 
    caracter de final de string '\0' */
	
	if(t){
		printf("Memoria alocada com sucesso\n");
		*t = letra;
		*(t + 1) = '\0';
		
		/*Devolve o endereço do vetor alocado (string). */
		
		return t;
	}else{
		
		/* Caso não seja possível alocar memória a esse ponteiro, retornará o valor NULL */
		
		printf("Erro ao alocar memoria\n");
		return NULL;
	}
	
}
