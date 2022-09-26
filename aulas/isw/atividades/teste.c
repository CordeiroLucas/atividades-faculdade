#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void  trata_linha(char *line, char **argv);

int main (void) {
   char str[80] = "ls ; pwd";
   const char s[] = ";";
   char *token;
   char *args[41];

   token = strtok(str, s);

   trata_linha(token, args);
   

   pid_t pid, pid2;

   while(token != NULL) {
      printf("%s", token);
      pid = fork();
      token = strtok(NULL, s);
   }

   if (pid < 0) {
      printf("Fork failed\n");
      exit(0);
   } else if (pid == 0) {
      printf("Child one:\n");
      execvp(args[0], args);
      printf("alo");
      exit(0);
   } else {
      printf("Parent One:\n");
      wait(NULL);
      printf("cabo\n");
      while (token != NULL) {
         token = strtok(str, s);
         pid2 = fork();
      }
      exit(0);
   }

   

   // printf("%s\n", token);

   return 0;
}

void  trata_linha(char *line, char **argv)
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
