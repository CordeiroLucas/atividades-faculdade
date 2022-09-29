#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void trata_linha(char *line);

int main(void)
{
	char str[80] = "   bondia ; manooo; do ceu";
	char *args[41];

	trata_linha(str);

	printf("%s", str);


	
	return 0;
}

void trata_linha(char *line)
{
     int i = 0, j = 0;
     char args_temp[strlen(line)];

     for (i = 0; i < strlen(line); i++) {
          if (line[i] != ' ' && line[i] != '\n' && line[i] != '\t') {
               args_temp[i] = line[i];
	       j++;
          }
     }
     strcpy(line, args_temp);
     
}
