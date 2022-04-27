#include <stdio.h>
#include "datalib.h"
#include "sortlib.h"

int main (void)
{
	int numero, opcao;
	Dlist *alista =  malloc(sizeof(Dlist));
	
	inicializa (alista);
	
	while(1) {
		printf("1 - INSERE INICIO   |   2 - INSERE FIM   |   3 - REMOVE INICIO\n");
		printf("4 - REMOVE FIM      |   5 - PRINT        |   6 - PRINT INVERTIDO\n");
		printf("7 - BUSCA\n0 - EXIT\n");
		scanf(" %d", &opcao);

		switch (opcao) {
			case 1:
				printf("Digite um número: ");
				scanf(" %d", &numero);
				insert_first (alista, numero);
				printf("\n");
				continue;
			case 2:
				printf("Digite um número: ");
				scanf(" %d", &numero);
				insert_last (alista, numero);
				printf("\n");
				continue;
			case 3:
				remove_first (alista);
				printf("\n");
				continue;
			case 4:
				remove_last (alista);
				printf("\n");
				continue;
			case 5: 
				print(alista);
				printf("\n");
				continue;
			case 6:
				printInvertido(alista);
				printf("\n");
				continue;
			case 7:
				printf("Buscar número: ");
				scanf("%d", &numero);
				busca (alista, numero);
				printf("\n");
				continue;
			case 8:
				insertionSort(alista);
				printf("\n");
				continue;				
			default:
				printf("!!EXIT!!\n");
				return 0;
		}


		printf("\n");
	}
}