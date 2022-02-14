#include <stdio.h>
#include <string.h>
 
int main() {
    int intVar;
    float floatVar;
    char charVar, stringVar[50];
    
    scanf("%d %f %c ", &intVar, &floatVar, &charVar);

    gets(stringVar);

    printf("\n%d%.6f%c%s\n", intVar, floatVar, charVar, stringVar);
    
    printf("%d        %.6f        %c        %s\n", intVar, floatVar, charVar, stringVar);

    printf("%d          %.6f          %c          %s", intVar, floatVar, charVar, stringVar);
    
    return 0;
}