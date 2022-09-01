#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	pid_t pid, pid1;
	pid = fork();

	// O identificador gerado para o pai será sempre maior que 0
	if(pid < 0){
		fprintf(stderr, "Fork failed");
		return 1;
	}

	printf("PID %d\n", pid);
	
	if (pid != 0) {
		wait(NULL);
	}

	return 0;
}