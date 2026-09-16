
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
int data;
struct node *left;
struct node *right;} node_t;


int size_tree(node_t* root){
if(root==NULL) return 0;
return 1+size_tree(root->right)+size_tree(root->left);
}
void tree_to_array(node_t* root,node_t** array,int* i){
if(root==NULL) return;
tree_to_array(root->left,array,i);
array[*i]=root;
(*i)++;
tree_to_array(root->right,array,i);

}
node_t* insert_to_tree(node_t** array, int start,int end){
if(start>end) return NULL;
int mid= (end+start)/2;
node_t* root=array[mid];
root->left=insert_to_tree(array,start,mid-1);
root->right=insert_to_tree(array,mid+1,end);
return root;
}


node_t* balance_BST( struct node* root){

int n =size_tree(root),i=0;

node_t** array=(node_t**)malloc(n*sizeof(node_t*));
if (array==NULL) return NULL;
tree_to_array(root,array,&i);
node_t* new_root=insert_to_tree(array,0,n-1);
free(array);
return new_root;

}