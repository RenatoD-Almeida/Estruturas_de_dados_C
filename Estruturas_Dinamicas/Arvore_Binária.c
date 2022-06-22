#include <stdio.h>
#include <stdlib.h>

struct NO{
	int conteudo;
	struct NO *esquerda, *direita;
};

typedef struct Arvore_Binaria{
	struct NO *raiz;	
}AB;

void iniciar_arvore(AB *arvore){
	arvore->raiz = NULL;
}

void inserir_esquerda(struct NO *no, int valor);
void inserir_direita(struct NO *no, int valor);

void inserir(AB *arvore, int valor){
	if(arvore->raiz == NULL){
		struct NO *novo = (struct NO *)malloc(sizeof(struct NO));
		if(novo){
			novo->conteudo = valor;
			novo->direita = NULL;
			novo->esquerda = NULL;
			arvore->raiz = novo;
		}
	}else{
		if(valor > arvore->raiz->conteudo){
			inserir_direita(arvore->raiz, valor);
		}else{
			inserir_esquerda(arvore->raiz, valor);
		}
	}
}

void imprimir(struct NO *raiz){
	if(raiz){
		imprimir(raiz->esquerda);
		printf("%d ", raiz->conteudo);
		imprimir(raiz->direita);
	}	
}

int main(){
	AB arvore;
	iniciar_arvore(&arvore);
	int op, valor;
	
	do{
		printf("1 - inserir.\n2 - imprimir.\n3 - sair.\n");
		scanf("%d%*c", &op);
		
		switch(op){
			case 1:
				printf("\nDigite um valor: ");
				scanf("%d", &valor);
				inserir(&arvore, valor);
				break;
			case 2:
				printf("\nImpressao da arvore binaria.\n");
				imprimir(arvore.raiz);
				getchar();
				break;
			case 3:
				break;
		}
	}while(op != 3);
	
	
	return 0;
}

void inserir_direita(struct NO *no, int valor){
	if(no->direita == NULL){
		struct NO *novo = (struct NO *)malloc(sizeof(struct NO));
		if(novo){
			novo->conteudo = valor;
			novo->direita = NULL;
			novo->esquerda = NULL;
			no->direita = novo;
		}
	}else{
		if(valor > no->direita->conteudo){
			inserir_direita(no->direita, valor);
		}else{
			inserir_esquerda(no->direita, valor);
		}
	}
}

void inserir_esquerda(struct NO *no, int valor){
	if(no->esquerda == NULL){
		struct NO *novo = (struct NO *)malloc(sizeof(struct NO));
		if(novo){
			novo->conteudo = valor;
			novo->direita = NULL;
			novo->esquerda = NULL;
			no->esquerda = novo;
		}
	}else{
		if(valor > no->esquerda->conteudo){
			inserir_direita(no->esquerda, valor);
		}else{
			inserir_esquerda(no->esquerda, valor);
		}
	}
}
