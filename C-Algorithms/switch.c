#include <stdio.h>
#include <stdlib.h>

int find_comb(int** mat,int switch,int bulb, int* array,int k,int pos,int index){

if(pos==k){
for(int i=0;i<bulb;i++){
   int count=0;
   for(int j=0;j<k;j++){
   if(mat[array[j]][i]==1) count++;
   }
    if(count%2==0) return 0;
    
        }
 
 printf("min number of bulbs is %d with switches { %d",k,array[0]);
 for(int j=1;j<k;j++){
 printf(", %d",array[j]); }
printf("}\n");
return 1;

}

for(int i=index;i<switch;i++){
array[pos]=i;
if(find_comb(mat,switch,bulb,array,k,pos+1,i+1)) return 1;
}
return 0;
}

void switches (int **mat, int switch, int bulb){

int* array=(int*)malloc(switch*sizeof(int));
if(array==NULL) return;
for(int k=0;k<switch;k++){
if(find_comb(mat,switch,bulb,array,k,0,0)) { free(array); return;}

}
free(array);


}
