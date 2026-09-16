#include <stdio.h>
#include <stdlib.h>
void recursive_comb(int* a, int n, int pos,int count ,int* max,int temp){
if(count==3){
if(temp>*max) *max=temp; return; }
for(int i=pos;i<n;i++){
recursive_comb(a,n,i+1,count+1,max,temp*a[i]);


}


}
int max_triplet_product(int a[],int n){
if(n<3) return 0;
int max=a[0]*a[1]*a[2];
recursive_comb(a,n,0,0,&max,1);
return max; }
