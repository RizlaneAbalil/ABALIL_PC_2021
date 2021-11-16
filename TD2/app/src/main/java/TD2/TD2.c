#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define PHRASE1 "Souvent, pour s’amuser, les hommes d’équipage\n"
#define PHRASE2  "Prennent des goélands, vastes oiseaux des mers,\n"
#define PHRASE3  "Qui suivent, indolents compagnons de voyage,\n"
#define PHRASE4  "Le navire glissant sur les gouffres amers.\n"


void main1(void)
{
    printf(PHRASE1);
    printf(PHRASE2);
    printf(PHRASE3);
    printf(PHRASE4);
}
void aff_T(void *mess)
{
    char *s = (char *)mess;
    printf("%s", s);   
}
void main2(void)
{
    pthread_t T1, T2, T3, T4;

    pthread_create(&T1, NULL, aff_T, PHRASE1);
    sleep(1);// OU uslepp(1) pour des microsecondes

    pthread_create(&T2, NULL, aff_T, PHRASE2);
    sleep(1);

    pthread_create(&T3, NULL, aff_T, PHRASE3);
    sleep(1);

    pthread_create(&T4, NULL, aff_T, PHRASE4);
    sleep(1);
}

void main3(void)
{
    pthread_t T1, T2, T3, T4;

    pthread_create(&T1, NULL, aff_T, PHRASE1)
    pthread_join(T1, NULL);

    pthread_create(&T2, NULL, aff_T, PHRASE2)
    pthread_join(T2, NULL);

    pthread_create(&T3, NULL, aff_T, PHRASE3)
    pthread_join(T3, NULL);

    pthread_create(&T4, NULL, aff_T, PHRASE4)
    pthread_join(T4, NULL);
}

void main(void)
{
    main1();
    main2();
    main3();
}
