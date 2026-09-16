#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct list_d {
    int val;
    struct list_d *next;
} list_t;

typedef struct bst_d {
    char *s;
    list_t *head;
    struct bst_d *left;
    struct bst_d *right;
} bst_t;


list_t *insert_list(list_t *head, int i) {
    list_t *node = (list_t *)malloc(sizeof(list_t));
    if (node == NULL) return NULL;
    node->val = i;
    node->next = head;
    return node;
}


bst_t *create_node_t(FILE *fp, char name[], int n) {
    bst_t *node = (bst_t *)malloc(sizeof(bst_t));
    if (node == NULL) return NULL;
    
    node->s = strdup(name);
    if (node->s == NULL) {
        free(node);
        return NULL;
    }
    
    node->head = NULL; 
    node->left = NULL;
    node->right = NULL;
    
    for (int i = 0; i < n; i++) {
        int x;
        if (fscanf(fp, "%d", &x) != 1) return NULL; 
        node->head = insert_list(node->head, x);
    }
    return node;
}
        
bst_t *search_tree(bst_t *head, char name[]) {
    if (head == NULL) return NULL;
    int n = strcmp(head->s, name);
    if (n == 0) return head;
    else if (n > 0) return search_tree(head->left, name);  
    else return search_tree(head->right, name);             }




void update_tree(FILE *fp, bst_t *node, int n) {
    for (int i = 0; i < n; i++) {
        int x;
        if (fscanf(fp, "%d", &x) != 1) return; 
        node->head = insert_list(node->head, x);
    }
}

bst_t *insert_node(bst_t *head, bst_t *new_node) {
    if (head == NULL) return new_node;
    int n = strcmp(head->s, new_node->s);
    
   
    if (n > 0) {
        head->left = insert_node(head->left, new_node);
    } else if (n < 0) {
        head->right = insert_node(head->right, new_node);
    }
    return head; // Must return head!
}

bst_t *file_to_bst_of_lists(char *filename) { // Renamed parameter to avoid shadowing
    FILE *fp = fopen(filename, "r"); 
    if (fp == NULL) {
        printf("error opening the file \n");
        return NULL;
    }
    
    char name[MAX + 1];
    int n;
    bst_t *head = NULL;
    bst_t *temp = NULL; 

    while (fscanf(fp, "%s %d", name, &n) == 1) { 
        temp = search_tree(head, name);
        if (temp == NULL) {
            bst_t *new_node = create_node_t(fp, name, n); 
            head = insert_node(head, new_node);        
        } else {
            update_tree(fp, temp, n);                  
        }
    }
    
    fclose(fp);
    return head;
}