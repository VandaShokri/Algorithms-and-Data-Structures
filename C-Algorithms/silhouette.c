#include <stdio.h>
#include <stdlib.h>


typedef struct tree_d{
 int value;
char* string;
struct tree_d* left;
struct tree_d* right;
}tree_t;
int is_leaf(tree_t* root){
if (root==NULL) return 0;
return (root->right==NULL && root->left==NULL);}
void  print_left(tree_t* root){
if(root==NULL||is_leaf(root) ) return;
 printf("%d %s",root->value,root->string);
if(root->left!=NULL){
print_left(root->left);}
else if(root->right!=NULL){
print_left(root->right);}

}
void print_leaf(tree_t* root){
if(root==NULL) return;
if(root->right==NULL && root->left==NULL){
printf("%d %s",root->value,root->string);
return;}
print_leaf(root->left);
print_leaf(root->right);
}
void  print_right(tree_t* root){
if(root==NULL || is_leaf(root) ) return;
if(root->right!=NULL){
print_right(root->right);}
else if(root->left!=NULL){
print_right(root->left);}

printf("%d %s",root->value,root->string);


}

void silhouette(tree_t** root){
if(root==NULL || *root==NULL) return;
printf("%d %s",(*root)->value,(*root)->string);

if(!(is_leaf(*root))){

print_left((*root)->left);
print_leaf(*root);
print_right((*root)->right);}


}