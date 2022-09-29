#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 80 /* 80 chars per line, per command */

void trata_linha(char *line, char **args);
void execute_seq(char *token, char **args);
void execute_par(char *token, char **args);

int main(int argc, char *argv[])
{

     if (argc == 1) {    
          char line[MAX_LINE]; // Linha 
          char *token; // Token de cada comando, dividido por ;
          char *args[MAX_LINE / 2 - 1]; //Max de argumentos na linha
          int should_run = 1, style_par = 0; // Variáveis para controlar o fluxo do shell
          char history[MAX_LINE], temp[MAX_LINE];

          while (should_run)
          {
               printf("\n");
               printf("lcp2 seq> ");
               
               fgets(line, MAX_LINE, stdin); // Entrada de usuário de no máx 80 carácteres
               strcpy(temp, line); // Copia a entrada em uma variável temporária
               printf("\n");
               
          
               token = strtok(line, ";"); // Divide a linha em tokens separados por ";"
               trata_linha(line, args); // Trata a linha


               if (strcmp(args[0], "style") == 0 && strcmp(args[1], "parallel") == 0) // Se usuário digita style parallel
                    style_par = 1;

               while (style_par) { // Entra função loop paralelo
                    printf("\n");  
                    printf("lcp2 par> ");
                    fgets(line, MAX_LINE, stdin); 
                    strcpy(temp, line); // Copia entrada do usuário para variável temporária
                    printf("\n");

                    token = strtok(line, ";"); // Pega apenas a string do comando sem o ";"
                    trata_linha(line, args);  // Adiciona alguns \0 para separar os comandos

                    if (strcmp(args[0], "style") == 0 && strcmp(args[1], "sequential") == 0) { // Se foi digitado style parallel ele muda a style_par 
                         style_par = 0;                                                        // para 0 e volta para o loop principal
                         break;
                    } 
                    
                    if (strcmp(args[0], "exit") == 0) { // Se digitado o Exit, finaliza o programa
                         exit(0);
                    } 
                    
                    if (strcmp(args[0], "!!") == 0) { // Condição para entrar na função de history
                         token = strtok(history, ";");
                         
                         trata_linha(history, args);
                         execute_par(token, args); // Executa a função executar em paralelo
                    } else 
                         strcpy(history, temp); execute_par(token, args); // Se não entrou nas outras funções, então o comando inserido é para executar o shell,
               }                                                          //    então o programa salva a variável temporária em histórico para ser utilizada posteriormente

               if (strcmp(args[0], "exit") == 0) // Se digitado o Exit, finaliza o programa
                    exit(0);

               else if (strcmp(args[0], "!!") == 0) {  //history
                    token = strtok(history, ";");

                    trata_linha(history, args);
                    execute_seq(token, args);
               }


               strcpy(history, temp); // Se não entrou nas outras funções, então o comando inserido é para executar o shell,
                                      //    então o programa salva a variável temporária em histórico para ser utilizada posteriormente
               execute_seq(token, args);
               // printf("%s\n", token);
          }
          return 0;
     } else {
          printf("Bash\n");
     }
}

void trata_linha(char *line, char **args) //divide a linha em argumentos
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
     while (token != NULL) // Em quanto o token for diferente de Nulo
     {
          trata_linha(token, args); // Formata a linha em argumentos

          pid = fork(); //faz o fork para executar a função
          if (pid < 0) //se menor que 0 é porque houve erro na criação de filho
          {
               printf("Fork failed\n");
               exit(0);
          }
          else if (pid == 0) // se igual a zero é porque é igual ao filho
          {
               execvp(*args, args); //executa comando
               exit(0);
          }
          else // Caso contrário o pai vai esperar o filho criado terminar logo em seguida
          {
               wait(NULL); // Pai vai esperar o filho terminar a execução para seguir o loop
               token = strtok(NULL, ";"); // Segue para o próximo token
          }
     }
}

void execute_par(char *token, char **args)
{
     pid_t pid;
     int filhos = 0; //contador de filhos gerados
     while (token != NULL)
     {
          trata_linha(token, args);

          pid = fork();
          filhos++; //incrementa o contador ao criar filhos
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
               token = strtok(NULL, ";"); // Segue para o próximo token
          }
     }
     // Filhos são criados e executam os comandos no primeiro loop

     for (int i = 0; i < filhos; i++)
     {
          wait(NULL); // Só após o último filho ser criado, que os pais vão começar a
                         // esperarem pelos processos filhos finalizarem
     }
}
