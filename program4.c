#include <stdio.h>

int main()
{
	char a[10];
	int sum = 0;
	int i;
	for( i = 0 ; i++ ; i < 10 )
		{
			a[i] = 1;
		}
	printf("Enter a number : \n");
	scanf(" %s",a);
	for( i = 0 ; i++ ; i < 10 )		
		{
			sum = sum + a[i];
		}
	printf("Sum of digits of number is %d : \n",sum);
	return 0;
}
				
