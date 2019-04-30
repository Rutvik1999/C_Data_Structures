#include <stdio.h>
#include <math.h>
int main()
{
	double x1,x2,i,integral;
	integral = 0;
	printf("Enter integration (definite) limits of x to integrate x*x \n");
	scanf(" %lf %lf",&x1,&x2);
	for(i = x1 ; i <= x2 ; i = i + ((x1-x2)/100) )
	{
		integral = integral + (i*i/100);
	}
	printf("Integral of sin(x) from %lf to %lf is : %lf", x1, x2, integral);
	return 0;
}
