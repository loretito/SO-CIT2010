#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 5
#define NUM_TICKETS 10

int tickets_available = NUM_TICKETS;

sem_t sem_tickets;

void* buy_ticket(void* arg) {
    int id_thread = *(int*)arg;

    sem_wait(&sem_tickets);

    tickets_available--;
    printf("Thread %d compró un ticket. Tickets disponibles: %d\n", id_thread, tickets_available);

    sem_post(&sem_tickets);

    return NULL;
}

int main() {
    sem_init(&sem_tickets, 0, NUM_TICKETS);

    pthread_t threads[NUM_THREADS];
    int id_threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        id_threads[i] = i + 1;
        pthread_create(&threads[i], NULL, buy_ticket, &id_threads[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&sem_tickets);

    return 0;
}
