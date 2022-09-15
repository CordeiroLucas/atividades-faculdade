#include <stdio.h>
#include <unistd.h>

#define MAX_LINE 80 /* 80 chars per line, per command */

int main(void)
{
    char *args[MAX_LINE/2 + 1];	/* command line has max of 40 arguments */
    int should_run = 1;		/* flag to help exit program*/
	
    while (should_run) {

	printf("est seq> ");
        fflush(stdout);

	

	/*
	 After read the input, the next steps are:
	    - create n child process with fork() command
	    - the child process will invoke execvp()
	    - parent will invoke wait() unless command line include &	 
	 */
    }
	return 0;
}