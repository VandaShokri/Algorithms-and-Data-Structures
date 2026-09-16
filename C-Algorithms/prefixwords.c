#include <stdio.h>
#include <stdlib.h>
#define max 20

int search_word(char* s1,char* s2,int k,int j){
int i=0,found=0,flag=0;
if(s1==NULL || s2==NULL) return 0;
while(s1[i]!='\0' && s2[i]!='\0'){
if(s1[i]!=s2[i]){ break;}
i++;
} 
if(s1[i]=='\0' && i>0 ){
printf("strings[%d]:%s is a prefix of strings[%d]:%s \n",k,s1,j,s2); 
flag=1;

}
if(s2[i]=='\0' && i>0 ){
printf("strings[%d]:%s is a prefix of strings[%d]:%s \n",j,s2,k,s1);
flag=1; }
return flag;
}

void detect_prefix_collision (char **strings, int n){
int flag=0,result=0;
for(int i=0;i<n-1;i++){

   for(int j=i+1;j<n;j++){
  result= search_word(strings[i],strings[j],i,j);
  if(flag==0 && result==1) flag=1;
}
   }
if(flag==0){
printf("no prefix found");}



}