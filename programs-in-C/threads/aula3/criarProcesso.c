#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	// pid_t é o mesmo que um inteiro, porém por padrão é recomendado o uso desse tipo "Identificador de Processo" ou 
	// "Process Identification"
	pid_t pid;
	int i;

	//Exemplo para criar i processos filhos e i pais
	for (i=0;i < 2; i++){
		// Ao fazer essa chamada "fork" ele cria um processo filho e atribui um pid "identificador" 
		// diferente para cada processo, sendo o valor do pid do processo filho é igual a 0 e o do pai será o filho 
		//Exemplo -> pid fork() cria um processo "pai" com pid = filho e também um processo "filho" com pid = 0

		// A partir dessa intrução, tudo abaixo dela será executado pelos processos criados
		pid = fork();
	}

	//O processo vai printar o seu identificador, sendo os processos filho igual a 0
	printf("PID %d\n", pid);

	// Se pid for diferente de 0 significa que o processo é um processo pai
	if (pid != 0) {
		wait(NULL);
	}

	return 0;
}