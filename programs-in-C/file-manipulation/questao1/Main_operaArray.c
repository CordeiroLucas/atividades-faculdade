#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operaArray.h"

int main(void)
{
	int tamanho, i;
	FILE *arquivo = fopen("resultados.txt", "a+");
	
	printf("Tamanho Array - ");
	scanf("%d", &tamanho);

	if (tamanho >= 0) {
		
		int array[tamanho];
		char escolha;

		for (i = 0; i < tamanho; i++) 
			scanf("%d", &array[i]);
		
		i = 0;

		while (1) {
			printf("\nR - newReverse\nE - elemNum\nU - unique\nD - deleteN\nS - sair\n");
			printf("-> ");
			scanf(" %c", &escolha);

			if (escolha == 'R') newReverse (tamanho, array, arquivo);
			else if (escolha == 'E') elemNum (tamanho, array, arquivo);
			else if (escolha == 'U') unique (tamanho, array, arquivo);
			else if (escolha == 'D') deleteN (tamanho, array, arquivo);
			else if (escolha == 'S') {
				fprintf(arquivo, "\n-----------||----------\n\n");
				fclose(arquivo); 
				break;

			} else 
				printf("Dado INVÁLIDO!\n");
		} 
	} else
		printf("Tamanho INVÁLIDO!\n");

}
