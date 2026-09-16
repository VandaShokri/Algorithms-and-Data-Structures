#include <stdio.h>
#include <stdlib.h>
void combination(int n,int* time,int* priority,int th,int* best,int* l,int* max,int pos,int* curr,int sum,int curr_l,int curr_p){

   if(curr_p>*max){
       *max=curr_p;
       *l=curr_l;
       for(int i=0;i<*l;i++){
        best[i]=curr[i];
       }

    }
  


 

for(int i=pos;i<n;i++){
    if(sum+time[i]<=th ){
        curr[curr_l]=i;
        combination(n,time,priority,th,best,l,max,i+1,curr,sum+time[i],curr_l+1,curr_p+priority[i]);

    }
    
}
}
void opt_task(int n,int* time,int* priority,int th,int *best,int *l,int* max){
    if(n<=0 || time==NULL) return;
    *max=-1;
    *l=0;
    int* curr=(int*)malloc(n*sizeof(int));
    if(curr==NULL) return;
combination(n,time,priority,th,best,l,max,0,curr,0,0,0);
free(curr);

}