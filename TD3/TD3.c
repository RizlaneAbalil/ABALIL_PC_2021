#include <windows.h>
//#include<pthread.h>
#include <Pthread.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>


int Val;

void *Inc()
{
     for(int i=0; i<10000; i++)
     {
             Val++;
    }

}

void *Dec()
{
     for(int i=0; i<10000; i++)
     {
             Val--;
}
}

void main(void)
{
     Val = 0;
     pthread_t tacheInc, tacheDec;
     pthread_create(&tacheInc, NULL, Inc, NULL);
     //pthread_join(tacheInc, NULL);

     pthread_create(&tacheDec, NULL, Dec, NULL);
     pthread_join(tacheInc, NULL);
     pthread_join(tacheDec, NULL);
}

