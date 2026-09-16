#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_dup_rows(char **mat,int c,int i,int j){

for(int k=0;k<c;k++){
if(mat[i][k]!=mat[j][k]) return 0;

}
return 1;
}
void remove_row(char** mat,int r,int c,int x){
 for(int i=x;i<r-1;i++){
   for(int k=0;k<c;k++){
    mat[i][k]=mat[i+1][k];


   }
 
}
 }

int check_dup_cols(char **mat,int r,int i,int j){

for(int k=0;k<r;k++){
if(mat[k][i]!=mat[k][j]) return 0;

}
return 1;
}
void remove_col(char** mat,int r,int c,int x){
 for(int i=x;i<c-1;i++){
   for(int k=0;k<r;k++){
    mat[k][i]=mat[k][i+1];


   }
 
}
 }


char **compress (char **mat, int* r, int* c){

for(int i=0;i<(*r)-1;i++){
  for(int j=i+1;j<*r;j++){
   if(check_dup_rows(mat,*c,i,j)){
     remove_row(mat,*r,*c,j);
     j--;
     (*r)--;
   }
     }
}

for(int i=0;i<(*c)-1;i++){
  for(int j=i+1;j<*c;j++){
   if(check_dup_cols(mat,*r,i,j)){
     remove_col(mat,*r,*c,j);
     j--;
     (*c)--;
   }
     }
}

return mat;


}