#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>

#define MAX_LINE 80 /* 80 chars per line, per command */

void trata_linha(char *line, char **args);
void execute_seq(char *token, char **args);
void execute_par(char *token, char **args);

int main(int argc, char *argv[])
{
     if (argc == 1) {    
          char line[MAX_LINE]; // Linha 
          char *token, *next; // Token de cada comando, dividido por ;
          char *args[MAX_LINE / 2 + 1]; //Max de argumentos na linha
          int should_run = 1, style_par = 0; // Variáveis para controlar o fluxo do shell
          char history[MAX_LINE], temp[MAX_LINE];
          

          while (should_run)
          {
               printf("lcp2 seq> ");
               gets(line, MAX_LINE); //Recebe Linha com no máximo 80 caracteres
               strcpy(temp, line); // Copia a linha para uma variável temporária

               token = strtok(line, ";");
               trata_linha(line, args); // Função trata linha que tira os espaços em branco 
               
               if (strcmp(args[0], "!!") == 0) {
                    token = strtok(history, ";");
                    
                    trata_linha(history, args);

                    if (strcmp(args[0], "style") != 0) {
                         execute_par(token, args);
                         continue;     
                    } else {
                         printf("style %s\n", args[1]);
                    }
               } 

               if (strcmp(args[0], "style") == 0 && strcmp(args[1], "parallel") == 0) // Se usuário digita style parallel
                    style_par = 1; strcpy(history, temp);

               while (style_par) { 
                    printf("lcp2 par> ");
                    gets(line, MAX_LINE);
                    strcpy(temp, line);

                    token = strtok(line, ";");
                    trata_linha(line, args);

                    if (strcmp(args[0], "!!") == 0) {
                         token = strtok(history, ";");
                         
                         trata_linha(history, args);

                         if (strcmp(args[0], "style") != 0) {
                              execute_par(token, args);
                         } else {
                              printf("style %s\n", args[1]);
                         }
                    }

                    if (strcmp(args[0], "exit") == 0) {
                         exit(0);
                    } 
                    
                    if (strcmp(args[0], "style") == 0 && strcmp(args[1], "sequential") == 0) {
                         style_par = 0;
                         strcpy(history, temp);
                         break;
                    } else 
                         strcpy(history, temp); execute_par(token, args);        
               }

               if (strcmp(args[0], "exit") == 0) // Se usuário digita exit
                    exit(0);

               strcpy(history, temp);
               execute_seq(token, args);
               // printf("%s\n", token);
          }
          
          return 0;
     } else {
          printf("OPA PARECE QUE TEMOS UMA ENTRADA BASH AQUI N É MEIIXMO!?!?!\n");
     }
}

void trata_linha(char *line, char **args)
{
     int i = 0;
     while (*line != '\0')
     { /* Se diferente do fim da linha */
          while (*line == ' ' || *line == '\t' || *line == '\n')
               *line++ = 0; /* Substitui espaços em branco por NULL */

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
