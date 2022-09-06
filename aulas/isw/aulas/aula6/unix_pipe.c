#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(void)
{
	char write_mesg[] = "hello pipe";
	char read_mesg[BUFFER_SIZE];

	pid_t pid;
	int fd[2];

	if(pipe(fd)){
		fprintf(stderr, "Pipe failed\n");
		return 1;
	}

	pid = fork();
	if(pid < 0){
		fprintf(stderr, "Fork failed");
		return 1;
	}

	if(pid > 0){
		close(fd[READ_END]);
		write(fd[WRITE_END], write_mesg, strlen(write_mesg)+1);
		close(fd[WRITE_END]);
	} else {
		close(fd[WRITE_END]);
		read(fd[READ_END], read_mesg, BUFFER_SIZE);
		printf("child read %s\n", read_mesg);
		close(fd[READ_END]);
	}
	return 0;
}
