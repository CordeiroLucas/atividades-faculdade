#include <stdio.h>
#include <stdlib.h>
 
double fazer_media(double nota1, double peso1, double nota2, double peso2, double nota3, double peso3)
{
    return (((nota1*peso1)+(nota2*peso2)+(nota3*peso3)) / (peso1+peso2+peso3));
}
 
int main(void) {
 
    double a, b, c, med;
    
    scanf(" %lf %lf %lf", &a, &b, &c);
    
    med = fazer_media(a, 2, b, 3, c, 5);
    
    printf("MEDIA = %.1lf\n", med);
 
    return 0;
}