#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct listB_d{
 char* string;
 struct listB_d* next;

}listB_t;
typedef struct listA_d{
    listB_t* head;
    struct listA_d* next;
}listA_t;
listB_t* merge_2lists(listB_t* l1,listB_t* l2){
 if(l1==NULL) return l2;
 if(l2==NULL) return l1;
 listB_t*  merged=NULL;
 listB_t* tail=NULL;
 if(strcmp(l1->string,l2->string)<0){
  merged=l1;
  l1=l1->next;

 }
 else if(strcmp(l1->string,l2->string)==0){
  merged=l1;
  l1=l1->next;
  listB_t* temp=l2;
  l2=l2->next;
  free(temp);

 }
 else {
    merged=l2;
    l2=l2->next;
 }
 tail=merged;
 while(l1!=NULL && l2!=NULL){
    if(strcmp(l1->string,l2->string)<0){
  tail->next=l1;
  l1=l1->next;

 }
  else if(strcmp(l1->string,l2->string)==0){
  tail->next=l1;
  l1=l1->next;
  listB_t* temp=l2;
  l2=l2->next;
  free(temp);
  

 }
 else {
  tail->next=l2;
  l2=l2->next;

 }
 tail=tail->next;
 }

if(l1==NULL){
   
        tail->next=l2;
}
else tail->next=l1;
return merged;
}
listB_t *merge(listA_t *head){
    if(head==NULL) return NULL;
    listB_t* headB=NULL;
    
    while(head!=NULL){
        headB=merge_2lists(headB,head->head);
       
         head=head->next;
        



    }
    return headB;



}