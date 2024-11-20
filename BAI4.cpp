/*######################################
# University of Information Technology
# IT007 Operating System
#
# <Dang Quoc Cuong>, <23520192>
# File: BAI4.cpp (synchronized)
#
######################################*/
#include <semaphore.h>
#include <stdio.h>
#include <pthread.h>

int x = 0; // Bien toan cuc
pthread_mutex_t lock; // Mutex de dong bo

void *processA(void *mess) {
    while (1) {
        pthread_mutex_lock(&lock); // Khoa mutex de tranh xung dot

        x = x + 1; // Tang x
        if (x == 20) {
            x = 0; // Reset x ve 0 neu x bang 20
        }
        printf("A = %d\n", x); // In gia tri x

        pthread_mutex_unlock(&lock); // Mo khoa mutex
    }
}

void *processB(void *mess) {
    while (1) {
        pthread_mutex_lock(&lock); // Khoa mutex de tranh xung dot

        x = x + 1; // Tang x
        if (x == 20) {
            x = 0; // Reset x ve 0 neu x bang 20
        }
        printf("B = %d\n", x); // In gia tri x

        pthread_mutex_unlock(&lock); // Mo khoa mutex
    }
}

int main() {
    pthread_t pA, pB; // Khai bao cac luong

    pthread_mutex_init(&lock, NULL); // Khoi tao mutex

    pthread_create(&pA, NULL, &processA, NULL); // Tao luong A
    pthread_create(&pB, NULL, &processB, NULL); // Tao luong B

    while (1) {
        // Chuong trinh chay vo han
    }

    pthread_mutex_destroy(&lock); // Huy mutex khi ket thuc
    return 0;
}
