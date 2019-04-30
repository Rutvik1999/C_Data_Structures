#include <stdio.h>
#include <stdlib.h>

struct node
	{
 	int val;
 	struct node* next;
	};
struct node* start_n = NULL;

int insert_start( int *val )
{
	struct node* new_node;
	new_node = (struct node*) malloc(sizeof(struct node));
	if(start_n == NULL)
	{		
		start_n = new_node;
		new_node->val = *val;
		new_node->next = NULL;
	}
	else
	{
		new_node->val = *val;
		new_node->next = start_n;
	}
}

int insert_end( int *val )
{
	struct node* new_node;
	struct node* temp;
	new_node = (struct node*) malloc(sizeof(struct node));
	if(start_n == NULL)
	{		
		start_n = new_node;
		new_node->val = *val;
		new_node->next = NULL;
	}
	else
	{
		temp = start_n;
		while(temp->next != NULL)
			temp = temp->next;
		new_node->val = *val;
		new_node->next = NULL;
		temp->next = new_node;
	}
}

int insert_spec( int *prev_val , int *val )
{
	struct node* new_node;
	struct node* temp;
	new_node = (struct node*) malloc(sizeof(struct node));
	temp = start_n;
	while(temp->val != *prev_val)
		temp = temp->next;
	new_node->val = *val;
	new_node->next = temp->next;
	temp->next = new_node;
	
}

int display()
{
	struct node* temp;
	temp = start_n;
	while(temp->next != NULL)
		{
		temp = temp->next;
		printf(" %d -> ",temp->val);
		}
}


int main()
{
	int val,option,prev_val;
	beg:
	printf(" 1) Insert in linked list \n 2) Insert at end \n 3) Insert after Specified node \n 4) Delete givgen node \n 5) Delete from End \n 6) Delete at start \n  7) Display Linked list \n");
	scanf(" %d",&option);
	switch(option)
	{
		case 1 :
		printf("Enter Value :");
		scanf(" %d",&val);
		insert_start(&val);
		goto beg;
		break;
		
		case 2 :
		printf("Enter Value :");
		scanf(" %d",&val);
		insert_end(&val);
		break;

		case 3 :
		printf("Enter Value of new node and value of previous node:");
		scanf(" %d %d",&val,&prev_val);
		insert_spec(&prev_val,&val);
		break;
/*
		case 4 :
		printf("Enter Value :");
		scanf(" %d",&val);
		del_given(&val);
		break;

		case 5 :
		del_end();
		break;

		case 6 :
		del_start();
		break;
*/		
		case 7 :
		display();
		goto beg;
		break;

		default : 
		perror("\n Error ! Invalid Input \n");
		goto beg; 
	}
	return 0;
}





