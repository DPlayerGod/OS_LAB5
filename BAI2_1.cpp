/*######################################
# University of Information Technology
# IT007 Operating System
#
# <Dang Quoc Cuong>, <23520192>
# File: BAI2.cpp not synchronized
#
######################################*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int i = 0, a[100], n;

void *processA(void *arr) {
    while (1) {
        int temp = rand() % 100; // Sinh so ngau nhien
        a[++i] = temp; // Them vao mang

        printf("\nThem vao mang: %d", temp);
        printf("\nKich thuoc mang a la: %d\n", i);

        for (int k = 0; k < i; k++) {
            printf("%d ", a[k]); // In cac phan tu trong mang
        }
        printf("\n");
    }
}

void *processB(void *arr) {
    while (1) {
        if (i <= 0) {
            printf("\nNothing in array a\n");
            continue;
        }

        printf("\nLoai khoi mang: %d", a[i - 1]); // Lay phan tu cuoi
        i--; // Giam chi so i
        printf("\nKich thuoc mang a la: %d\n", i);

        for (int k = 0; k < i; k++) {
            printf("%d ", a[k]); // In cac phan tu trong mang
        }
        printf("\n");
    }
}

int main() {
    printf("Nhap so phan tu: ");
    scanf("%d", &n);

    pthread_t pA, pB;
    pthread_create(&pA, NULL, &processA, NULL); // Tao luong A
    pthread_create(&pB, NULL, &processB, NULL); // Tao luong B

    while (1) {
        // Chuong trinh chay lien tuc
    }

    return 0;
}
