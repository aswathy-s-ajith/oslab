#include  <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#define BUFFER 5

int buffer[BUFFER];
sem_t empty,full;
pthread_mutex_t mutex;
int in=0,out=0;

void *producer(void *args){
    int item=1;
    while(1){
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        buffer[in]=item;
        printf("Produced item:%d\n",item);
        in=(in+1)%BUFFER;
        item++;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}

void *consumer(void *args){
    while(1){
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        int item=buffer[out];
        out=(out+1)%BUFFER;
        printf("consumed item:%d\n",item);
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}

int main(){
    sem_init(&empty,0,BUFFER);
    sem_init(&full,0,0);
    pthread_mutex_init(&mutex,NULL);
    
    pthread_t producer_thread,consumer_thread;
    
    pthread_create(&producer_thread,NULL,producer,NULL);
    pthread_create(&consumer_thread,NULL,consumer,NULL);
    
    pthread_join(producer_thread,NULL);
    pthread_join(consumer_thread,NULL);
    
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);
}
    
    
    
