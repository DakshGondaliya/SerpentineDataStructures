#include <stdio.h> 
#include <stdlib.h> 
  
/* A binary tree node has data, pointer to left child 
   and a pointer to right child */
struct node 
{ 
    int data; 
    struct node* left, *right; 
}; 
  
struct node* newNode(int data); 
  
int max(int a, int b); 
  
int height(struct node* node); 
  
int diameter(struct node * tree) 
{ 
  
   if (tree == NULL) 
     return 0; 
     
  int lheight = height(tree->left); 
  int rheight = height(tree->right); 
  
  int ldiameter = diameter(tree->left); 
  int rdiameter = diameter(tree->right); 
  
   1) Diameter of left subtree 
   2) Diameter of right subtree 
   3) Height of left subtree + height of right subtree + 1 
  return max(lheight + rheight + 1, max(ldiameter, rdiameter)); 
}  
  

int height(struct node* node) 
{ 
   /* base case tree is empty */ 
   if(node == NULL) 
       return 0;    
   return 1 + max(height(node->left), height(node->right)); 
}  
  
struct node* newNode(int data) 
{ 
  struct node* node = (struct node*) 
                       malloc(sizeof(struct node)); 
  node->data = data; 
  node->left = NULL; 
  node->right = NULL; 
  
  return(node); 
} 
  
int max(int a, int b) 
{ 
  return (a >= b)? a: b; 
}     
  
int main() 
{ 
  
  /* Constructed binary tree is  */
  struct node *root = newNode(1); 
  root->left        = newNode(2); 
  root->right       = newNode(3); 
  root->left->left  = newNode(4); 
  root->left->right = newNode(5); 
  
  printf("Diameter of the given binary tree is %d\n", diameter(root)); 
  
  getchar(); 
  return 0; 
} 
