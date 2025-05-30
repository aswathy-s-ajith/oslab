#include <stdio.h>
#include <stdlib.h>

#define size 100
int main(){
    int n,request[size],num;
    printf("enter the number of requests:\n");
    scanf("%d",&n);
    if(n<=0 || n>size){
        printf("invalid");
    }
    printf("enter disk request:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&request[i]);
    }
    int total=0,current=0,seek;
    for(int i=0;i<n;i++){
        int seek=abs(current-request[i]);
        current=request[i];
        total+=seek;
        
    }
    printf("total : %d\n",total);
}