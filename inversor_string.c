#include <stdio.h>
	
int main(){
	int tamanho_string(char vetor[]);
	void inverter_string(char frase[], int tam);
	
	char nome[] = "Qualquer Frase";
	inverter_string(nome, tamanho_string(nome));
	printf("%s", nome);
	
	return 0;
}

int tamanho_string(char frase[]){
	int i;
	while(frase[i] != '\0'){
		++i;
	}
	return i - 1;
}

void inverter_string(char frase[], int tam){
	int i;
	char aux;
	for(i = 0; i < tam/2; ++i){
		aux = frase[i]; 
		frase[i] = frase[tam - i];
		frase[tam - i] = aux;
	}
}
