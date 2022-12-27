#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>

#define Cars 10

sem_t wait;
sem_t point;

void *northsouth(void *total);
void *eastwest(void *total);

int main(int argc, char *argv[])
{
	int i, wn, we, totalcars;
	int nor[Cars];
    int east[Cars];
    pthread_t tidn[Cars];
    pthread_t tide[Cars];
    
    printf("Enter the no of cars in north region : ");
    scanf("%d", &wn);
    printf("Enter the no of cars in east region : ");
    scanf("%d", &we);
    
    totalcars = wn + we;
    
    if (Cars < totalcars)
    {
        printf("the limit exceded");
        return 0;
    }
   
    
	for (i = 0; i < wn; i++)
    {
        nor[i] = i;
    }
    for (i = 0; i < we; i++)
    {
        east[i] = i;
    }
    
	sem_init(&wait, 1, totalcars);
    sem_init(&point, 1, 3);
    
	for (i = 0; i < wn; i++)
    {
        pthread_create(&tidn[i], NULL, northsouth, (void *)&nor[i]);
    }
    for (i = 0; i < we; i++)
    {
        pthread_create(&tide[i], NULL, eastwest, (void *)&east[i]);
    }
    
	for (i = 0; i < wn; i++)
    {
        pthread_join(tidn[i], NULL);
    }

    for (i = 0; i < we; i++)
    {
        pthread_join(tide[i], NULL);
    }
    
	printf("No Cars have been left\n");
    return 0;
}

void *northsouth(void *num)
{
    int total = *(int *)num;
    printf("Car %d from north leaving from home \n", total + 1);
    sem_wait(&wait);
    int n;
    n = rand() % 10;
    sleep(n);
    printf("Car %d from north approached point area at teen talwar\n", total + 1);
    sem_wait(&point);
    sem_post(&wait);
    printf("Car %d from north entered point area at teen talwar \n", total + 1);
    sem_post(&point);
    printf("Car %d has exited towards south \n", total + 1);
}

void *eastwest(void *num)
{
    int total = *(int *)num;
    printf("Car %d from east leaving from home \n", total + 1);
    sem_wait(&wait);
    int k;
    k = rand() % 10;
    sleep(k);
    printf("Car %d from east approached point area at teen talwar \n", total + 1);
    sem_wait(&point);
    sem_post(&wait);
    printf("Car %d from east entered point area at teen talwar \n", total + 1);
    sem_post(&point);
    printf("Car %d has exited towards west \n", total + 1);
}
