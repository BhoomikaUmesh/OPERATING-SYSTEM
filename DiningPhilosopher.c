#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#define num_philosophers 5
#define num_chopsticks 5
void dine(int n);
pthread_t philosopher[num_philosophers];
pthread_mutex_t chopstick[num_chopsticks];

int main()
{
    //define counter var i and status_message
    int i, status_message;
    void *msg;
    //initialize the semaphore array
    for(i=1;i<num_chopsticks;i++)
    {
        status_message=pthread_mutex_init(&chopstick[i],NULL);
        //checkl if the mutex is initialized successfully
        if(status_message==-1)
        {
            printf("\n Mutex initialization failed");
            exit(1);
        }
    }
    //run the philosopher threads using *dine() function
    for(i=1;i<=num_philosophers;i++)
    {
        status_message=pthread_create(&philosopher[i],NULL,(void*)dine,(int*)i);
        if(status_message!=0)
        {
            printf("\n Thread creation error\n");
            exit(1);
        }
    }
    //wait for all philosopher threads to complete executing (finish dining) before closing the program
    for(i=1;i<num_philosopher[i];i++)
    {
        status_message=pthread_join(philosopher[i],&msg);
        if(status_message!=0)
        {
        printf("\n Thread join failed\n");
        exit(1);
        }

    }
    for(i=1;i<=num_chopsticks;i++)
    {
        status_message=pthread_mutex_destroy(&chopstick[i]);
        if(status_message!=0)
        {
            printf("\n mutex destroyed\n");
            exit(1);
        }
    }
    return 0;
}
void dine(int n)
{
    printf("\n Philosopher %d is thinking",n);
    //philosopher picks up the left chopstick(wait)
    pthread_mutex_lock(&chopstick[n]);
    //philosopher picks up the right chopstick(wait)
    pthread_mutex_lock(&chopstick[(n+1)%num_chopsticks]);
    //after picking up both the chopstick philosopher starts eating
    printf("\n Philosopher %d is eating",n);
    sleep(3);
    pthread_mutex_unlock(&chopstick[n]);
    pthread_mutex_unlock(&chopstick[n+1%num_chopsticks]);
    printf("\nPhilosopher %d finished eating",n);
}