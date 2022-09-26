#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>

#define MAX_LINE 80 /* 80 chars per line, per command */

// int main(void)
// {
// 	char* args[MAX_LINE/2 + 1];	/* command line has max of 40 arguments */
// 	int should_run = 1;		/* flag to help exit program*/
// 	pid_t pid;
		
// 	char* argument[] = {"ls", NULL};

// 	while (should_run) {

// 		printf("lcp2 seq> ");
// 		fflush(stdout);

// 		/*
// 		After read the input, the next steps are:
// 		- create n child process with fork() command
// 		- the child process will invoke execvp()
// 		- parent will invoke wait() unless command line include &	 
// 		*/

// 		fgets(args, MAX_LINE/2 + 1, stdin);

// 		if (strcmp(args, "exit\n") == 0) exit(0);
		
// 		// pid = fork();

// 		// if (pid < 0) {
// 		// 	fprintf(stderr, "Fork failed\n");
// 		// 	return 1;
// 		// } 
// 		// else if (pid == 0) {
// 		// 	execvp("ls", PATH)
// 		// } else {
// 		// 	wait(NULL);
// 		// }


		
// 		printf("%s", args);
// 	}
// 		return 0;
// }

void  execute(char **argv);
void  trata_linha0(char *line, char **argv);

void  main(void)
{
     char  line[MAX_LINE];             /* Linha de entrada                 */
     char  *argv[MAX_LINE/2 + 1];      /* argumentos      */

     // if (argc == 1) {
     //      printf("não há argumentos na entrada");
     // } else if (argc > 1) {
     //      printf("há argumentos na entrada\n");
     // }

     while (1) {                  /* repeat until done ....         */
          printf("lcp2> ");     
          gets(line);             
          printf("\n");
          trata_linha0(line, argv);      /*   trata_linha0 the line               */
          if (strcmp(argv[0], "exit") == 0) /* Finaliza programa */
               exit(0);            
          else if (strcmp(argv[0], "style") == 0 && strcmp(argv[1], "sequential") == 0) {
               while(1) {
                    printf("lcp2 seq> ");
                    exit(0);
               }
          } else if (strcmp(argv[0], "style") == 0 && strcmp(argv[1], "parallel") == 0) {
               while (1) {
                    printf("lcp2 par> ");
                    exit(0);
               }
          }

          execute(argv);           /* otherwise, execute the command */
     }
}

void  trata_linha0(char *line, char **argv)
{
     while (*line != '\0') {       /* Se diferente do fim da linha */ 
          while (*line == ' ' || *line == '\t' || *line == '\n')
               *line++ = '\0';     /*  Substitui espaços em branco por NULL */
          *argv++ = line;          /* Guarda a posição do argumento     */
          while (*line != '\0' && *line != ' ' && 
                 *line != '\t' && *line != '\n') 
               line++;             /* Pula o argumento até caracter de espaço, ou fim da linha    */
     }
     *argv = '\0';                 /* Coloca o final do argumento  */
}

void  execute(char **argv)
{
     pid_t	pid;
     int	status;

     if ((pid = fork()) < 0) {     /* Faz um fork para criar um processo filho          */
          printf("Fork failed\n");
          exit(1);
     }
     else if (pid == 0) {          /* Processo filho         */
          if (execvp(*argv, argv) < 0) {     /* execute the command  */
               printf("Exec failed\n");
               exit(1);
          }
     }
     else {                                  /* for the parent:      */
          while (wait(&status) != pid);       /* wait for completion  */
     }
}