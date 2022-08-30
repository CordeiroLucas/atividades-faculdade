#include <stdio.h>
#include <stdlib.h>

int main (int argc, char file[25])
{
	int x;
	FILE *arq;

	printf("1\n");
	arq = fopen(file, "r");

	printf("2\n");
	while(!feof(arq)){
		fscanf(arq, "%d", &x);
		printf("%d ", x);
	}
	printf("\n");

	fclose(arq);

	return 0;
}