#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *reorder_string (char *s1, int *v){
int n=strlen(s1);
char* s2=(char*)malloc((n+1)*sizeof(char));
if(s2==NULL) return NULL;
for(int i=0;i<n;i++){
if(v[i]<0 || v[i]>=n){ printf("error:index out of bound"); free(s2); return NULL;}
s2[v[i]]=s1[i];
}
s2[n]='\0';

return s2;

}