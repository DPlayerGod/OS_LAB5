//writefile thread_args.cpp

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct print_params
{
    char character;
    int count;
};

void *char_print(void* args)
{
    struct print_params *p = (struct print_params *)args;
    int i;

    for (i = 0; i < p->count; i++)
        printf("%c\n", p->character);

    return NULL;
}

int main()
{
    pthread_t tid;
    struct print_params th_args;

    th_args.character = 'A';
    th_args.count = 3;

    pthread_create(
        &tid,
        NULL,
        &char_print,
        &th_args
    );

    pthread_join(tid, NULL);

    pthread_exit(NULL);
    return 0;
}