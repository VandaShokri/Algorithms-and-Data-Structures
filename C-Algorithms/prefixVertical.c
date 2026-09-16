#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 21
void find_prefix(char** string,char* prefix,int n){
    prefix[max-1]='\0';
 for(int j=0;j<max-1;j++){
        if(string[0][j]=='\0'){prefix[j]='\0'; return;}
        else{
            prefix[j]=string[0][j];
        }
    for(int i=1;i<n;i++){
        if(string[i][j]=='\0' || string[i][j]!=prefix[j] ) {prefix[j]='\0'; return;}
       } 
    }

}
void lcp (char** string,int n){
    if(string==NULL||n==0){
        printf("NULL\n");
        return;
    }
    if(n==1){
        if(string[0][0]=='\0') printf("no words.\n");
        else printf("%s\n",string[0]);
        return;
    }
    char* prefix= (char*)malloc(max*sizeof(char));
    if(prefix==NULL){
        printf("allocation error\n");
        return;
    }
    find_prefix(string,prefix,n);
    if(prefix[0]=='\0') printf("no prefix\n");
    else printf("%s\n",prefix);
    free(prefix);


    }