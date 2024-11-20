/*######################################
# University of Information Technology
# IT007 Operating System
#
# <Dang Quoc Cuong>, <23520192>
# File: BAI1.cpp
#
######################################*/
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

int sells = 0, products = 0; // Bien toan cuc
sem_t sem, sem1;             // Semaphore de dong bo hoa

// Luong A: Xy ly sells
void *processA(void *mess) {
    while (1) { // Vong lap vo han
        sem_wait(&sem); // Doi semaphore "sem" duoc mo
        sells++;        // Tang gia tri cua sells
        printf("SELL = %d\n", sells); // In gia tri cua sells
        printf("SELL_1 (SELL + 192) = %d\n", sells + 192); // In SELL + 192
        sem_post(&sem1); // Mo semaphore "sem1" de luong B chay
        //usleep(100000);  // Nghi 0.1 giay de giam tai CPU
    }
    return NULL;
}

// Luong B: Xy ly products
void *processB(void *mess) {
    while (1) { // Vong lap vo han
        sem_wait(&sem1); // Doi semaphore "sem1" duoc mo
        products++;      // Tang gia tri cua products
        printf("PRODUCT = %d\n", products); // In gia tri cua products
        sem_post(&sem);  // Mo semaphore "sem" de luong A chay
        //usleep(100000);  // Nghi 0.1 giay de giam tai CPU
    }
    return NULL;
}

int main() {
    // Khoi tao semaphore
    sem_init(&sem, 0, 0);          // Khoi tao semaphore "sem", gia tri ban dau = 0
    sem_init(&sem1, 0, sells + 192); // Khoi tao semaphore "sem1", gia tri ban dau = sells + 192

    pthread_t pA, pB; // Khai bao hai luong

    // Tao hai luong
    pthread_create(&pA, NULL, processA, NULL); // Tao luong A
    pthread_create(&pB, NULL, processB, NULL); // Tao luong B

    // Vong lap chinh chay vo han
    while (1) {
        // Chuong trinh van hoat dong de cac luong chay
    }

    // Huy semaphore khi chuong trinh ket thuc
    sem_destroy(&sem);
    sem_destroy(&sem1);

    return 0;
}
