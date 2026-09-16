#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct tree_d{
   char* s;
   struct tree_d *left;
   struct tree_d *right;8
}tree_t;
tree_t *create_node(char *s){
    tree_t* new=(tree_t*)malloc(sizeof(tree_t));
    if(new==NULL) return NULL;
    int n=strlen(s)+1;
    new->s=(char*)malloc(n*sizeof(char));
    if(new->s==NULL) { free(new); return NULL;}
    new->left=NULL;
    new->right=NULL;
    strcpy(new->s,s);
    return new;
}

tree_t *fill(tree_t *root,char *s){
    if(s==NULL) return root;
    if(root==NULL){
        root=create_node(s);
        return root;
    }
    int capacity=4,head=0,tail=0;
    tree_t **queue=(tree_t**)malloc(capacity*sizeof(tree_t*));
    if (queue==NULL){
        return root;
    }
    queue[tail++]=root;

    while(head<tail){
        tree_t* curr = queue[head++];
        if(curr->left==NULL){
            curr->left=create_node(s);
            free(queue);
            return root;
        }
        if(curr->right==NULL){
            curr->right=create_node(s);
            free(queue);
            return root;
        }
        if(tail+2>capacity){capacity*=2;
        queue=(tree_t**)realloc(queue,capacity*sizeof(tree_t*));}
        queue[tail++]=curr->left;
        queue[tail++]=curr->right;
} 
free(queue);
return root;  


}