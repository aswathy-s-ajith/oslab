#include <stdio.h>
#include <stdlib.h>

int main(){
    typedef struct process{
        int pid;
        int arr;
        int burst;
    }process;
    process p[]={
        {1, 0, 8},
        {2, 1, 1},
        {3, 2, 3},
        {4, 3, 2},
        {5, 4, 6}
    };
    int n=sizeof(p)/sizeof(p[0]);

    for(int i=0;i<n;i++){
        for(int j=0;j=n-i-1;j++){
            if (p[j].burst>p[i+1].burst){
                process temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }

    int *wt=(int *)malloc(sizeof(int)*n);
    int *tat=(int *)malloc(sizeof(int)*n);

    wt[0]=0;
    tat[0]=p[0].burst;
    for(int i=1;i<n;i++){
        wt[i]=wt[i-1]+p[i-1].burst;
        tat[i]=wt[i]+p[i].burst;
    }
    
    
    
}