#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE 80


int main(int argc, char file[25])
{
  char *programName = "ls; pwd";

  char *args2[] = strtok(programName, ";");

  printf(("%s", args2[0]));

//   char *args[] = {programName, NULL};
 
//   execvp(programName, args);
 
  return 0;
}
