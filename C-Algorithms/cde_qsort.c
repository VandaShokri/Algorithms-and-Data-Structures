#include <stdio.h>
#include <stdlib.h>

int compare(void* a,void* b){
return (*(int*)a - *(int*)b);

}

void cde(int** mat,int r,int c){
 int n=r*c;
 if(n<=0) return;
 int* arr= (int*)malloc(n*sizeof(int));
 if(arr==NULL) return;
int index=0;
 for(int i=0;i<r;i++){
  for(int j=0;j<c;j++){
    arr[index++]=mat[i][j];
   }
 }

qsort(arr,n,sizeof(int),compare);
int curr=arr[0];
int count=1;
int first=1;

for(ibt i=0;i<n;i++){
if(arr[i]==curr) count++;
else{
  if(!first) printf(",");
  printf("%d [%d]",curr,count);
  curr=arr[i];
  count=1;
  first=0;
}


}
printf("%d [%d]",curr,count);
printf("\n"); 
free(arr);

}

#include <stdio.h>
#include <stdlib.h>

// Comparator function (identical to the one used for qsort)
int compare(const void *a, const void *b) {
    int val_a = *(const int *)a;
    int val_b = *(const int *)b;

    if (val_a < val_b) return -1;
    if (val_a > val_b) return 1;
    return 0;
}

int main(void) {
    // bsearch REQUIRES the array to be sorted beforehand
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target = 23;

    // bsearch parameters:
    // 1. Pointer to the key being searched
    // 2. Base address of the sorted array
    // 3. Number of elements
    // 4. Size of each element in bytes
    // 5. Comparator function pointer
    int *result = (int *)bsearch(&target, arr, n, sizeof(int), compare);

    if (result != NULL) {
        // Calculate the index using pointer arithmetic
        int index = result - arr;
        printf("Found %d at index %d.\n", *result, index);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}