#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

int products = 0, sells = 0; // Bien toan cuc, duoc chia se giua A va B
sem_t stock; // Khai bao semaphore la toan cuc

void *Produce(void *message)
{
    while(1)
    {
        products++;
        printf("Produce | products = %d\n", products);
        sem_post(&stock); // Thao tac signal semaphore
    }
}

void *Consume(void *message)
{
    while(1)
    {
        sem_wait(&stock); // Thao tac wait semaphore
        sells++;
        printf("Consume | sells = %d\n", sells);
    }
}

int main()
{
    pthread_t idthreadA, idthreadB;
    sem_init(&stock, 0, products - sells); // Gia tri khoi tao cua stock la products - sells

    pthread_create(
        &idthreadA,
        NULL,
        &Produce,
        NULL
    );

    pthread_create(
        &idthreadB,
        NULL,
        &Consume,
        NULL
    );

    while(1){} // Giữ cho tiểu trình main tồn tại để quan sát idthreadA và idthreadB

    return 0;
}