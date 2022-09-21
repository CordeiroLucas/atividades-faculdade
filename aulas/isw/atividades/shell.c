#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 80 /* 80 chars per line, per command */

int main(void)
{
	char* args[MAX_LINE/2 + 1];	/* command line has max of 40 arguments */
	int should_run = 1;		/* flag to help exit program*/
	pid_t pid;
		
	while (should_run) {

		printf("lcp2 seq> ");
		fflush(stdout);

		/*
		After read the input, the next steps are:
		- create n child process with fork() command
		- the child process will invoke execvp()
		- parent will invoke wait() unless command line include &	 
		*/

		fgets(args, MAX_LINE/2 + 1, stdin);

		pid = fork();

		if (pid < 0) {
			fprintf(stderr, "Fork failed\n");
			return 1;
		} 
		else if (pid == 0) {

			
		}

		if (strcmp(args, "exit\n") == 0) exit(0);

		printf("%s", args);
	}
		return 0;
}