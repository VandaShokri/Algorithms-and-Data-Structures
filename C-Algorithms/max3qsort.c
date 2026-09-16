#include <stdio.h>
#include <stdlib.h>
int cmp(void* a,void*b){
    return *(int*)a-*(int*b);
}
int max_triplet_product(int a[],int n){
   
    qsort(a,n,sizeof(int),cmp);
    int a1=a[n-1]*a[n-2]*a[n-3];
    int a2=a[0]*a[1]*a[n-1];
    return a1>a2 ? a1:a2;
}