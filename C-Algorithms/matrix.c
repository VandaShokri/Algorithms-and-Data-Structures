#include <stdio.h>
#include <stdlib.h>
void fill_mat1(char *s ,char **mat, int n){

int count=0;

for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
if(s[count]!='\0'){
mat[i][j]=s[count];
count++;} 
else {mat[i][j]='-';
}

}
   }
     
          }
void fill_mat2(char *s ,char **mat, int n){

int count=0;


for(int i=n-1;i>=0;i--){
for(int j=n-1;j>=0;j--){
if(s[count]!='\0'){
mat[j][i]=s[count];
count++;} 
else {mat[j][i]='-';
}

}
   }
     
          }

void transform(char *s ,char **mat1,char **mat2, int n){

fill_mat1(s,mat1,n);
fill_mat2(s,mat2,n);


}