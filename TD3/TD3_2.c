#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>

int Val; 

void *Inc()
{
     for(int i=0; i<10000; i++
     {
             Val++; 
}

}

void *Dec()
{
     for(int i=0; i<10000; i++
     {
             Val--; 
}
}

void main(void)
{
     Val = 0; 
     pthread_t tacheInc, tacheDec; 
     sem_t semInc, semDec; 
     
     sem_wait(&semInc);
     pthread_create(&tacheInc, NULL, Inc, NULL);
     //pthread_join(tacheInc, NULL); 
     sem_post(&semInc);
     
     sem_wait(&semDec);
     pthread_create(&tacheDec, NULL, Dec, NULL);
     sem_post(&semDec);
     
     pthread_join(tacheInc, NULL); 
     pthread_join(tacheDe, NULL); 
}     
     
