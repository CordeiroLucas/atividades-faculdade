#include <stdio.h>

int main()
{

	float nota1, nota2, nota3, nota4, exame, media;
	float peso1 = 2, peso2 = 3, peso3 = 4, peso4 = 1;

	scanf(" %f %f %f %f", &nota1, &nota2, &nota3, &nota4);

	media = ((nota1 * peso1) + (nota2 * peso2) + (nota3 * peso3) + (nota4 * peso4)) / (peso1 + peso2 + peso3 + peso4);

	printf("Media: %.1f\n", media);

	if (media < 7)
	{
		if (media >= 5)
		{
			printf("Aluno em exame.\n");

			scanf(" %f", &exame);

			printf("Nota do exame: %.1f\n", exame);

			if (((exame + media) / 2) < 5)
				printf("Aluno reprovado.\n");
			else 
				printf("Aluno aprovado.\nMedia final: %.1f\n", (media + exame)/2);
		} else 
			printf("Aluno reprovado.\n");
	} else
		printf("Aluno aprovado.\n");

	return 0;
}