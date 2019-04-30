#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node 
{
    char string[15];
    struct node *right;
    struct node *left;
};




void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%s \n", root->string); 
        inorder(root->right); 
    } 
} 


// str_compare agad varu nanhu hoy toh return 1

int str_compare(char str1[15], char str2[15])
{
    while ( *str1 != '\0' && *str1 == *str2 )
    {
     ++str1;
     ++str2;
    }
    if((int)(*str1) > (int)(*str2))
        return 1;
    else return 0;
}
struct node *New_Node(char string[15]) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    for(int i = 0 ; i < 15 ; i++)
        (temp->string)[i] = string[i]; 
    temp->left = NULL;
    temp->right = NULL; 
    return temp; 
} 
struct node *insert(struct node *node, char string[15])
{
    if(node == NULL)
        {
            return New_Node(string);
        }
    if(str_compare(string,node->string))
        {
            node->left = insert(node->left, string);
        }
    else if(str_compare(node->string,string))
        {
            node->right = insert(node->right, string);
        }
    return node;
}

int main()
{   char string[15];
    struct node *root = NULL;
    printf("Enter String to insert in BST (enter 'qx' to break loop)\n");
    scanf(" %s",string);
    root = insert(root, string);
    while(strcmp(string,"qx"))
    { 
        scanf(" %s",string);
        insert(root, string);
    }
    inorder(root);
    return 0;
}