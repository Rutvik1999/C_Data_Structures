#include<stdio.h> 
#include<stdlib.h> 
   
struct node 
{ 
    long double key; 
    struct node *left, *right; 
}; 

struct node *Node_initialize(long double key) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->key = key; 
    temp->left = NULL;
    temp->right = NULL; 
    return temp; 
} 

void preorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        printf("%Lf \n", root->key);  
        preorder(root->left); 
        preorder(root->right); 
    } 
}   

void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%Lf \n", root->key); 
        inorder(root->right); 
    } 
} 

void postorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        postorder(root->left); 
        postorder(root->right); 
        printf("%Lf \n", root->key); 
    } 
} 

struct node *insert(struct node *node , long double key)
{
    if(node == NULL)
    {
        node = Node_initialize(key);
        return node;
    }
    if(key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if(key > node->key)
    {
        node->right = insert(node->right, key);
    }
    return node;
}

int main() 
{ 
    struct node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80);

    printf("Tree in Preorder form is : \n"); 
    preorder(root); 

    printf("Tree in inorder form is : \n"); 
    inorder(root);

    printf("Tree in Postorder form is : \n"); 
    postorder(root);
   
    return 0; 
} 