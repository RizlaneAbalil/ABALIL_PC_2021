#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#define N 10
pthread_mutex_t monMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_t tache[N];


void *aff_lettre()
{
    pthread_mutex_lock(&monMutex);

    for(char i='a'; i<='j'; i++)
    {
        printf("%c\n", i);
    }
    pthread_mutex_unlock(&monMutex);
}


void main(void)
{

    for(int i=0; i<N; i++)
    {
     pthread_create(&tache[i], NULL, aff_lettre, NULL);

    }
    for(int i=0; i<N; i++)
    {
     pthread_join(tache[i], NULL);
    }

}
