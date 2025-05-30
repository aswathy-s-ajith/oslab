#include <stdio.h>
#include <stdlib.h>
int main(){


typedef struct p{
    int name;
    int arrival;
    int burst;
    int compl;
    int turn;
    int wait;
}p;

p process[]={
    {1,0,24},
    {2,0,3},
    {3,0,3}
};

int n=sizeof(process)/sizeof(process[0]);

int current=0;

for(int i=0;i<n;i++){
    if (current<process[i].arrival){
        current=process[i].arrival;
    }
    
    current+=process[i].burst;
    process[i].compl=current;
    process[i].turn=process[i].compl-process[i].arrival;
    process[i].wait=process[i].turn-process[i].burst;

}

float awgwt=0,awgtat=0;
for (int i=0;i<n;i++){
    printf("%d%d%d%d%d%d\n",process[i].name,process[i].arrival,process[i].burst,process[i].compl,process[i].wait,process[i].turn);
    awgwt+=process[i].wait;
    awgtat+=process[i].turn;

}
printf("avg waiting time:%f",awgwt/n);
printf("awg turnaround time:%f",awgtat/n);

}