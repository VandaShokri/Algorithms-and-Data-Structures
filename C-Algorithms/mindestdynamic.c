#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int findMinRechargingCost(int M, int R, int n, int positions[], int costs[]){
if(M<=R) return 0;
if(positions[0]>R || n<=0 ) return -1;
int* dp=(int*)malloc(n*sizeof(int));
if(dp==NULL) return -1;
for(int i=0;i<n;i++){
if(positions[i]<=R) dp[i]=costs[i];
else dp[i]=INT_MAX;
}
for(int i=0;i<n-1;i++){
if(dp[i]==INT_MAX) continue;
for(int j=i+1;j<n;j++){
if(positions[j]-positions[i]>=R){
if(dp[i]+costs[j]<dp[j]) dp[j]=dp[i]+costs[j];}
}
  }

int min=INT_MAX;
for(int i=0;i<n;i++){
if(positions[i]+R>=M && dp[i]!=INT_MAX){
if(dp[i]<min) min=dp[i];
}
   }
free(dp);
if(min==INT_MAX) return -1;
return min;


}