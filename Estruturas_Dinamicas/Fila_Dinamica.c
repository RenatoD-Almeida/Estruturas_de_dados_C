#include <stdio.h>
#include <stdlib.h>

#define exit '4'


// É o tipo de dado que escolhi trabalhar nesse programa.
struct Pessoa{
	char nome[50];
};

// Defini o Nó, que são conjuntos de dados com ponteiros que apontam pra outros nós, facilitando o encadeamento das estruturas
struct NO{
	struct Pessoa pessoa;
	struct NO *proximo;
};

/* Decidi trabalhar com struct da fila dinâmica, pois lidar com um ponteiro dentro do main parece uma maneira mais genêrica, já 
que o ponteiro em si para um Nó não se diz nada em questões das regras das TADS */

typedef struct Fila_Dinamica{
	struct NO *inicio_da_fila;
}FD;

//função menu
void menu_faz(int op, FD *fila);
int menu(FD *fila);
void continuar();

// funções para struct Pessoa
struct Pessoa cadastrar_pessoa();
void imprimir_pessoa(struct Pessoa p);

// funções para Fila_Dinamica
void iniciar_fila(FD *fila);
void push(FD *fila);
void pop(FD *fila);
void printR(FD *fila);
void desalocar(FD *fila);

	
int main(){
	
	// Criação da fila, e inicialização dela.
	FD fila;		
	iniciar_fila(&fila);
	
	char op = ' '; // Var para controlar o menu
	
	// Menu propriamente dito, uma função e um procedimento realizam a tarefa do menu.
	while(op != exit){
		op = menu(&fila);
	}
	
	/* Desaloca a memória para cada novo nó criado. É importante desalocar memoria depois de alocar dinamicamente */
	desalocar(&fila);
	
	return 0;
}

// Função para definir que a fila foi iniciada, atribui o valor nulo ao bloco de controle da struct fila_dinamica
void iniciar_fila(FD *fila){
	fila->inicio_da_fila = NULL;
}

/* Adiciona um Nó a estrutura Fila_Dinamica, funciona da seguinte maneira:
- Cria um novo ponteiro para Nó e aloca memoria para que ele possa funcionar como uma variável.
- Cadastra as informações dentro do nó, como por exemplo a função cadastrar_pessoa().
- Faz com que o ponteiro para Nó desse novo Nó mire no nulo, pois ele é o ultimo da fila.
- Se a fila estiver vazia (inicio = nulo) faz com que esse ponteiro da structfila_dinamica mire nesse primeiro elemento criado
- Se não estiver vazia, percorre a fila procurando o Nó em que o ponteiro *proximo seja nulo, e faz com que mire para
esse novo nó criado. 

__ E depois de tudo isso Voilà, seu novo nó foi criado em sua fila dinâmica __
*/
void push(FD *fila){
	struct NO *novo_NO = NULL;
	novo_NO = (struct NO*)malloc(sizeof(struct NO));
	novo_NO->pessoa = cadastrar_pessoa();
	novo_NO->proximo = NULL;
	if(!fila->inicio_da_fila){
		fila->inicio_da_fila = novo_NO;
	}else{
		struct NO *aux;
		aux = fila->inicio_da_fila;
		while(aux->proximo){
			aux = aux->proximo;
		}
		aux->proximo = novo_NO;
	}
}

/* Função que remove um nó criado. Funciona da seguinte maneira: 
- Verifica primeiramente se a fila se encontra vazia (Lugar onde o inicio da fila aponta é NULL? )
- Se sim, não há o que remover, então ele sai do bloco de código
- Se não, então temos de demover o nó:
	-> criamos um ponteiro para auxiliar, aconselho a fazer isso para não mexer diretamente na fila e trazer problemas no futuro
	-> Fazemos esse ponteiro mirar no inicio da fila, já que a remoção sempre é feita no inicio.
	-> Fazemos o ponteiro que mira para o primeiro elemento mirar para o ponteiro *proximo dele (aponta para o segundo elemento)
	-> Por fim, damos um Free para desalocar a memoria dele, fazendo com que ele não tenha mais valor.*/


