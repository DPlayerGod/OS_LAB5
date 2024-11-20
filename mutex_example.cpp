//writefile mutex_example.cpp

#include <pthread.h>
#include <stdio.h>

int x = 0; // Bien toan cuc, duoc chia se giua A va B
pthread_mutex_t mut; // Khai bao mutex toan cuc

void *ProcessA(void *message)
{
    while(1)
    {
        // pthread_mutex_lock(&mut); // Lock mutex hay acquire
        x = x + 1;
        if (x == 20)
            x = 0;
        printf("Process A | x = %d\n", x);
        // pthread_mutex_unlock(&mut); // Unlock mutex hay release
    }
}

void *ProcessB(void *message)
{
    while(1)
    {
        // pthread_mutex_lock(&mut); // Lock mutex
        x = x + 1;
        if (x == 20)
            x = 0;
        printf("Process B | x = %d\n", x);
        // pthread_mutex_unlock(&mut); // Unlock mutex
    }
}

int main()
{
    pthread_t idthreadA, idthreadB;
    pthread_mutex_init(&mut, NULL); // Khoi tao mutex

    pthread_create(
        &idthreadA,
        NULL,
        &ProcessA,
        NULL
    );

    pthread_create(
        &idthreadB,
        NULL,
        &ProcessB,
        NULL
    );

    while(1){}

    return 0;
}