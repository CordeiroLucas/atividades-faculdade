#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void  trata_linha(char *line, char **argv);

int main (void) {
   char str[80];
   const char s[] = ";";
   char *token;
   char *args[41];
   char *history[80];
   
   history[0] = NULL;

   pid_t pid;

   int n;
   while (1) {
      int n = 0;
      gets(str, 80);
      if (strcmp(str, "history") == 0) {
         if (history[0] != NULL) {
            printf("1");
            for(n=0;history[n]!=NULL;n++) {
               printf("%s \n", *history);
            }
         }else {
            printf("No history!\n");
         }

      } else if (str != ' ' && str != '\0' && str != '\n') {
         token = strtok(str, s);
   
         while (token != NULL) {
            trata_linha(token, args);
            
            pid = fork();
            if (pid < 0) {
               printf("Fork failed\n");
               exit(0);
            } else if (pid == 0) {   
               history[i] = args;       
               execvp(*args, args);
               exit(0);
            } else {
               wait(NULL);
               token = strtok(NULL, s);
            }
         }
      } else {
         printf("Invalid Key\n");
         exit(0);
      }      
   }
   
   // printf("%s\n", token);

   return 0;
}

void  trata_linha(char *line, char **argv)
{
     while (*line != '\0') {       /* Se diferente do fim da linha */ 
          while (*line == ' ' || *line == '\t' || *line == '\n')
               *line = '\0';     /* Substitui espaços em branco por NULL */
               
          *argv++ = line;        /* Guarda a posição do argumento     */
         
          while (*line != '\0' && *line != ' ' && 
                 *line != '\t' && *line != '\n') 
               line++; history[i]             /* Pula o argumento até caracter de espaço, ou fim da linha    */
     }

     *argv = '\0';                 /* Coloca o final do argumento  */
}
