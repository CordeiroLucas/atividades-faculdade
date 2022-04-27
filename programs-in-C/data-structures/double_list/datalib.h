#include <stdio.h>
#include <stdlib.h>

struct node {
	int numero;
	char carac;
	struct node *next;
	struct node *prev;
};
typedef struct node Node;

struct doubleList { 
	struct node *inicio;
	struct node *fim;
	int tamanho;
};
typedef struct doubleList Dlist;

//funções

int caracter = 97;

void inicializa (Dlist *alista) 
{
	alista->fim = NULL;
	alista->inicio = NULL;
	alista->tamanho = 0;
	return;
}

void insert_last (Dlist *alista, int num) 
{
	Node *newNode = (Node *) malloc(sizeof(Node));
	newNode->numero = num;
	newNode->carac = caracter;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (alista != NULL) {
		if (alista->inicio == NULL) {
			alista->inicio = newNode;
			alista->fim = newNode;
			alista->tamanho++;
		} else {
			alista->fim->next = newNode;
			newNode->prev = alista->fim;
			alista->fim = newNode;
			alista->tamanho++;
		}
	}
	caracter++;
	return;
} 

void insert_first (Dlist *alista, int num)
{
	Node *newNode = (Node *) malloc(sizeof(Node));
	newNode->numero = num;
	newNode->carac = caracter;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (alista != NULL) {
		if (alista->inicio == NULL) {
			alista->inicio = newNode;
			alista->fim = newNode;
			alista->tamanho++;
		} else {
			newNode->next = alista->inicio;
			alista->inicio = newNode;
			alista->tamanho++;
		}
	}
	caracter++;
	return;
}

void remove_last (Dlist *alista) 
{
	if (alista != NULL) {
		if (alista->inicio != NULL) {
			if (alista->tamanho == 1) {
				inicializa(alista);
			} else {
				alista->fim = alista->fim->prev;
				alista->fim->next = NULL;
				alista->tamanho--;
				return;
			}
		} else {
			printf("EMPTY STACK\n");
		}
	}
	return;
}

void remove_first (Dlist *alista)
{
	if (alista != NULL) {
		if (alista->inicio != NULL) {
			if (alista->tamanho == 1) {
				inicializa(alista);
			} else {
				alista->inicio = alista->inicio->next;
				alista->inicio->prev = NULL;
				alista->tamanho--;
				return;
			}
		} else {
			printf("EMPTY STACK\n");
		}
	}
	return;
}

void print (Dlist *alista) 	
{
	Node *ptr;
	ptr = (Node *) malloc(sizeof(Node));

	if (alista->inicio != NULL) {
		printf("\n| ");
		for (ptr = alista->inicio; ptr != NULL; ptr = ptr->next) {
			printf("%d ", ptr->numero);
		};
		printf ("|");
		printf("\n\nTAMANHO = %d\n", alista->tamanho);
		printf("PRIMEIRO ELM: %d\n", alista->inicio->numero);
		printf("ÚLTIMO ELM: %d\n\n", alista->fim->numero);
	} else {
		printf("\nEMPTY LIST\n");
	}
	return;
}

void printInvertido (Dlist *alista)
{
	Node *ptr;
	ptr = (Node *) malloc(sizeof(Node));

	if (alista->inicio != NULL) 
	{
		printf("\n| ");
		for (ptr = alista->fim; ptr != NULL; ptr = ptr->prev) {
			printf("%d ", ptr->numero);
		}
		printf("|");
		printf("\n\nTAMANHO = %d\n", alista->tamanho);
		printf("PRIMEIRO ELM: %d\n", alista->inicio->numero);
		printf("ÚLTIMO ELM: %d\n\n", alista->fim->numero);
	} else {
		printf("\nEMPTY LIST\n");
	}
	return;
}

void busca (Dlist *alista, int num)
{
	Node *ptr = (Node *) malloc(sizeof(Node));

	if (alista->inicio != NULL) {
		for (ptr = alista->inicio; ptr != NULL; ptr = ptr->next) {
			if (ptr->numero == num) {
				printf("-%c-\n", ptr->carac);
			}
		}
	} else {
		printf("\n!EMPTY STACK ERROR!\n\n");
	}
	return;
}