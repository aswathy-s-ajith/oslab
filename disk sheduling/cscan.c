// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n,head,req[20],max,index,seek=0;
    printf("enter the number of req:\n");
    scanf("%d",&n);
    printf("enter request:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&req[i]);
    }
    printf("enter head position:\n");
    scanf("%d",&head);
    printf("enter max disk range:\n");
    scanf("%d",&max);
    req[n]=head;
    req[n+1]=max;
    n+=2;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(req[j]>req[j+1]){
                int temp=req[j];
                req[j]=req[j+1];
                req[j+1]=temp;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        if(req[i]==head){
            index=i;
        }
    }
    for(int i=index;i<n-1;i++){
        printf("move from %d to %d",req[i],req[i+1]);
        seek+=abs(req[i+1]-req[i]);
    }
    printf("move to 0\n");
    seek+=max;
    for(int i=0;i<index-1;i++){
        printf("move from %d to %d",req[i],req[i+1]);
        seek+=abs(req[i+1]-req[i]);
    }
    
    printf("total seek:%d\n",seek);
    printf("average seek time:%d\n",seek/(n-2));
    return 0;
}