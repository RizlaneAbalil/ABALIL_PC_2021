#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>

sem_t semaphore1, semaphore2; 
int Val; 
pthread_mutex_t monMutex = PTHREAD_MUTEX_INITIALIZER; 

void *Inc()
{
     
     for(int i=0; i<10000; i++
     {
             sem_wait(&semaphore1);
             Val++; 
             sem_post(&semaphore1);
             /*
             p_thread_mutex_lock(&monMutex)
             Val++
             p_thread_mutex_unlock(&monMutex)
             */
}

}

void *Dec()
{
     for(int i=0; i<10000; i++
     {
             sem_wait(&semaphore2);
             Val--; 
             sem_post(&semaphore2);
             /*
             p_thread_mutex_lock(&monMutex)
             Val--
             p_thread_mutex_unlock(&monMutex)
             */
}
}

void main(void)
{
     Val = 0; 
     pthread_t tacheInc, tacheDec; 
     int sem1 = sem_init(&semaphore1, 0, 0); 
     int sem2 = sem_init(&semaphore2, 0, 0); 
     
     sem1 = pthread_create(&tacheInc, NULL, Inc, NULL);
     //pthread_join(tacheInc, NULL); 
     
     sem2 = pthread_create(&tacheDec, NULL, Dec, NULL);
     
     pthread_join(tacheInc, NULL); 
     pthread_join(tacheDe, NULL); 
}     
     
