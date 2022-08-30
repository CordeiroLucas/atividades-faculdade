#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *avg_func(void *str);
void *min_func(void *str);
double avg;
int min;

typedef struct{//Passa o tamanho e os valores do array!!!!
    int size;
    int * values;
}datastruct;

int main(int argc, char *argv[]){
    //Argc é o count da linha de comando introduzida!!!!!
    if (argc == 1){//Se argc == 1 significa que apenas foi introduzido o nome do programa!
        printf("No arguments entered\n");
        exit(0);
    }

    int copy[argc -1];//Declara o tamanho do array copia como argc-1(para retirar o nome do programa)
    for (int i=0; i < argc - 1; i++){//Esse loop vai pegar os inteiros do array
        copy[i] =  atoi(argv[i+1]);//+1 pq ele exclui o primeiro elemento que é o nome do programa
    }

    datastruct ds =  {argc -1, copy};

    pthread_t thread1,thread2; //Declara thread1 do tipo pthread_t

    int t1,t2;

    t1 = pthread_create(&thread1,NULL,(void *)avg_func,(void *) &ds);//Cria uma thread! O t1 é uma flag q salva o retorno 0 = sucesso  

    if(t1){
        fprintf(stderr, "Erro created thread 1 with code %d\n",t1);//FPRINTF salva o erro no config.log boas praticas ;)
        exit(EXIT_FAILURE); 
    }

    t2 = pthread_create(&thread2,NULL,(void *)min_func, (void *) &ds);

    if(t2){
        fprintf(stderr, "Erro created thread 2 with code %d\n",t2);//FPRINTF salva o erro no config.log boas praticas ;)
        exit(EXIT_FAILURE); 
    }

    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);

    printf("The average: %g\n", avg);
    printf("The min: %d\n", min);

    exit(EXIT_SUCCESS);
}

void *avg_func(void *str){
    datastruct *ds;
    ds = (datastruct *) str;

    avg = 0;

    int sz = ds->size;
    for(int i=0; i<sz;i++){
        avg += ds->values[i];
    }
    avg = avg/sz;
}

void *min_func(void *str)
{
    datastruct *ds;
    ds = (datastruct *) str;

    int sz = ds->size;
    min = ds->values[0];
    
    for(int i=1; i<sz;i++){
        if(min > ds->values[i]){
            min = ds->values[i];
        }
    }
}