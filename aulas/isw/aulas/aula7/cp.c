#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

sem_t empty; //Semáforo 
sem_t full; //Semáforo

pthread_mutex_t mutex; //Estrutura com as informações dos semáforos

int in = 0; // Indica a posição que vai inserir o elemento
int out = 0; // Indica a posição que vai retirar o elemento

int * buffer; //

void * producer(void *pdo); 
void * consumer(void *con); //con = nome da variável que vai conter o nome do produtor

int B, C, P, N; //B -> Tamanho do Buffer, N Limite do produtor

int main()
{
	printf("Insira P, C, B, N respectinvamente:\n");
	scanf("%d %d %d %d, &P, &C, &B, &N");

	pthread_t * pro = (pthread_t*)malloc(sizeof(pthread_t)*P); // é o array que vai conter os nomes do produtores 
	pthread_t * con =(pthread_t*)malloc(sizeof(pthread_t)*C); 
	buffer = (int*)malloc(sizeof(int)*B);

	pthread_mutex_init(&mutex,NULL);
	sem_init(&empty, 0, 0);
	sem_init(&full, 0, B);

	int size = P > C ? P:C; //Se P maior que C, size = P, caso contrário, size = C
	int *index = (int *)malloc(sizeof(int)*size);

	for(int i = 0;i < P; i++) {
		pthread_create(&pro[i], NULL, producer, index[i]);
	}

	for(int i = 0; i < C; i ++) {
		pthread_create(&con[i], NULL, consumer, &index[i]);
	}

	for(int i = 0; i < P; i++) {
		pthread_join(pro[i], NULL);
	}

	for(int i = 0; i < C; i++) {
		pthread_join(con[i], NULL);
	}

	free(pro);
	free(con);
	free(buffer);

	return 0;
}


void *producer(void *pno)
{
	int *id = pno;
	int input;
	while(1){
		for(int i = 0; i <= N; i++){
			input = 2*i+1;
			sem_wait(&full);
			pthread_mutex_lock(&mutex);
			buffer[in];
			printf("Producer %d Input %d Index %d",
				*id, input, in);
			in = (in+1)%B;
			pthread_mutex_unlock(&mutex);
			sem_post(&empty);
		}
	}
}

void *consumer(void *cno)
{
	int *id = cno;
	int output;
	while(1){
		sem_wait(&empty);
		pthread_mutex_lock(&mutex);
		output = buffer[out];
		printf("Consumer %d Output %d Index %d", *id, output, out);
		out = (out+1)%B;
		pthread_mutex_unlock(&mutex);
		sem_post(&full);
	}
}
