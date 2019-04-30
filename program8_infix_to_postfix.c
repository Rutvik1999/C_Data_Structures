
#include <stdio.h>
#include <ctype.h>
char stack[20];
int top = -1;
void push(char x)
{
	stack[++top] = x;

}
char pop()
{
	if(top == -1)
		return -1;

	else return stack[top--];
}

int priority(char ch)
{
	if( ch == '(')
		{
		return 0;
		}
	else if( (ch == '+') || (ch == '-') )
		{
		return 1;
		}
	else if( (ch == '*') || (ch == '/') || (ch == '%') )
		{
		return 2;
		}

}
int main()
{
    char arr[20];
    char *p, x;
    printf("Enter the expression :: ");
    scanf(" %s",arr);
    p = arr;
    while(*p != '\0')
    {
        if(isalnum(*p))
            printf("%c",*p);
        else if(*p == '(')
            push(*p);
        else if(*p == ')')
        {
            while((x = pop()) != '(')
                printf("%c", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(*p))
                printf("%c",pop());
            push(*p);
        }
        p++;
    }
    while(top != -1)
    {
        printf("%c",pop());
    }
    printf(" \n");
}
