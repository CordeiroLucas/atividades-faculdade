#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main () {
   char str[80] = {"ls ; pwd"};
   const char s[4] = " ; ";
   char *token;
   
   /* get the first token */
   token = strtok(str, s);
   
   /* walk through other tokens */
   while( token != NULL ) {
      execvp(str, *token);
      printf("%s\n", token );
    
      token = strtok(NULL, s);
   }

   return(0);
}