#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree_d{

char* s;
struct tree_d *left;
struct tree_d *right;}tree_t;


int check_isomorphic_tree (tree_t *rootA, tree_t *rootB){
if(rootA==NULL && rootB==NULL) return 1;
if(rootA==NULL || rootB==NULL) return 0;

if(rootA->s==NULL || rootB->s==NULL) return 0;
if(strcmp(rootA->s,rootB->s)!=0) return 0;
equal=(check_isomorphic_tree(rootA->right,rootB->right)&&check_isomorphic_tree(rootA->left,rootB->left));
iso=(check_isomorphic_tree(rootA->right,rootB->left)&&check_isomorphic_tree(rootA->left,rootB->right));
return egual||iso;



}

if(rootA->s==NULL && rootB->s==NULL) return 1;
