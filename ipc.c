#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SHM_SIZE 1024

int main(){
    char *shm,*ptr;
    key_t key=ftok("shmfile.txt",'R');
    int shmid=shmget(key,SHM_SIZE,IPC_CREAT|0666);
    shm=shmat(shmid,NULL,0);

    ptr=shm;
    sprintf(ptr,"this is data");
    printf("data written successfully");
    ptr=shm;
    while(*ptr!='\0'){
        printf("%c",*ptr);
        ptr++;
    }
    printf("data read successfully");

    shmdt(shm);
    shmclt(shmid,IPC_RMID,NULL);

}