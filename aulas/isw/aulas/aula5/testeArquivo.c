#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *avg_func(void *);
void *min_func(void *);
void read_file(FILE *file);
double avg;
int min;

typedef struct{ /* Define uma struct para ter mais de uma informação em um único parâmetro*/
	int size;
	int * values;
}datastruct;

int main(int argc, char *argv[]) /*argv é igual aos parâmetros do programa a ser executado*/
{
	if (argc == 1) /*Se igual a 1, significa que ele tem apenas o nome do programa a ser executado*/
	{ 
		printf("No arguments entered\n");
		exit(0);
	}

	int copy[argc - 1]; /*Cria um array com tamanho igual ao do parâmetro, sendo que o primeiro valor é o nome do programa, então ele é
	excluído. */
	for (int i = 0; i < argc - 1; i++) // se for <= ele dá segmentation fault porque ele vai tentar pegar um valor fora do index
		copy[i] = atoi(argv[i+1]);

	datastruct ds = {argc - 1, copy};

	pthread_t thread1, thread2; // Cria uma thread do tipo pthread (tipo com todos os dados e características de uma thread )
	int t1, t2;

	t1 = pthread_create(&thread1,NULL,(void *) avg_func, (void *) &ds);
	if (t1)
	{
		fprintf(stderr, "Erro created thread 1 with code %d\n", t1); //Se houver algum erro na criação da thread, ele irá escrever o 
		// erro no lugar padrão definido pelo stderr (se não for definido ele printa no terminal).
		exit(EXIT_FAILURE);
	}

	t2 = pthread_create(&thread2,NULL,(void *) min_func, (void *) &ds);
	if (t2)
	{
		fprintf(stderr, "Erro created thread 2 with code %d\n", t2); //Se houver algum erro na criação da thread, ele irá escrever o 
		// erro no lugar padrão definido pelo stderr (se não for definido ele printa no terminal).
		exit(EXIT_FAILURE);
	}

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	printf("The average: %g\n", avg);
	printf("The min: %d\n", min);

	exit(EXIT_SUCCESS);
}

void *avg_func(void *str)
{
	datastruct *ds;
	ds = (datastruct *) str; //definindo uma variável que é um ponteiro para o tipo datastruct

	avg = 0;

	int sz = ds->size;
	for(int i = 0; i < sz; i++)
		avg += ds->values[i];
	
	avg = avg/sz;
}

void *min_func(void *str)
{
	datastruct *ds;
	ds = (datastruct *) str;

	min = ds->values[0];
	int sz = ds->size;

	for(int i = 1; i < sz; i++)
		if (min > ds->values[i]) min = ds->values[i];

}

void read_file(FILE *file) 
{

}