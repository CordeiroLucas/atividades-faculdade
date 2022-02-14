#include <stdio.h>

int main (void)
{
	const double PI = 3.14159;
	double n, r, a;

	scanf(" %lf", &r);

	a = PI * (r*r);

	printf("A=%.4lf\n", a);

	return 0;
}