#include <pthread.h>
#include <stdio.h>

void *thread_print(void *message)
{
    while(1)
        printf("Hello, how are you?\n");
}

int main()
{
    pthread_t idthread;

    pthread_create(
        &idthread,
        NULL,
        &thread_print,
        NULL
    );

    while(1)
        printf("I'm fine, and you?\n");

    return 0;
}