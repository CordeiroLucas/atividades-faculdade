#include <stdio.h>
#include <stdlib.h>
#include "datalib.h"

void insertionSort(Dlist *alista)
{
	Node *inicio = alista->inicio;
	Node *i;
	
	for (i = alista->inicio->next; i != NULL; i = i->next) {
		Node *j;
		j = i;
		while ((j->numero < j->prev->numero) && j != inicio) {
			int aux;
			aux = j->prev->numero;

			j->prev->numero = j->numero;
			j->numero = aux;
			j = j->prev;
		}
	}

	for (i = alista->inicio; i != NULL; i = i->next) {
		printf("%d ", i->numero);
	}
}
