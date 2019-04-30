
#include <stdio.h>
#include <ctype.h>
char stack[20];
char stack2[20];
int top2 = -1;
int top = -1;
void push(char x);
char pop();
int priority(char ch);
void pushx(int x);
int popx();
int main2(char exp[]);
int main()
{
    char arr[20];
    char cache[20];
    int c = 0;
    char *p, x;
    printf("Enter the expression :: ");
    scanf("%s",arr);
    p = arr;
    while(*p != '\0')
    {
        if(isalnum(*p))
            { printf("%c",*p); cache[c++] = *p;}
		
        else if(*p == '(')
            { push(*p); cache[c++] = *p;}
        else if(*p == ')')
        {
            while((x = pop()) != '(')
               { printf("%c", x); cache[c++] = *p;}
        }
        else
        {
            while(priority(stack[top]) >= priority(*p))
               { printf("%c",pop()); cache[c++] = *p; }
            push(*p);
        }
        p++;
    }
    while(top != -1)
    {
        printf("%c",pop()); cache[c++] = *p;
    }
printf(" %s",cache);
main2(cache);
}

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











void pushx(int x)
{
        stack2[++top2] = x;
}
 
int popx()
{
        return stack2[top2--];
}

int main2(char exp[])
{
        char *e;
        int n1,n2,n3,num;
        e = exp;
        while(*e != '\0')
        {
                if(isdigit(*e))
                {
                        num = *e - 48;
                        pushx(num);
                }
                else
                {
                        n1 = pop();
                        n2 = pop();
                        switch(*e)
                        {
                                case '+':
                                {
                                        n3 = n1 + n2;
                    break;
                                }
                                case '-':
                                {
                                        n3 = n2 - n1;
                                        break;
                                }
                                case '*':
                                {
                                        n3 = n1 * n2;
                                        break;
                                }
                                case '/':
                                {
                                        n3 = n2 / n1;
                                        break;
                                }
				case '%':
				{
					n3 = (float)((int)n2%(int)n1);
					break;
				}
                        }
                        pushx(n3);
                }
                e++;
        }
        printf("\nThe result of expression %s  =  %d\n\n",exp,popx());
        return 0;
 
}
 

