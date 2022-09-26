#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void  trata_linha(char *line, char **argv);

int main (void) {
   char str[80] = " ls; pwd; ls -l";
   const char s[] = "; ";
   char *token;
   char *args[41];


   pid_t pid, pid2;
   token = strtok(str, s);

   while (token != NULL) {
      

      trata_linha(token, args);

      pid = fork();


      if (pid < 0) {
         printf("Fork failed\n");
         exit(0);
      } else if (pid == 0) {
         execvp(*args, args);
         exit(0);
      } else {
         wait(NULL);
         token = strtok(NULL, s);
      }

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