void pop(FD *fila){
	if(!fila->inicio_da_fila){
		printf("\nFila atualmente vazia!\n");
		continuar();
	}else{
		struct NO *deletar;
		deletar = fila->inicio_da_fila;
		fila->inicio_da_fila = fila->inicio_da_fila->proximo;
		printf("\n%s saiu da fila\n", deletar->pessoa.nome);
		continuar();
		free(deletar);
	}
}
/* Função que percorre a fila e imprimi os dados. Funciona assim:
- Verificamos se está vazio: Se sim, não imprimimos a fila, se não:
	-> percorremos a fila desde o inicio utilizando o ponteiro *proximo de cada elemento */
void printR(FD *fila){
	struct NO *auxiliar;
	auxiliar = fila->inicio_da_fila;
	if(!auxiliar){
		printf("\nFila atualmente vazia!\n");
		continuar();
	}else{
		printf("Fila: [ ");
		while(auxiliar){
			imprimir_pessoa(auxiliar->pessoa);
			auxiliar = auxiliar->proximo;
		}
		printf("]");
		continuar();
	}
}
/* Função para cadastrar o nome da pessoa */
struct Pessoa cadastrar_pessoa(){
	system("cls");
	struct Pessoa p;
	printf("============================\n");
	printf("Digite o nome da nova pessoa\n");
	printf("============================\n");
	printf("-> ");
	scanf("%50[^\n]%*c", &p.nome);
	return p;
}

/* Função que imprimi os dados da pessoa, neste caso apenas nome */ 
void imprimir_pessoa(struct Pessoa p){
	printf("%s, ", p.nome);
}

/* Função de menu, retorna um inteiro para o controle da saída do ciclo while no main
-> essa função chama a função menu_faz para dar funcionalidade ao menu, fazendo com que assim não seja
necessário a poluição de código no main */

int menu(FD *fila){
	char opcao = 0;
	system("cls");
	printf("+==========================+\n");	
	printf("|            MENU          |\n");
	printf("+==========================+\n");
	printf("|     1 - Push()           |\n");
	printf("|     2 - Pop()            |\n");
	printf("|     3 - Print Row()      |\n");
	printf("|                          |\n");
	printf("|     4 - Exit()           |\n");
	printf("+==========================+\n");
	printf("   -> ");
	scanf("%c%*c", &opcao);
	menu_faz(opcao, fila);
	return opcao;
}
/*opção que dá funcionalidade ao menu, basicamente chamando cada função respectiva a legenda do menu */
void menu_faz(int op, FD *fila){
	switch(op){
		case '1':
			push(fila);
			break;
		case '2':
			pop(fila);
			break;
		case '3':
			printR(fila);
			break;
		case '4':
			break;
		default:
			printf("\nOpcao invalida!");
			continuar();
	}
}

/* Apenas para não escrever isso um milhão de vezes hehe */
void continuar(){
	printf("\nPressione ENTER para continuar...\n");
	getchar(); fflush(stdin);
}

/* mais IMPORTANTE, ao alocar memória é importante você desalocar depois de utilizar. Basicamente essa função funciona assim:
- Criamos dois ponteiros, (desalocar e auxiliar) e ambos apontam para o inicio da fila.
- Um irá apontar para o proximo elemento. (auxiliar)
- Outro (desalocar) receberá a desalocação de memoria. desalocando então o primeiro da fila
- O ponteiro desalocar apontará para o mesmo lugar que o auxiliar.
- O auxiliar apontará para o proximo elemento (auxiliar->proximo)
- Assim repetindo o ciclo. */

void desalocar(FD *fila){
	struct NO *desalocar, *auxiliar;
	desalocar = auxiliar = fila->inicio_da_fila;
	if(fila->inicio_da_fila){
		while(auxiliar){
			auxiliar = auxiliar->proximo;
			free(desalocar);
			desalocar = auxiliar;
		}	
	}
	printf("\n~~~~~~ Ate logo ~~~~~~\n");
	printf("\n    Fila esvaziada!   \n");
	printf("\n~~~~~~~~~~~~~~~~~~~~~~\n");
	
}






