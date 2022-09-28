#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void trata_linha(char *line, char **argv);
void execute_seq(char *token, char **args);
void execute_par(char *token, char **args);

int main(void)
{
   char str[80];
   char *token;
   char *args[41];
   int should_run = 1, style_par = 0;

   int n;
   while (should_run)
   {
      int n = 0;

      printf("lcp2 seq> ");
      gets(str, 80);

      token = strtok(str, ";");
      trata_linha(str, args);

      if (strcmp(args[0], "style") == 0 && strcmp(args[1], "parallel") == 0)
         style_par = 1;

      else if (strcmp(args[0], "exit") == 0)
         exit(0);

      while (style_par)
      {
         printf("lcp2 par> ");
         gets(str, 80);

         token = strtok(str, ";");
         trata_linha(str, args);

         if (strcmp(args[0], "style") == 0 && strcmp(args[1], "sequential") == 0)
         {
            style_par = 0;
            break;
         }

         execute_par(token, args);
      }

      execute_seq(token, args);
      // printf("%s\n", token);
   }
   return 0;
}

void trata_linha(char *line, char **argv)
{
   while (*line != '\0')
   { /* Se diferente do fim da linha */
      while (*line == ' ' || *line == '\t' || *line == '\n')
         *line++ = '\0'; /* Substitui espaços em branco por NULL */

      *argv++ = line; /* Guarda a posição do argumento     */

      while (*line != '\0' && *line != ' ' &&
             *line != '\t' && *line != '\n')
         line++; /* Pula o argumento até caracter de espaço, ou fim da linha    */
   }

   *argv = '\0'; /* Coloca o final do argumento  */
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