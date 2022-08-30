#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	pid_t pid, pid1;
	// cria 2 processos, sendo 1 pai e seu respectivo filho
	pid = fork();

	// O identificador gerado para o pai será sempre maior que 0
	if(pid < 0){
		// stderr é um ponteiro que caso não seja alterado, vai levar para um lugar padrão (terminal)
		fprintf(stderr, "Fork failed");
		// Retorno 1 porque o sistema deu erro
		return 1;
	} // O processo filho terá o pid 0
	else if(pid == 0){
		pid1 = getpid(); //getpid irá pegar o id do processo, nesse caso ele pega o id do processo filho
		printf("Child pid %d\n", pid);
		printf("Child pid1 %d\n", pid1);
	}
	else{
		pid1 = getpid(); //Processo pai
		printf("Parent pid %d\n", pid);
		printf("Parent pid1 %d\n", pid1);
		wait(NULL);
	}

	return 0;
}