#include <stdio.h>
#include <stdlib.h>

#define QUIT '6'

struct Itens{
	char objeto[30];
	int quantidade;
};

struct NO{
	struct Itens Item;
	struct NO *proximo;
};

typedef struct Lista_Dinamica{
	struct NO *inicio;	
}LD;

struct Itens cadastrar_item(){
	struct Itens I;
	printf("Digite o nome do item: ");
	scanf("%30[^\n]%*c", I.objeto);
	printf("Digite a quantidade: ");
	scanf("%d%*c", &I.quantidade);
	return I;
}

void imprimir_item(struct Itens I){
	printf("\t%5s\t -\t%d\n", I.objeto, I.quantidade);
}

int tamanho_da_lista(LD *F){
	struct NO *aux = F->inicio;
	int i = 0;
	while(aux){
		++i;
		aux = aux->proximo;
	}
	return i;
}

void iniciar_lista(LD *F){
	F->inicio = NULL;
}

void adicionar_inicio(LD *F){
	struct NO *novo;
	novo = (struct NO*)malloc(sizeof(struct NO));
	if(novo){
		novo->Item = cadastrar_item();
		novo->proximo = F->inicio;
		F->inicio = novo;
	}else{
		printf("\nErro ao alocar memoria.\n");
	}
	
}

void adicionar_fim(LD *F){
	struct NO *novo;
	novo = (struct NO*)malloc(sizeof(struct NO));
	if(novo){
		novo->Item = cadastrar_item();
		novo->proximo = NULL;
		
		if(!F->inicio){
			F->inicio = novo;
		}else{
			struct NO *aux;
			aux = F->inicio;
			while(aux->proximo){
				aux = aux->proximo;
			}
			aux->proximo = novo;
		}
	}else{
		printf("\nErro ao alocar memoria.\n");
	}
}

void adicionar_meio(LD *F, int inserir){
	struct NO *novo = (struct NO *)malloc(sizeof(struct NO));
	struct NO *aux;
	if(novo){
		novo->Item = cadastrar_item();
		if(!F->inicio){
			novo->proximo = NULL;
			F->inicio = novo;
		}else{
			aux = F->inicio;
			int i = 0;
			if(inserir < tamanho_da_lista(F)){
				while(i < inserir - 1){
					aux = aux->proximo;
					++i;
				}
				novo->proximo = aux->proximo;
				aux->proximo = novo;
				
			}else if(inserir + 1 == (tamanho_da_lista(F))){
				while(i < inserir){
					aux = aux->proximo;
				}
				aux->proximo = novo;
			}else{
				printf("\nIndice alem do tamanho da pilha.\n");
				getchar();
			}
		}
	}else{
		printf("Erro ao alocar memoria.\n");
	}
}

void imprimir_lista(LD *F){
	struct NO *aux = F->inicio;
	int i = 0;
	printf("\n\tItem.\t - \tQtd.\n");
	printf("\t~~~~~~~~~~~~~~~~~~~~\n");
	while(aux){
		printf("%d ", i);
		imprimir_item(aux->Item);
		aux = aux->proximo;
		++i;
	}
	printf("\t~~~~~~~~~~~~~~~~~~~~\n");
}

void menu_utilidade(LD *F, char opcao){
	int indice;
	switch(opcao){
		case '1':
			adicionar_inicio(F);
			break;
		case '2':
			if(F->inicio){
			printf("\nDigite o indice que desaja inserir o item: ");
			imprimir_lista(F);
			scanf("%d", &indice); fflush(stdin);
			adicionar_meio(F, indice);			
			}else{
				adicionar_meio(F, 0);
			}
			break;
		case '3':
			adicionar_fim(F);
			break;
		case '4':
			imprimir_lista(F);
			getchar();
			break;						
		case '5':
			printf("Quantidade de itens a lista: %d", tamanho_da_lista(F));
			getchar();
			break;
		case '6':
			printf("\n----- Ate logo -----\n");
			break;
		default:
			printf("Opcao invalida!.\n");
			getchar();
			break;
	}
}

char menu(LD *F){
	char opcao;
	system("cls");
	printf("=======================\n");
	printf("     Menu da Lista     \n");
	printf("=======================\n");
	printf("1) Adicionar no inicio.\n");
	printf("2) Adicionar no meio.  \n");
	printf("3) Adicionar no fim.   \n");
	printf("4) Imprimir lista.     \n");
	printf("5) Volume da lista.    \n\n");
	printf("6) Sair.               \n");
	printf("=======================\n");
	printf("-> "); 
	scanf("%c", &opcao); fflush(stdin);
	menu_utilidade(F, opcao);
	return opcao;
}

void desalocar_tudo(LD *F){
	struct NO *Iterador, *Deletar;
	Deletar = Iterador = F->inicio;
	while(Iterador){
		Iterador = Iterador->proximo;
		free(Deletar);
		Deletar = Iterador;
	}
}

int main(){
	
	char opcao = ' ';
	
	LD lista;
	iniciar_lista(&lista);
	
	do{
		opcao = menu(&lista);
	}while(opcao != QUIT);
	

	desalocar_tudo(&lista);
	return 0;
}
