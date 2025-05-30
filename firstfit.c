#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int size;
    int status;
    struct node *next;
}node;
node* head=NULL ;

void create(int block[],int m){
    head=(node*)malloc(sizeof(node));
    head->size=block[0];
    head->status=0;
    head->next=NULL;
    node * temp=head;
    for (int i=1;i<m;i++){
        node *new=(node*)malloc(sizeof(node));
        new->size=block[i];
        new->status=0;
        new->next=NULL;
        temp->next=new;
        temp=new;
    }
}

void display(){
    node *temp=head;
    while(temp!=NULL){
        printf("%d  :   %d\n",temp->size , temp->status?"allocated" : "free");
        temp=temp->next;
    }
}

void firstfit(int process[],int n){
    int number=1;
    for(int i=0;i<n;i++){
        node *temp=head;
        while(temp!=NULL){
            if (temp->size>=process[i]&&temp->status==0){
                temp->status=1;
                temp->size-=process[i];
                printf("%d allocated to block %d\n",process[i],number);

            }
            temp=temp->next;
            number++;
        }
        if (temp==NULL){
            printf("%d  not allocated\n",process[i]);
        }
    }
    
}

void worstfit(int process[],int n){
    int blocknumber=1,worsnum;
    for (int i=0;i<n;i++){
        node*temp=head;
        node*worstblock=NULL;
        while(temp!=NULL){
            if(temp->size>=process[i]&& temp->status==0){
                if(worstblock==NULL || temp->size>worstblock->size){
                    worstblock=temp;
                    worsnum=blocknumber;      
                }
            }
            temp=temp->next;
            blocknumber++;
        }
        if(worstblock==NULL){
            printf("%d not allocated ",process[i]);
        }
        else{
            printf("%d allocated to block %d\n",process[i],worsnum);
            worstblock->status=1;
            worstblock->size-=process[i];
        }
    }
}

void bestfit(int process[],int n){
    int blocknumber=1,bestnum;
    for (int i=0;i<n;i++){
        node*temp=head;
        node*bestblock=NULL;
        while(temp!=NULL){
            if(temp->size>=process[i]&& temp->status==0){
                if(bestblock==NULL || temp->size<bestblock->size){
                    bestblock=temp;
                    bestnum=blocknumber;      
                }
            }
            temp=temp->next;
            blocknumber++;
        }
        if(bestblock==NULL){
            printf("%d not allocated ",process[i]);
        }
        else{
            printf("%d allocated to block %d\n",process[i],bestnum);
            bestblock->status=1;
            bestblock->size-=process[i];
        }
    }
}



int main(){
    int m, n;
    int block[10],process[10];
    printf("enter number of blocks:");
    scanf("%d",&m);
    for (int i=0;i<m;i++){
        scanf("\nenter block%d",&block[i]);
    }
    printf("enter no of processes:");
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&process[i]);
    }
    create(block,m);
    display();
    firstfit(process,n);
    display();


}