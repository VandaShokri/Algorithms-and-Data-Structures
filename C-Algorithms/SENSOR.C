#include <stdio.h>
#include <stdlib.h>
int check_coverage(int** grid,int* selected,int k,int c){
int check;
    for(int i=0;i<c;i++){
        for(int j=0;j<k;j++){
            check=0;
         if(grid[selected[j]][i]){
            check=1;
            break;
         }
        

        }
         if(!check) return 0;
    }
    return check;

}

int recursive_search(int** grid,int* selected,int r,int c,int start,int pos,int k,int* sensor){
    if(pos==k){
       int found=check_coverage(grid,selected,k,c);
       if(found){
       for(int i=0;i<k;i++){
        sensor[i]=selected[i];
     }
    }
    return found;

       }
    for(int i=start;i<r;i++){   
    selected[pos]=i;   
    if(recursive_search(grid,selected,r,c,i+1,pos+1,k,sensor)){
        return 1;
    }  } 
    return 0;


}
int maximize_sensor_coverage(int** grid,int r , int c,int* sensor,int* count){
    int* selected=(int*)malloc(r*sizeof(int));
    if (selected==NULL) exit(1);
    for(int i=1;i<=r;i++){

     if(recursive_search(grid,selected,r,c,0,0,i,sensor)){

        *count=i;
        free(selected);
        return 1;
     }
     


    }

free(selected);
return 0;




}