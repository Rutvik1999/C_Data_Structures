#include <stdio.h>
#include <stdlib.h>
int option,n;
	int top = -1;
int push(int arr[] )
{
	int item;
	if(top >= (n-1))
		{ perror("\n OVERFLOW !! "); printf("\n Cannot enter more elements ::\n "); }
	else
	{ 
		printf("\n Enter item (integer) to push : ");
		scanf(" %d",&item);	
		top++;
		arr[top] = item;
		
	}
return 0;	
}
int pop(int arr[])
{
	if(top < 0)
	{ perror("\n UNDERFLOW !! "); printf("\n Stack is empty ::\n "); }
	else
	{
		top--;
	}
return 0;
}
void display(int arr[])
{
	int i;
	for(i = top; i >= 0 ; i-- )
	{
		printf("\n %d \n",arr[i]);
	}
}
int main()
{
		
	int arr[5];
	n = 5;
	pos:
	printf("Select option \n");
	printf("1. PUSH in stack \n2. POP in stack \n3. DISPLAY stack \n4. EXIT \n");
	scanf(" %d",&option);
	
	switch(option)
	{
		case 1 :
		push(arr);
		break;
		
		case 2 :
		pop(arr);
		break;

		case 3 :
		display(arr);
		break;

		case 4 :
		exit(-1);
		break;

		default :
		perror("Error : Invalid input \n EXIT NOW \n");
		exit(-1); 
		
	}
		goto pos;
		return 0;
}

