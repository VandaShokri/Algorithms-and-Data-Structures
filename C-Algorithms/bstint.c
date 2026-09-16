#include <stdlib.h>
typedef struct node_d{
int val;
struct node_d* left;
struct node_d* right;
}node_t;

void fill_array(node_t *root, int *v, int n,int* i){
if(root==NULL) return;
fill_array(root->left,v,n,i);
v[(*i)++]=root->val;
fill_array(root->right,v,n,i);


}

node_t* array_to_tree(int* v,int l,int r ){
if(l>r){
return NULL;}
int mid=(r+l)/2;
node_t *root=(node_t*)malloc(sizeof(node_t));
if (root==NULL) return NULL;
root->val=v[mid];
root->left=array_to_tree(v,l,mid-1);
root->right=array_to_tree(v,mid+1,r);
return root;


}
node_t *balance (node_t *root, int *v, int n){
if(root==NULL || v==NULL || n<=0) return NULL;
int i=0;
fill_array(root,v,n,&i);
node_t* new_root=array_to_tree(v,0,n-1);
return new_root;


}
