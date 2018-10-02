#include <iostream>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
};

struct node* newNode(int data) 
{ 
  struct node* node = (struct node*) 
                       malloc(sizeof(struct node)); 
  node->data = data; 
  node->left = NULL; 
  node->right = NULL; 
  
  return(node); 
} 

int height (node *root, int &ans);

int diameter(node *root){
	int ans = 0;
  height(root, ans);
  return ans ;
}

int height(node *root, int &ans){
	
	if(!root)
	return 0;
	
	int l = height (root->left, ans);
	int r = height (root->right, ans);
	ans = max(ans, l+r + 1);
	cout <<root->data<<" "<<ans<<" "<<l<<r<<endl;
	return max(l,r) + 1;
}

int main() {
  struct node *root = newNode(1); 
  root->left        = newNode(2); 
  root->right       = newNode(3); 
  root->left->left  = newNode(4); 
  root->left->right = newNode(5);
  root->left->right->left = newNode(6);
  root->left->left->left = newNode(7);
  cout<<diameter(root);
  
	return 0;
}
