#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int queue_array[MAX];
int rear = - 1;
int front = - 1;
int top=-1;
int stack[MAX];
struct node
{
	int value;
	struct node*ptr;
	
};

struct node * insertatfront(struct node*h,int val)
{
	struct node * newnode;
	newnode=(struct node *) malloc (sizeof(struct node));
	newnode->value=val;
		newnode->ptr=h;
		h=newnode;
	return h;
	
}
struct node * display(struct node*h)
{
	struct node * temp;
	temp=h;
	while(temp!=NULL)
	{	printf("%d ",temp->value);
		temp=temp->ptr;
	}
	printf("\n");
	
}

int pop()
{
    if(top==-1)
    {
        printf("\nStack is empty!!");
    }
    else
    {	
        printf("\nThe last sold car was  %d \n",stack[top]);
        top=top-1;
    }
}

void push(int val)
{
    
    
    if(top==MAX-1)
    {
        printf("\nStack is full!!\n");
    }
    else
    {
     
        top=top+1;
        stack[top]=val;
    }
}

void book()
{	int add_item;
	if (front == - 1)
         
            front = 0;
        printf("Inset the element in queue : ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
}

int queue()
{	int book;
    if (front == - 1 || front > rear)
    {
        printf("Queue Empty!!! \n");
        return 0;
    }
    else
    {	
    	book=queue_array[front];
        printf("Prcessed car no. is : %d\n", book);
        front = front + 1;
    }
    return book;
} 

struct node * deleteatpos(struct node*h,int val)
{	struct node * nodetobedeleted;
	struct node * temp;
	temp=h;
	while(temp->ptr!=NULL && (temp->ptr)->value!=val)
	{
		temp=temp->ptr;
	}
	if(temp->ptr==NULL)
	{
		printf("Car not found\n");
		return h;
		
	}
	else
	{
		nodetobedeleted=temp->ptr;
		temp->ptr=(temp->ptr)->ptr;
		free(nodetobedeleted);
	}
	return h;
}

void process(struct node*h)
{	int status;
	
		status=queue();
		push(status);
		deleteatpos(h,status);	
	
}



int main()
{
	struct node*H;
	H=NULL;
	
	H=insertatfront(H,5);
	H=insertatfront(H,4);
	H=insertatfront(H,3);
	H=insertatfront(H,2);
	H=insertatfront(H,1);
	printf("Cars list -: \n 1.Honda \n 2.Marutri \n 3.Audi \n 4.Tesla \n 5.Hundai \n");
    	int choice;
    	while (choice!=4)
    {
        printf("1.Book a car\n");
        printf("2.Process Bookings\n");
        printf("3.Last Sold car \n");
        printf("4.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            	book();
                break;
            case 2:
            	process(H);
           	
                break;
            case 3:
            	pop();
                break;
            case 4:
            	
                break;
            
            default:
                printf("Wrong choice \n");
        }
     }

   
}
