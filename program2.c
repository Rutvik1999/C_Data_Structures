#include<stdio.h>
#include<stdlib.h>
int main()
{
	float x, y;
	printf("Enter number to be divided \n");
	scanf(" %f",&x);
	printf("Enter divisor \n");
	scanf(" %f",&y);
	if(y == 0)
		{ 
		printf("Division by zero is not possible \n");
		exit(-1);
		}			
	printf("Division product is %f \n", (x/y) );
	return 0;
}
