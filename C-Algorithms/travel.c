#include <stdio.h>
#include <stdlib.h>
int check_dup(int* arr,int x, int len){

for(int i=0;i<len;i++){
if(arr[i]==x) return 1;

}
return 0;
}
void search_rec(int **m, int n, int curr, int dest_city, int budget,int cost,int* count,int* selected,int len ){

if(curr==dest_city){

if(cost<=budget){
printf("path %d:%d ",*count,selected[0]);
for(int i=1;i<len;i++)
{printf("-> %d",selected[i]);
}
printf("=%d\n",cost);
(*count)++;
}

return;
}

for(int i=0;i<n;i++){
int edge_cost=m[curr][i];
if(edge_cost==0) continue;
if(check_dup(selected,i,len)) continue;
if(cost+edge_cost>budget) continue;
selected[len]=i;
search_rec(m,n,i,dest_city,budget,cost+edge_cost,count,selected,len+1);
}





}
void find_all_paths (int **m, int n, int src_city, int dest_city, int budget){

int* selected=(int*)malloc(n*sizeof(int));
if(selected==NULL) return;
int i=0;
selected[0]=src_city;
search_rec(m,n,src_city,dest_city,budget,0,&i,selected,1);

free(selected);



}