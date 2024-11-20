/*######################################
# University of Information Technology
# IT007 Operating System
#
# <Dang Quoc Cuong>, <23520192>
# File: BAI2.cpp synchronized
#
######################################*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem1, sem2;
pthread_mutex_t pt1;
int i = 0, a[100], n;

void *processA(void *arr) {
    while (1) {
        sem_wait(&sem2); // Doi semaphore sem2
        pthread_mutex_lock(&pt1); // Khoa mutex de tranh xung dot

        int temp = rand() % 100; // Sinh so ngau nhien
        a[i++] = temp; // Them vao mang

        printf("\nThem vao mang: %d", temp);
        printf("\nKich thuoc mang a la: %d\n", i);

        for (int k = 0; k < i; k++) {
            printf("%d ", a[k]); // In cac phan tu trong mang
        }
        printf("\n");

        pthread_mutex_unlock(&pt1); // Mo khoa mutex
        sem_post(&sem1); // Mo semaphore sem1
    }
}

void *processB(void *arr) {
    while (1) {
        if (i <= 0) {
            printf("\nNothing in array a\n");
            continue;
        }

        sem_wait(&sem1); // Doi semaphore sem1
        pthread_mutex_lock(&pt1); // Khoa mutex de tranh xung dot

        printf("\nLoai khoi mang: %d", a[i - 1]); // Lay phan tu cuoi
        i--; // Giam chi so i
        printf("\nKich thuoc mang a la: %d\n", i);

        for (int k = 0; k < i; k++) {
            printf("%d ", a[k]); // In cac phan tu trong mang
        }
        printf("\n");

        pthread_mutex_unlock(&pt1); // Mo khoa mutex
        sem_post(&sem2); // Mo semaphore sem2
    }
}

int main() {
    printf("Nhap so phan tu: ");
    scanf("%d", &n);

    pthread_mutex_init(&pt1, NULL); // Khoi tao mutex
    sem_init(&sem1, 0, 0); // Khoi tao semaphore sem1
    sem_init(&sem2, 0, n); // Khoi tao semaphore sem2

    pthread_t pA, pB;
    pthread_create(&pA, NULL, &processA, NULL); // Tao luong A
    pthread_create(&pB, NULL, &processB, NULL); // Tao luong B

    while (1) {
        // Chuong trinh chay lien tuc
    }

    return 0;
}
