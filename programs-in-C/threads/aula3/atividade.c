#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main()
{
	pid_t pid;
	int n;

	scanf("%d", &n);
	// cria 2 processos, sendo 1 pai e seu respectivo filho
	pid = fork();

	// O identificador gerado para o pai será sempre maior que 0
	if(pid < 0){
		// stderr é um ponteiro que caso não seja alterado, vai levar para um lugar padrão (terminal)
		fprintf(stderr, "Fork failed");
		// Retorno 1 porque o sistema deu erro
		return 1;
	} // O processo filho irá executar a operação
	else if(pid == 0){
		while(n > 1){
			printf("%d ", n);
			if(n%2) n=3*n+1;
			else n=n/2;
		}
		printf("%d\n", n);
	}
	else{ // Caso seja um processo pai ele vai ficar esperando o processo filho
		wait(NULL);
	}

	return 0;
}