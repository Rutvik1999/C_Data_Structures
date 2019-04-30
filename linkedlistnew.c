#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start=NULL;
void insert_beg()
{
	int num;
	struct node *newnode;
			printf("Enter value to enter\n");
			scanf("%d",&num);
			newnode=(struct node *)malloc(sizeof(struct node));
            newnode->data=num;
            newnode->next=start;
            start=newnode;
           // printf("check=%d\n",newnode->data);
}
void insert_end()
{
	int num;
	struct node *ptr,*newnode;
	ptr=start;
			printf("Enter value to enter\n");
			scanf("%d",&num);
			newnode=(struct node *)malloc(sizeof(struct node));
	if(start==NULL)
		{
			start=newnode;
			newnode->data=num;
			newnode->next=NULL;
		}
	else
		{
			newnode->data=num;
			newnode->next=NULL;
			while(ptr->next!=NULL)
				{
					ptr=ptr->next;
				}
			ptr->next=newnode;
		}
}
void display()
{
	struct node *ptr;
	ptr=start;
	if(start==NULL)
	{
		printf("Linkedlist is empty\nHEAD -> -> NULL\n");
	}
	else
	{
		printf("The linked list is:-\n");
		printf("HEAD->");
		while(ptr!=NULL)
				{
				printf("%d ->",ptr->data);
				ptr=ptr->next;
				}
		printf("NULL\n");
	}
}
void insert_after()
{
	struct node *ptr,*newnode,*posptr;
	int val,num;
	ptr=start;
	if(start==NULL)
	{
		printf("START -> NULL\n");
	}
	else
	{
		printf("Enter the value after which you want to enter new node\n");
		scanf("%d",&val); 
		while(ptr->data!=val)
		{
			ptr=ptr->next;
		}
		posptr=ptr->next;
		printf("Enter value to enter\n");
		scanf("%d",&num);
		newnode=(struct node *)malloc(sizeof(struct node));
		newnode->data=num;
		newnode->next=posptr;
		ptr->next=newnode;
	}
}
void delete_beg()
{
	struct node *ptr;
	if(start==NULL)
	{
		printf("START -> NULL\n");
	}
	else if(start->next==NULL)
	{
		free(start);
		start=NULL;
	}
	else
	{	
		ptr=start;
		start=start->next;
		free(ptr);
	}
}
void delete_end()
{
	struct node *ptr,*preptr;
	if(start==NULL)
	{
		printf("START -> NULL\n");
	}
	else if(start->next==NULL)
	{
		free(start);
		start=NULL;
	}
        else    
        {
	ptr=start;
	while(ptr->next!=NULL)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	free(ptr);
	preptr->next=NULL;
	}
}
void delete_after()
{
	struct node *ptr,*posptr;
	int val;
	if(start==NULL)
	{
		printf("START -> NULL\n");
	}
	else if(start->next==NULL)
	{
		printf("There is only one value so there is no value after it\n");
	}
	else
	{
		printf("Enter the value after which you want to delete the node\n");
		scanf("%d",&val); 
		ptr=start;
		while(ptr->data!=val)
		{
			ptr=ptr->next;
		}	
		posptr=ptr->next;
		ptr->next=posptr->next;
		free(posptr);
	}	
}

void reverse()
{
	struct node *prev = NULL;
	struct node *nextnode = NULL;
	struct node *cur = start;
	while(cur != NULL)
		{
		nextnode = cur->next;
		cur->next = prev;
		prev = cur;
		cur = nextnode;
		}
	start = prev;	
}
int main()
{
int choice;
start:
printf("\n 1.Insert at start \n 2.Insert at end \n 3.Display \n 4.insert after \n 5.delete at beg \n 6.delete at end \n 7.delete after\n 8.Reverse List \n 9.exit  \n");
scanf("%d",&choice);
switch(choice)
{
	case 1:
	{
		insert_beg();
		break;
	}
	case 2:
	{
		insert_end();
		break;
	}
	case 3:
	{
		display();
		break;
	}
	case 4:
	{
		insert_after();
		break;
	}
	case 5:
	{
		delete_beg();
		break;
	}
	case 6:
	{
		delete_end();
		break;
	}
	case 7:
	{
		delete_after();
		break;
	}
	case 8:
	{
		reverse();
		break;
	}
	case 9:
	{
		exit(0);
	}
	default:
	{
		printf("Invalid choice\n");
	}
}
goto start;
return 0;
}
