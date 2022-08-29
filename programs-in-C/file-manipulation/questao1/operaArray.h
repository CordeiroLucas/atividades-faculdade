/*Retorna um array de int | Inverso do array do usuário*/
void newReverse (int tamanho, int array[tamanho], FILE *arquivo)
{
	int reverseArray[tamanho], m, n;
	char saida[tamanho];

	printf("\n-NewReverse-\n");

	for (m = 0, n = (tamanho-1); m < tamanho, n >= 0; m++, n--)
		reverseArray[n] = array[m];
	
	printf("[ ");
	for (m = 0; m < tamanho; m++)
		printf("%d ", reverseArray[m]);
	printf("]\n");


	char resposta;
	printf("\n Deseja Salvar o Resultado?\nS - Sim | N - Não\n\n-> ");
	scanf(" %c", &resposta);

	if (resposta == 'S') {

		fprintf(arquivo, "newReverse = [ ");

		for (m = 0; m < tamanho; m++) 
			fprintf(arquivo, "%d ", reverseArray[m]);

		fprintf(arquivo, "]\n");
		
	} else return;

}

/*Retorna um inteiro | Número de vezes que o elemento aparece no array*/
void elemNum (int tamanho, int array[tamanho], FILE *arquivo)
{
	int elemento, m, total = 0;

	printf("\n-ElemNum-\nElemento -> ");
	scanf(" %d", &elemento);

	for (m = 0; m < tamanho; m++) 
		if (array[m] == elemento)
			total++;
	
	printf("\nO número %d apareceu %d vezes!\n", elemento, total);

	char resposta;
	printf("\nDeseja Salvar o Resultado?\nS - Sim | N - Não\n\n-> ");
	scanf(" %c", &resposta);

	if (resposta == 'S') 
		fprintf(arquivo, "O número %d apareceu %d vezes!\n", elemento, total);
	
	else return;	
}

/*Retorna um array de int | Apenas números que aparecem uma vez*/
void unique (int tamanho, int array[tamanho], FILE *arquivo)
{
	int i = 0, m, n, aparicoes, numero;
	int arrayUn[tamanho];
	printf("\n-Unique-\n");

	for (m = 0; m < tamanho; m++) {
		numero = array[m];
		aparicoes = 0;

		for (n = 0; n < tamanho; n++) {
			if (numero == array[n]) {
				aparicoes++;

				if (aparicoes > 1)
					break;
			}
		}

		if (aparicoes == 1) {
			arrayUn[i] = numero;
			i++;
		}
	}

	printf("[ ");
	for (m = 0; m < i; m++) 
		printf("%d ", arrayUn[m]);
	printf("]\n");


	char resposta;
	printf("\nDeseja Salvar o Resultado?\nS - Sim | N - Não\n\n-> ");
	scanf(" %c", &resposta);
	
	if (resposta == 'S') {

		fprintf(arquivo, "unique = [ ");

		for (m = 0; m < i; m++)
			fprintf(arquivo, "%d ", arrayUn[m]);

		fprintf(arquivo, "]\n");
		
	} else return;
}

/*Retorna um array de int | Array antigo menos o valor no index escolhido*/
void deleteN (int tamanho, int array[tamanho], FILE *arquivo)
{
	int elemento, m, i = 0;
	int arrayDelet[tamanho];

	printf("\n-DeleteN-\nEnésimo elemento -> ");
	scanf(" %d", &elemento);

	for (m = 0; m < tamanho; m++) {
		if (elemento == m+1) 
			continue;
		else {
			arrayDelet[i] = array[m];
			i++;
		}
	}

	printf("\nnewArray -> [ ");
	for (m = 0; m < i; m++) 
		printf("%d ", arrayDelet[m]);
	printf("]\n");

	char resposta;
	printf("\nDeseja Salvar o Resultado?\nS - Sim | N - Não\n\n-> ");
	scanf(" %c", &resposta);
	
	if (resposta == 'S') {

		fprintf(arquivo, "deleteN %d = [ ", elemento);

		for (m = 0; m < i; m++)
			fprintf(arquivo, "%d ", arrayDelet[m]);

		fprintf(arquivo, "]\n");
		
	} else return;
}

