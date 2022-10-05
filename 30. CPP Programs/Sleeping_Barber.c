#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <time.h>
#include <sys/types.h>
#include <sys/time.h>
void *barber_function(void *idp);
void *customer_function(void *idp);
void service_customer();
void *make_customer_function();
/* Mutex*/
pthread_mutex_t srvCust;
/* Semaphores */
sem_t barber_ready;
sem_t customer_ready;
sem_t modifySeats;
/* Inputs */
int chair_cnt;
int total_custs;
int available_seats;
int no_served_custs = 0;
time_t waiting_time_sum;
void *barber_function(void *idp)
{
int counter = 0;
while (1)
{
/* Lock semaphore "customer_ready" - try to get a customer or sleep if there is none */
sem_wait(&customer_ready);
/* Lock semaphore "modifySeats" - try to get access to seats */
sem_wait(&modifySeats);
/* Increment by 1 the available seats */
available_seats++;
/* Unlock semaphore "modifySeats" */
sem_post(&modifySeats);
/*Unlock semaphore "barber_ready" - set barber ready to serve" */
sem_post(&barber_ready);
/* Lock mutex "srvCust - protect service from the same barber from other threads */
pthread_mutex_lock(&srvCust);
/* serve customer */
service_customer();
/* Unlock mutex "srvCust - finished service */
pthread_mutex_unlock(&srvCust);
printf("Customer was served.\n");
counter++;
if (counter == (total_custs - no_served_custs))
break;
}
pthread_exit(NULL);
}
void *customer_function(void *idp)
{
struct timeval start, stop;
/* Lock semaphore "modifySeats" */
sem_wait(&modifySeats);
/* If there is available seat*/
if (available_seats >= 1)
{
/* Occupy a seat*/
available_seats--;
printf("Customer[pid = %lu] is waiting.\n", pthread_self());
printf("Available seats: %d\n", available_seats);
/* Start waiting-time counter */
gettimeofday(&start, NULL);
/* Unlock semaphore "customer_ready" - set the customer ready to be served */
sem_post(&customer_ready);
/* Unlock semaphore "modifySeats" */
sem_post(&modifySeats);
/* Lock semaphore "barber_ready" - wait for barber to get ready */
sem_wait(&barber_ready);
/* Stop waiting-time counter */
gettimeofday(&stop, NULL);
double sec = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec -
start.tv_sec);
/* Assigning the time spent to global variable (ms)*/
waiting_time_sum += 1000 * sec;
printf("Customer[pid = %lu] is being served. \n", pthread_self());
}
else
{
/* Unlock semaphore "modifySeats" */
sem_post(&modifySeats);
no_served_custs++;
printf("A Customer left.\n");
}
pthread_exit(NULL);
}
void service_customer()
{
int s = rand() % 401; /* Random number between 0 and 400 (miliseconds)*/
s = s * 1000; /* Convert miliseconds to microseconds*/
usleep(s);
}
void *make_customer_function()
{
int tmp;
int counter = 0;
while (counter < total_custs)
{
/* Declare and create a customer thread */
pthread_t customer_thread;
tmp = pthread_create(&customer_thread, NULL, (void *)customer_function, NULL);
if (tmp)
printf("Failed to create thread.");
/* Increment the counter */
counter++;
/* Sleep for 100ms before creating another customer */
usleep(100000);
}
}
int main()
{
/* Initialization, should only be called once. */
srand(time(NULL));
/* Barber 1 thread */
pthread_t barber_1;
/* Thread that creates customers */
pthread_t customer_maker;
int tmp;
/* Initialize the mutex */
pthread_mutex_init(&srvCust, NULL);
/* Initialize semaphores */
sem_init(&customer_ready, 0, 0);
sem_init(&barber_ready, 0, 0);
sem_init(&modifySeats, 0, 1);
printf("Please enter the number of seats: \n");
scanf("%d", &chair_cnt);
printf("Please enter the total customers: \n");
scanf("%d", &total_custs);
available_seats = chair_cnt;
/* Create barber thread*/
tmp = pthread_create(&barber_1, NULL, (void *)barber_function, NULL);
if (tmp)
printf("Failed to create thread.");
/* Create customer_maker thread*/
tmp = pthread_create(&customer_maker, NULL, (void *)make_customer_function, NULL);
if (tmp)
printf("Failed to create thread.");
/* Wait for threads to finish */
pthread_join(barber_1, NULL);
pthread_join(customer_maker, NULL);
printf("\n------------------------------------------------\n");
printf("Average customers' waiting time: %f ms.\n", (waiting_time_sum / (double)(total_custs -
no_served_custs)));
printf("Number of customers that were forced to leave: %d\n", no_served_custs);
}