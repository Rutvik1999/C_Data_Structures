#include <stdio.h>
int swap(int*,int*);
int main()
{
	int x, y;
	printf("Enter two variables \n");
	scanf(" %d %d",&x,&y);
	printf("\n Variables are : %d and %d \n",x,y);
	swap(&x,&y);
	printf("\n Swapped Variables are : %d and %d \n",x,y);
	return 0;
}

int swap(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
	return 0;
}	 
