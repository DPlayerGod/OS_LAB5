#include <semaphore.h>
#include <stdio.h>
#include <pthread.h>

int x = 0;

void *processA(void *mess) {
    while (1) {
        x = x + 1; // Tang x
        if (x == 20) {
            x = 0; // Reset x ve 0 neu x bang 20
        }
        printf("A = %d\n", x); // In gia tri x
    }
}

void *processB(void *mess) {
    while (1) {
        x = x + 1; // Tang x
        if (x == 20) {
            x = 0; // Reset x ve 0 neu x bang 20
        }
        printf("B = %d\n", x); // In gia tri x
    }
}

int main() {
    pthread_t pA, pB; // Khai bao cac luong

    pthread_create(&pA, NULL, &processA, NULL); // Tao luong A
    pthread_create(&pB, NULL, &processB, NULL); // Tao luong B

    while (1) {
        // Chuong trinh chay vo han
    }

    return 0;
}
