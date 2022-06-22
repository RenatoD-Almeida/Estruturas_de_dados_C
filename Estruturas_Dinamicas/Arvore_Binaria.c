#include <stdio.h>
#include <stdlib.h>

#define quit 0
	
struct NO{
	int dado;
	struct NO *direita, *esquerda;
};

typedef struct arvore_binaria{
	struct NO *raiz;	
}AB;

void iniciar_arvore(AB *arvore){
	arvore->raiz = NULL;
}

void menu(){
	system("cls");
	printf("===============\n");
	printf("     MENU      \n");
	printf("===============\n");
	printf(" 1 - Inserir   \n");
	printf(" 2 -Imprimir Pre\n");
	printf(" 3 -Imprimir Em\n");
	printf(" 4 -Imprimir Pos\n");
	printf(" 5 - Tamanho\n");
	printf(" 6 - Buscar.\n");
	printf(" 7 - Remover.\n");
	printf(" 0 - Sair      \n");
	printf("===============\n");
}

struct NO * inserir(struct NO *raiz, int valor){
	if(raiz == NULL){
		struct NO *novo = (struct NO *)malloc(sizeof(struct NO));
		if(novo){
			novo->dado = valor;
			novo->direita = novo->esquerda = NULL;
			raiz = novo;
			return raiz;
		}else{
			printf("Erro ao alocar memoria para um novo no.");
			getchar();
		}
	}else{
		if(valor > raiz->dado){
			raiz->direita = inserir(raiz->direita, valor);
		}else{
			raiz->esquerda = inserir(raiz->esquerda, valor);
		}
	}
}

void imprimir_arvore_PreOrdem(struct NO *raiz){
	if(raiz){
		printf("%d, ", raiz->dado);
		imprimir_arvore_PreOrdem(raiz->esquerda);
		imprimir_arvore_PreOrdem(raiz->direita);
	}
}

void imprimir_arvore_EmOrdem(struct NO *raiz){
	if(raiz){
		imprimir_arvore_EmOrdem(raiz->esquerda);
		printf("%d, ", raiz->dado);
		imprimir_arvore_EmOrdem(raiz->direita);
	}
}

void imprimir_arvore_PosOrdem(struct NO *raiz){
	if(raiz){
		imprimir_arvore_PosOrdem(raiz->esquerda);
		imprimir_arvore_PosOrdem(raiz->direita);
		printf("%d, ", raiz->dado);
	}
}

int tamanho_da_arvore(struct NO *raiz){
	if(raiz == NULL){
		return 0;
	}else{
		return 1 + tamanho_da_arvore(raiz->direita) + tamanho_da_arvore(raiz->esquerda);
	}
}

int busca_arvore(struct NO *raiz, int valor){
	if(raiz == NULL){
		return 0;
	}else{
		if(valor == raiz->dado){
			return 1;
		}else{
			if(valor > raiz->dado){
				busca_arvore(raiz->direita, valor);
			}else{
				busca_arvore(raiz->esquerda, valor);
			}
		}
	}
}

struct NO * remover_da_arvore(struct NO *raiz, int valor){
	if(raiz == NULL){
		return NULL;
	}else{
		if(raiz->dado == valor){
			if(raiz->direita == NULL && raiz->esquerda == NULL){
				free(raiz);
				return NULL;
			}else if((raiz->direita == NULL && raiz->esquerda != NULL) || (raiz->direita != NULL && raiz->esquerda == NULL)){
				struct NO *aux;
				if(raiz->esquerda){
					aux = raiz->esquerda;
				}else{
					aux = raiz->direita;
				}
				free(raiz);
				return aux;
			}else{
				struct NO *aux = raiz->esquerda;
				while(aux->direita){
					aux = aux->direita;
				}
				raiz->dado = aux->dado;
				aux->dado = valor;
				raiz->esquerda = remover_da_arvore(raiz->esquerda, valor);
				return raiz;
			}
		}else{
			if(valor < raiz->dado){
				raiz->esquerda = remover_da_arvore(raiz->esquerda, valor);
			}else{
				raiz->direita = remover_da_arvore(raiz->direita, valor);
			}
			return raiz;
		}
	}
}

int main(){
	int op = quit, valor = 0;
	
	struct NO *remover;
	
	AB arvore;
	iniciar_arvore(&arvore);
	
	do{
		menu();
		scanf("%d%*c", &op);
		switch(op){
			case 1:
				printf("Digite o valor a ser inserido: ");
				scanf("%d", &valor);
				arvore.raiz = inserir(arvore.raiz, valor);
				break;
			case 2:
				imprimir_arvore_PreOrdem(arvore.raiz);
				getchar();
				break;
			case 3:
				imprimir_arvore_EmOrdem(arvore.raiz);
				getchar();
				break;
			case 4:
				imprimir_arvore_PosOrdem(arvore.raiz);
				getchar();
				break;
			case 5:
				printf("Tamanho %d", tamanho_da_arvore(arvore.raiz));
				getchar();
				break;
			case 6:
				printf("Digite o valor a ser buscado: ");
				scanf("%d", &valor); fflush(stdin);
				if(busca_arvore(arvore.raiz, valor)){
					printf("Valor encontrado.\n");
				}else{
					printf("Valor nao inserido na arvore ainda.\n");
				}
				getchar();
				break;
			case 7:
				printf("Digite o valor a ser removido: ");
				scanf("%d", &valor); fflush(stdin);
				arvore.raiz = remover_da_arvore(arvore.raiz, valor);
				break;
		}
		
	}while(op != quit);
	
	return 0;
}
