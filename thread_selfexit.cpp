//writefile thread_selfexit.cpp

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 2

void *thread_print(void *threadid)
{
    long tid;
    tid = (long)threadid;
    printf("Hello IT007! I'm Thread #%ld!\n", tid);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int check;
    long tID;

    for(tID = 0; tID < NUM_THREADS; tID++)
    {
        check = pthread_create(
                    &threads[tID],
                    NULL,
                    &thread_print,
                    (void *)tID
                );

        if (check != 0)
        {
            printf("[MAIN_THREAD] ERROR! Can't create Thread #%ld\n", tID);
            exit(-1);
        }
    }


    sleep(10);

    printf("[MAIN THREAD] Bye bye!\n");
    pthread_exit(NULL);
    return 0;
}