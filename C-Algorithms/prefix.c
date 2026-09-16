#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 21

void lcp (char** string,int n){
    if(string==NULL||n==0){
        printf("NULL\n");
        return;
    }
    if(n==1){
       printf("%s\n",string[0]);
       return;
    }
    int j;
    char* prefix = (char*)malloc(max*sizeof(char));
    if(prefix==NULL) return;
    strcpy(prefix,string[0]);
   for(int i=1;i<n;i++){
    if(prefix[0]=='\0') break;
    for( j=0;string[i][j]!='\0' && prefix[j]!='\0';j++){
        if(prefix[j]!=string[i][j]){
            break;
        }
    }
    prefix[j]='\0';

}
if (prefix[0] == '\0') {
    printf("nothing matched\n");
} else {
    printf("%s\n", prefix);
}
free(prefix);


}
