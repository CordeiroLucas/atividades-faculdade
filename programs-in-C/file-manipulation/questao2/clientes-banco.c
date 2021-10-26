#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dado_cliente {
	char nome[100];
	char sobrenome[100];
	int nConta;
	float saldo;
};

int main(void)
{
	FILE *dados_brutos, *devedores;
	struct dado_cliente cliente;
	char c;
	int n, pos, tamanho;
	
	//Abre o arquivo CLIENTES.txt
	dados_brutos = fopen("CLIENTES.txt", "r+");

	if (dados_brutos != NULL) {
		//Loop para contar o número de clientes pelo número de linhas
		tamanho = 0;
		while ((c=fgetc(dados_brutos)) != EOF) {
			if (c == '\n')
				tamanho++;
		}

		printf("número de linhas = %d\n", tamanho);
		
		//Dados Brutos || tamanho - número max de pessoas || [150] - tamanho max da string
		char clientes_linha[tamanho][150];


		//Volta o vetor para o início do arquivo
		fseek(dados_brutos, 3, SEEK_SET);

		printf("\n");

		//Loop para organizar as linhas em um array:
		// clientes_linha[index do cliente][posição do vetor na string]
		n = 0; pos = 0;
		while ((c=fgetc(dados_brutos)) != EOF) {
			
			printf("%c", c);
			clientes_linha[n][pos] = c;
			pos++;

			//Quando o vetor for igual a uma quebra de linha ele volta a posição do vetor para 0,
			// substitui a quebra de linha da string por um '\0' ou seja 'fim da string' e avança
			// para a próxima linha.
			if (c == '\n') {	
				clientes_linha[n][pos-1] = '\0';
				pos = 0;
				n++;
			}
		}

		//Fecha o arquivo, já que a leitura dele já foi efetuada.
		fclose(dados_brutos);
		printf("\n");


		//Dados organizados || n - index pessoa | [4] - número de tipos (ID, NOME, SOBRENOME, SALDO) | [100] tamanho max string	
		char dados_org[n][4][100];

		//Declara as variáveis novas para o array novo dados_org, no qual
		// eu irei inserir os dados novos separados por tipo, por exemplo:
		// dados_org [index cliente] [0 = ID | 1 = NOME | 2 = SOBRENOME | 3 = SALDO]

		int i, tipo, i2;
		for (n = 0; n < tamanho; n++){
			tipo = 0; i2 = 0;
			printf("CLIENTE [%d] | ", n);
			for (i = 0; clientes_linha[n][i] != '\0'; i++) {
				
				printf("%c", clientes_linha[n][i]);
				
				// Quando eu tiro esses comentários o programa dá um erro no qual ou
				// printa tudo errado ou dá um segmentation fault

				if (clientes_linha[n][i] != ' ') {
					dados_org[n][tipo][i2] = clientes_linha[n][i];
					i2++;
				} else {
					dados_org[n][tipo][i2] = '\0';
					tipo++;
					i2 = 0;
				}

				if (clientes_linha[n][i+1] == '\0')
					printf("\n-------------------------------------------\n");	
			}
		}
		printf("\n");

		n = 9; tipo = 1;
		printf("%s\n", clientes_linha[n]);
		printf("dados_org[%d][%d] - %s\n", n, tipo, dados_org[n][tipo]);
	}
	return 0;
}