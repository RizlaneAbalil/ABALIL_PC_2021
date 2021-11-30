#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define N 10

pthread_mutex_t Tmutex[N];
pthread_t Tthread[N];
char Tchar[N] = "ABCDEFGHIJ";
void *f(void *x)
{
    int id;
    id = *(int *)x;
    pthread_mutex_lock(&(Tmutex[id]));
    printf("%d%c ", id, Tchar[id]);
    if (id < N)
        pthread_mutex_unlock(&(Tmutex[id+1]));
    return NULL;
}

int main(void)
{
    for (int i = 0; i < N; i++)
    {
        pthread_mutex_init(&(Tmutex[i]), NULL);
        pthread_mutex_lock(&(Tmutex[i]));
        int *val = (int *)malloc(sizeof(int));
        *val = i;
        pthread_create(&(Tthread[i]), NULL, f, (void *)val);
    }
    pthread_mutex_unlock(&(Tmutex[0]));
    for (int i = 0; i < N; i++)
    {
        pthread_join(Tthread[i], NULL);
    }
    printf("\n");
    return 0;
}