
#include <stdio.h>
#include <stdlib.h>

void comb_cols(int** m, int r, int c,int index,int size,int* selected){
if(size==4){
if(m[selected[0]][selected[2]] == m[selected[0]][selected[3]]
&& m[selected[0]][selected[3]]== m[selected[1]][selected[3]]
&& m[selected[1]][selected[3]]== m[selected[1]][selected[2]]){
for(int i=selected[0];i<=selected[1];i++){
for(int j=selected[2];j<=selected[3];j++){

printf("%d ",m[i][j]);

}

printf("\n");
}
  printf("\n");  }

   return;  }



for(int i=index;i<c;i++){

selected[size]=i;

comb_cols(m,r,c,i+1,size+1,selected);

}


 }


void comb_rows(int** m, int r, int c,int index,int size,int* selected){
if(size==2){
comb_cols(m,r,c,0,size,selected);
return;}

for(int i=index;i<r;i++){
selected[size]=i;
comb_rows(m,r,c,i+1,size+1,selected);


}
}
void valid_rectangle(int** M,int R, int C ){
if(M==NULL) return;
int* selected=(int*)malloc(4*sizeof(int));
if (selected==NULL) return;
comb_rows(M,R,C,0,0,selected);
free(selected);


}

/*I used a dynamically allocated array to save four corners of the rectangle then i wanted to find all row combinations by a recursive function and for every two rows find we will also search recursively for colum combinations when we find four point we check the equality if it matched we print.*/