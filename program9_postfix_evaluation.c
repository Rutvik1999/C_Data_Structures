#include <ctype.h>
#include <stdio.h>
#define max 10
float stack[max];
int top = -1;
void push(float stack[], float val)
{
 	if (top == (max-1))
		perror("\n Overflow \n");
	else stack[++top] = val;
}
int pop(float stack[])
{
	if(top == -1)
		perror("\n Underflow \n");
	else { return stack[top] ; top--; }
}
int evaluate(char arr[])
{
	int i = 0;
	float n1, n2, val;
	while(arr[i] != '\0')
	{
		if(isdigit(arr[i]))
			push(stack,(float)(arr[i]-48));
		else
			{
				n2 = pop(stack);
				n1 = pop(stack);
				switch(arr[i])
                        	{
                                case '+':
                                {
                                        val = n1 + n2;
                   			break;
                                }
                                case '-':
                                {
                                        val = n2 - n1;
                                        break;
                                }
                                case '*':
                                {
                                        val = n1 * n2;
                                        break;
                                }
                                case '/':
                                {
                                        val = n2 / n1;
                                        break;
                                }
                     				case '%':
                     				{
                        					val = (float)((int)n2%(int)n1);
                        					break;
                     				}

                        	}
			}
		push(stack,val);
	}
	printf("\nThe result of expression %s  =  %d\n\n",arr,pop(stack));
        return 0;
}
 int main()
{
	char arr[max];
	printf("Enter string in postfix form : \n");
	scanf(" %s",arr);
   printf("\n %s", arr);
	evaluate(arr);
	return 0;

}
