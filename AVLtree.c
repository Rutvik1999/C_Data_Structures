#include <stdio.h>
#include <stdlib.h>

struct Node 
{ 
    int key; 
    struct Node *left; 
    struct Node *right; 
    int height; 
}; 

int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 

int height(struct Node *N) 
{ 
    if (N == NULL) 
        return 0; 
    return N->height; 
} 

struct Node* newNode(int key) 
{ 
    struct Node* node = (struct Node*) malloc(sizeof(struct Node)); 
    node->key   = key; 
    node->left   = NULL; 
    node->right  = NULL; 
    node->height = 1;   
    return(node); 
} 

int getBalance(struct Node *N) 
{ 
    if (N == NULL) 
        return 0; 
    return height(N->left) - height(N->right); 
} 

struct Node *rightRotate(struct Node *y) 
{ 
    struct Node *x = y->left; 
    struct Node *z = x->right; 

    x->right = y; 
    y->left = z; 
  
    y->height = max(height(y->left), height(y->right))+1; 
    x->height = max(height(x->left), height(x->right))+1; 

    return x; 
} 

struct Node *leftRotate(struct Node *x) 
{ 
    struct Node *y = x->right; 
    struct Node *z = y->left; 
  
    y->left = x; 
    x->right = z; 

    x->height = max(height(x->left), height(x->right))+1; 
    y->height = max(height(y->left), height(y->right))+1; 
  
    return y; 
} 

struct Node *leftRightRotate(struct Node *x)
{
    x->left =  leftRotate(x->left); 
        return rightRotate(x); 
}

struct Node *rightLeftRotate(struct Node *x)
{
        x->right = rightRotate(x->right); 
        return leftRotate(x); 
}

struct Node* insert(struct Node* node, int key) 
{ 

    if (node == NULL) 
        return(newNode(key)); 
  
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key); 
    else 
        return node; 
  
    
    node->height = 1 + max(height(node->left),height(node->right)); 
  
    int balance = getBalance(node); 
  
    if (balance > 1 && key < node->left->key) 
        return rightRotate(node); 
  
    if (balance < -1 && key > node->right->key) 
        return leftRotate(node); 
  

    if (balance > 1 && key > node->left->key) 
    { 
        return leftRightRotate(node);
    } 

    if (balance < -1 && key < node->right->key) 
    { 
        return rightLeftRotate(node);
    } 
    return node; 
} 

void preorder(struct Node *root) 
{ 
    if (root != NULL) 
    { 
        printf("%d  ", root->key);  
        preorder(root->left); 
        preorder(root->right); 
    } 
}   

void inorder(struct Node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d  ", root->key); 
        inorder(root->right); 
    } 
} 

void postorder(struct Node *root) 
{ 
    if (root != NULL) 
    { 
        postorder(root->left); 
        postorder(root->right); 
        printf("%d  ", root->key); 
    } 
}  
  
int main()
{
    struct Node *root = NULL; 
    int val = 0;
    printf("Enter values to put in tree (Enter -100000 to end loop \n");
    while(1)
    {
        scanf(" %d",&val);
        if(val != (-100000))
            root = insert(root,val);
        else break;
    }
    printf("Preorder traversal of the constructed AVL tree is \n"); 
    preorder(root); 
    printf("Postorder traversal of the constructed AVL tree is \n"); 
    postorder(root);
    printf("Inorder traversal of the constructed AVL tree is \n"); 
    inorder(root);
  return 0; 
}