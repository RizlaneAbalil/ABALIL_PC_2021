#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define N 10

pthread_mutex_t Tmutex[N];
pthread_t Tthread[N];
int val_partage;

void *f(void *x)
{
    int id;
    id = *(int *)x;
    pthread_mutex_lock(&(Tmutex[id]));
    //printf("%d%c ", id, Tchar[id]);
    val_partage++;
    //On veut afficher la valeur e la dernière tâche
    if (id < N-1)
        pthread_mutex_unlock(&(Tmutex[id+1])); //Je fais un signal
    else
        printf("%d ", val_partage);
    return NULL;
}

int main(void)
{
    int i;
    val_partage=0;
    printf("val_partage");
    scanf("%d", &val_partage);

    for (i = 0; i < N; i++)
    {
        pthread_mutex_init(&(Tmutex[i]), NULL);
        pthread_mutex_lock(&(Tmutex[i]));
        int *val = (int *)malloc(sizeof(int));
        *val = i;
        pthread_create(&(Tthread[i]), NULL, f, (void *)val);
    }
    pthread_mutex_unlock(&(Tmutex[0]));
    for (i = 0; i < N; i++)
    {
        pthread_join(Tthread[i], NULL);
    }
    printf("\n");
    return 0;
}
