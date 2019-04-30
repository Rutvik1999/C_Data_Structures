#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char search[100];
char stack[100];

struct node
{
	char data[100];
	struct node *next;
};

struct queue
{
	struct node *front;
	struct node *rear;
};

struct node *start=NULL;
struct queue *q;
struct node *top=NULL;
struct node *create_ll(struct node *);
struct node *display_ll(struct node *);
struct queue *create_queue(struct queue *);
struct queue *insert_q(struct queue *,char car[]);
struct queue *display_q(struct queue *);
struct queue *delete_q(struct queue *);
struct node *delete_ll(struct node *,char search[]);
struct node *delete_beg(struct node *);
struct node *push(struct node *, char stack[]);
struct node *display_s(struct node *);
void peek(struct node *);

int main()
{
	int ch;
	char order[100];
	q = create_queue(q);
	do
	{
		printf("\n1) Enter Car Names");
		printf("\n2) Show Available Cars");
		printf("\n3) Enter Customer Request");
		printf("\n4) Display Customer Requests");
		printf("\n5) Process Customer Request");
		printf("\n6) Search The Store");
		printf("\n7) Register Delivery");
		printf("\n8) Display All Delivered Cars");
		printf("\n9) Display Last Delivery");
		printf("\n10) Exit");
		printf("\nEnter Your Choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				start=create_ll(start);
			break;
			case 2:
				start=display_ll(start);
			break;
			case 3:
				printf("\nEnter Customer Request: ");

				scanf(" %s",order);
				q=insert_q(q,order);
			break;
			case 4:
				q=display_q(q);
			break;
			case 5:
				q=delete_q(q);
			break;
			case 6:
				start=delete_ll(start,search);
			break;
			case 7:
				top=push(top,stack);
			break;
			case 8:
				top=display_s(top);
			break;
			case 9:
				peek(top);
			break;
		}
	}while(ch!=10);

}

struct node *create_ll(struct node *start)
{
	struct node *new_node, *ptr;
	char name[100];
	printf("\n(press x to finish) \nEnter Car Name: ");

	scanf(" %s",name);
	while(strcmp(name,"x")!=0)
	{
		new_node=(struct node *)malloc(sizeof(struct node));
		strcpy(new_node->data,name);
		if(start==NULL)
		{
			new_node->next=NULL;
			start=new_node;
		}
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=new_node;
			new_node->next=NULL;
		}
		printf("\nEnter Car Name: ");
		scanf(" %s",name);
	}
	return start;
}

struct node *display_ll(struct node *start)
{
	struct node *ptr;
	ptr=start;
	if(start==NULL)
	{
		printf("\nNo Cars Available.\n");
		return NULL;
	}
	else
	{
		while(ptr->next!=NULL)
		{
			printf("%s",ptr->data);
			printf("\n");
			ptr=ptr->next;
		}
		printf("%s\n",ptr->data);
		return start;
	}
}


struct queue *create_queue(struct queue *q)
{
	q = (struct queue*)malloc(sizeof(struct queue));
	q->rear=NULL;
	q->front=NULL;
	return q;
}

struct queue *insert_q(struct queue *q,char car[])
{
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	strcpy(ptr->data,car);
	if(q->front==NULL)
	{
		q->front=ptr;
		q->rear=ptr;
		q->front->next=q->rear->next=NULL;
	}
	else
	{
		q->rear->next=ptr;
		q->rear=ptr;
		q->rear->next=NULL;
	}
	return q;
}

struct queue *display_q(struct queue *q)
{
	struct node *ptr;
	ptr=q->front;
	if(ptr==NULL)
	{
		printf("\nNo Requests To Show.\n");
	}
	else
	{
		printf("\n");
		while(ptr!=q->rear)
		{

			printf(" %s",ptr->data);
			ptr=ptr->next;
		}

		printf(" %s",ptr->data);
	}
	return q;
}

struct queue *delete_q(struct queue *q)
{
	struct node *ptr;
	ptr=q->front;
	if(q->front==NULL)
	{
		printf("\nNo Requests To Show.\n");
	}
	else
	{
		q->front=q->front->next;
		strcpy(search,ptr->data);
		printf("\nThe Car To Be Searched: ");
		printf(" %s",ptr->data);
		free(ptr);
	}
	return q;
}

struct node *delete_beg(struct node *start)
{
	struct node *ptr;
	ptr=start;
	strcpy(stack,ptr->data);
	start=start->next;
	free(ptr);
	return start;
}

struct node *delete_ll(struct node *start,char search[])
{
	struct node *ptr, *preptr;
	ptr=start;
	if(strcmp(ptr->data,search)==0)
	{
		printf("\nCar Found.\n");
		start=delete_beg(start);
		return start;
	}
	else
	{
		while(strcmp(ptr->data,search)!=0)
		{
			preptr=ptr;
			ptr=ptr->next;
			if(strcmp(ptr->data,search)==0)
			{
				printf("\nCar Found\n");
				strcpy(stack,ptr->data);
				preptr->next=ptr->next;
				free(ptr);
				return start;
			}
			else
			{
				printf("\nCar Not Available.\n");
				return start;
			}
		}
	}
}

struct node *push(struct node *top, char stack[])
{
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	strcpy(ptr->data,stack);
	if(top==NULL)
	{
		ptr->next=NULL;
		top=ptr;
	}
	else
	{
		ptr->next=top;
		top=ptr;
	}
	return top;
}

struct node *display_s(struct node *top)
{
	struct node *ptr;
	ptr=top;
	if(top==NULL)
	{
		printf("\nNo Deliveries Made.\n");
	}
	else
	{
		while(ptr!=NULL)
		{

			printf("\n %s",ptr->data);
			ptr=ptr->next;
		}
	}
	return top;
}

void peek(struct node *top)
{
	if(top==NULL)
	{
		printf("\nNo Deliveries Made.\n");
	}
	else
	{
		printf("\nLast Delivery Made: ");

		printf(" %s",top->data);
	}
}
