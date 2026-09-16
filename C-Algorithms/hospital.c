#include <stdio.h>
#include <stdlib.h>


int recursive_search(int** mat,int nd ,int nh ,int* selected ,int* count ,int* array,
int k, int index ,int pos){

if(pos==k){
int found;
for(int j=0;j<nd;j++){
found=0;
for(int i=0;i<k;i++){
if(mat[j][array[i]]){
found=1; break;}


}
if (!found) return 0;

}

for(int j=0;j<k;j++){
selected[j]=array[j];

}

*count=k;
return 1;
}

for(int i=index;i<nh;i++){
array[pos]=i;
if(recursive_search(mat,nd,nh,selected,count,array,k,i+1,pos+1))
return 1; 
}

return 0;
}






int minimize_hospital_count (
int **coverage_matrix, int num_districts, int num_hospitals, int *selected_hospitals,
int *count){
if(coverage_matrix == NULL){
printf("error"); 
return 0;
}


int* array=(int*)malloc(num_hospitals*sizeof(int));
if(array==NULL) {
printf("error in memory allocation"); return 0; }

for(int k=1;k<=num_hospitals+;k++){

if(recursive_search(coverage_matrix,num_districts,num_hospitals,selected_hospitals,count, array,k,0,0)) {
free(array);
return 1;

}




}

free(array);
return 0;
}
