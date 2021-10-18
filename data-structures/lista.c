#include <stdio.h>
#include <stdlib.h>


/*
CÓDIGO QUE CRIA UMA LISTA NA QUAL PODEMOS
 INSERIR VALORES NO COMEÇO OU NO FINAL
*/


/*
Structs para definir o nó, e a struct lista em si
*/

typedef struct node {
	int dado;
	struct node *next;
}node;

typedef struct lista {
	node *head;
	node *tail;
	int tamanho;
}lista;


/*
DECLARANDO TODAS AS FUNÇÕES CRIADAS
*/

void init (lista *alista);
void insereComeco (lista *alista, node *novo);
void insereFinal (lista *alista, node *novo);
void printList (lista *alista);


int main(void)
{

	/*
	Declarando variáveis e alocando espaço para a lista
	*/

	int n, selecao;
	lista *alista;

	alista = (lista*) malloc(sizeof(lista));

	/*
	Função init (alista) inicializa os ponteiros da lista criada sendo iguais a NULL, e define o tamanho como 0
	*/

	init (alista);

	while (n != -1) {
		if (n != -1) {
			node *novo;
			novo = (node*)malloc(sizeof(node));
			
			/*
			Mostra as opções de escolha de inserção para o usuário
			*/

			printf("\n\n1 - Inserir no Começo\n2 - Inserir no Final\n3 - Printar\n-1 - Sair do Prog.\n\n--> ");
			scanf("%d", &selecao);

			/*
			Caso a seleção não seja para sair, ele entra no bloco
			*/

			if (selecao > 0 && selecao < 3) {
				printf("Inserir--> ");
				scanf("%d", &n);

				/*
				Ele atualiza o valor de dado em novo.
				*/

				novo->dado = n;

				if (selecao == 1) {
					insereComeco(alista, novo);
					
				} else if (selecao == 2) {
					insereFinal(alista, novo);
				}

			} else if (selecao == 3) {

				/*
				Chama função para printa a lista de forma da esquerda para direita
				*/

				printList (alista);
			} else 
				break;	
		} 
	}
}

void init (lista *alista) 
{	
	alista->head = NULL;
	alista->tail = NULL;
	alista->tamanho = 0;
}

void insereComeco (lista *alista, node *novo)
{
	if (alista != NULL) {
		if (alista->head == NULL) {
			novo->next = alista->head;
			alista->head = novo;
			alista->tail = novo;
		} else {
			novo->next = alista->head;
			alista->head = novo;
		}
		alista->tamanho++;
	} else {
		printf("EMPTY STACK!!\n");
	}
	
}

void insereFinal (lista *alista, node *novo)
{
	if (alista != NULL) {
		if (alista->head == NULL) {
			alista->head = novo;
			alista->tail = novo;
		}else {
			alista->tail->next = novo;
			alista->tail = novo;
			novo->next = NULL;
		}
		alista->tamanho++;
		
	} else {
		printf("EMPTY STACK!!\n");
	}
}

void printList (lista *alista)
{
	node *p = (node*) malloc(sizeof(node));

	for (p = alista->head; p!=NULL; p = p->next) {
		printf("%d\t", p->dado);
	}
}