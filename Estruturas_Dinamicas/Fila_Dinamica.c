#include <stdio.h>
#include <stdlib.h>

#define exit '4'


// � o tipo de dado que escolhi trabalhar nesse programa.
struct Pessoa{
	char nome[50];
};

// Defini o N�, que s�o conjuntos de dados com ponteiros que apontam pra outros n�s, facilitando o encadeamento das estruturas
struct NO{
	struct Pessoa pessoa;
	struct NO *proximo;
};

/* Decidi trabalhar com struct da fila din�mica, pois lidar com um ponteiro dentro do main parece uma maneira mais gen�rica, j� 
que o ponteiro em si para um N� n�o se diz nada em quest�es das regras das TADS */

typedef struct Fila_Dinamica{
	struct NO *inicio_da_fila;
}FD;

//fun��o menu
void menu_faz(int op, FD *fila);
int menu(FD *fila);
void continuar();

// fun��es para struct Pessoa
struct Pessoa cadastrar_pessoa();
void imprimir_pessoa(struct Pessoa p);

// fun��es para Fila_Dinamica
void iniciar_fila(FD *fila);
void push(FD *fila);
void pop(FD *fila);
void printR(FD *fila);
void desalocar(FD *fila);

	
int main(){
	
	// Cria��o da fila, e inicializa��o dela.
	FD fila;		
	iniciar_fila(&fila);
	
	char op = ' '; // Var para controlar o menu
	
	// Menu propriamente dito, uma fun��o e um procedimento realizam a tarefa do menu.
	while(op != exit){
		op = menu(&fila);
	}
	
	/* Desaloca a mem�ria para cada novo n� criado. � importante desalocar memoria depois de alocar dinamicamente */
	desalocar(&fila);
	
	return 0;
}

// Fun��o para definir que a fila foi iniciada, atribui o valor nulo ao bloco de controle da struct fila_dinamica
void iniciar_fila(FD *fila){
	fila->inicio_da_fila = NULL;
}

/* Adiciona um N� a estrutura Fila_Dinamica, funciona da seguinte maneira:
- Cria um novo ponteiro para N� e aloca memoria para que ele possa funcionar como uma vari�vel.
- Cadastra as informa��es dentro do n�, como por exemplo a fun��o cadastrar_pessoa().
- Faz com que o ponteiro para N� desse novo N� mire no nulo, pois ele � o ultimo da fila.
- Se a fila estiver vazia (inicio = nulo) faz com que esse ponteiro da structfila_dinamica mire nesse primeiro elemento criado
- Se n�o estiver vazia, percorre a fila procurando o N� em que o ponteiro *proximo seja nulo, e faz com que mire para
esse novo n� criado. 

__ E depois de tudo isso Voil�, seu novo n� foi criado em sua fila din�mica __
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

/* Fun��o que remove um n� criado. Funciona da seguinte maneira: 
- Verifica primeiramente se a fila se encontra vazia (Lugar onde o inicio da fila aponta � NULL? )
- Se sim, n�o h� o que remover, ent�o ele sai do bloco de c�digo
- Se n�o, ent�o temos de demover o n�:
	-> criamos um ponteiro para auxiliar, aconselho a fazer isso para n�o mexer diretamente na fila e trazer problemas no futuro
	-> Fazemos esse ponteiro mirar no inicio da fila, j� que a remo��o sempre � feita no inicio.
	-> Fazemos o ponteiro que mira para o primeiro elemento mirar para o ponteiro *proximo dele (aponta para o segundo elemento)
	-> Por fim, damos um Free para desalocar a memoria dele, fazendo com que ele n�o tenha mais valor.*/


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
/* Fun��o que percorre a fila e imprimi os dados. Funciona assim:
- Verificamos se est� vazio: Se sim, n�o imprimimos a fila, se n�o:
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
/* Fun��o para cadastrar o nome da pessoa */
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

/* Fun��o que imprimi os dados da pessoa, neste caso apenas nome */ 
void imprimir_pessoa(struct Pessoa p){
	printf("%s, ", p.nome);
}

/* Fun��o de menu, retorna um inteiro para o controle da sa�da do ciclo while no main
-> essa fun��o chama a fun��o menu_faz para dar funcionalidade ao menu, fazendo com que assim n�o seja
necess�rio a polui��o de c�digo no main */

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
/*op��o que d� funcionalidade ao menu, basicamente chamando cada fun��o respectiva a legenda do menu */
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

/* Apenas para n�o escrever isso um milh�o de vezes hehe */
void continuar(){
	printf("\nPressione ENTER para continuar...\n");
	getchar(); fflush(stdin);
}

/* mais IMPORTANTE, ao alocar mem�ria � importante voc� desalocar depois de utilizar. Basicamente essa fun��o funciona assim:
- Criamos dois ponteiros, (desalocar e auxiliar) e ambos apontam para o inicio da fila.
- Um ir� apontar para o proximo elemento. (auxiliar)
- Outro (desalocar) receber� a desaloca��o de memoria. desalocando ent�o o primeiro da fila
- O ponteiro desalocar apontar� para o mesmo lugar que o auxiliar.
- O auxiliar apontar� para o proximo elemento (auxiliar->proximo)
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






