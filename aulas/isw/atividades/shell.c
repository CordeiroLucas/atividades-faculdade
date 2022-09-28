#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>

#define MAX_LINE 80 /* 80 chars per line, per command */

void trata_linha(char *line, char **args);
void execute_seq(char *token, char **args);
void execute_par(char *token, char **args);

int main(void)
{
     char line[MAX_LINE];
     char *token;
     char *args[MAX_LINE / 2 - 1];
     int should_run = 1, style_par = 0;

     int n;
     while (should_run)
     {
          int n = 0;

          printf("lcp2 seq> ");
          gets(line, MAX_LINE);

          token = strtok(line, ";");
          trata_linha(line, args);

          if (strcmp(args[0], "style") == 0 && strcmp(args[1], "parallel") == 0) // Se usuário digita style parallel
               style_par = 1;

          while (style_par)
          {
               printf("lcp2 par> ");
               gets(line, 80);

               token = strtok(line, ";");
               trata_linha(line, args);

               if (strcmp(args[0], "style") == 0 && strcmp(args[1], "sequential") == 0)
               {
                    style_par = 0;
                    break;
               }
               else if (strcmp(args[0], "exit") == 0)
               {
                    exit(0);
               } else execute_par(token, args);
          }

          if (strcmp(args[0], "exit") == 0) // Se usuário digita exit
               exit(0);

          execute_seq(token, args);
          // printf("%s\n", token);
     }
     return 0;
}

void trata_linha(char *line, char **args)
{
     while (*line != '\0')
     { /* Se diferente do fim da linha */
          while (*line == ' ' || *line == '\t' || *line == '\n')
               *line++ = '\0'; /* Substitui espaços em branco por NULL */

          *args++ = line; /* Guarda a posição do argumento     */

          while (*line != '\0' && *line != ' ' &&
                 *line != '\t' && *line != '\n')
               line++; /* Pula o argumento até caracter de espaço, ou fim da linha    */
     }

     *args = '\0'; /* Coloca o final do argumento  */
}

void execute_seq(char *token, char **args)
{
     pid_t pid;
     while (token != NULL)
     {
          trata_linha(token, args);

          pid = fork();
          if (pid < 0)
          {
               printf("Fork failed\n");
               exit(0);
          }
          else if (pid == 0)
          {
               execvp(*args, args);
               exit(0);
          }
          else
          {
               wait(NULL);
               token = strtok(NULL, ";");
          }
     }
}

void execute_par(char *token, char **args)
{
     pid_t pid;
     int filhos = 0;
     while (token != NULL)
     {
          trata_linha(token, args);

          pid = fork();
          filhos++;
          if (pid < 0)
          {
               printf("Fork failed\n");
               exit(0);
          }
          else if (pid == 0)
          {
               execvp(*args, args);
               exit(0);
          }
          else
          {
               token = strtok(NULL, ";");
          }
     }

     for (int i = 0; i < filhos; i++)
     {
          wait(NULL);
     }
}