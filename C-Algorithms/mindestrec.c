#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


void search_recursive(int M, int R, int n, int positions[], int costs[],int index,int cost,int *mincost,int dest){
if(index>n) return;
if(dest+R>=M){
if(cost<*mincost){
*mincost=cost;
return;
}
return;

}

for(int i=index;i<n;i++){
if(positions[i]-dest<=R)
search_recursive(M,R,n,positions,costs,i+1,cost+costs[i],mincost,positions[i]);
else break;


}
  }

int findMinRechargingCost(int M, int R, int n, int positions[], int costs[]){
if(positions[0]>R) return -1;
int i=INT_MAX;
search_recursive(M,R,n,positions,costs,0,0,&i,0);
if(i==INT_MAX) return -1;
return i;


}