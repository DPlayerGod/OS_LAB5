/*######################################
# University of Information Technology
# IT007 Operating System
#
# <Dang Quoc Cuong>, <23520192>
# File: BAI5.cpp
#
######################################*/`
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

// Bien toan cuc
int x1 = 1, x2 = 2, x3 = 3, x4 = 4, x5 = 5, x6 = 6; // Bien dau vao
int w, v, y, z, ans; // Bien trung gian va ket qua

// Semaphore dong bo hoa
sem_t sem_v, sem_y, sem_z, sem_e, sem_f, sem_g;

// Ham tinh w = x1 * x2
void *compute_w(void *arg) {
    w = x1 * x2;
    printf("w = %d (x1 * x2)\n", w);
    sem_post(&sem_e); // Mo khoa de phep tinh (e) thuc hien
    sem_post(&sem_f); // Mo khoa de phep tinh (f) thuc hien
    return NULL;
}

// Ham tinh v = x3 * x4
void *compute_v(void *arg) {
    v = x3 * x4;
    printf("v = %d (x3 * x4)\n", v);
    sem_post(&sem_y); // Mo khoa de phep tinh (c) thuc hien
    sem_post(&sem_z); // Mo khoa de phep tinh (d) thuc hien
    return NULL;
}

// Ham tinh y = v * x5
void *compute_y(void *arg) {
    sem_wait(&sem_y); // Cho v duoc tinh
    y = v * x5;
    printf("y = (v * x5) = %d\n", y);
    sem_post(&sem_e); // Mo khoa de phep tinh (e) thuc hien
    return NULL;
}

// Ham tinh z = v * x6
void *compute_z(void *arg) {
    sem_wait(&sem_z); // Cho v duoc tinh
    z = v * x6;
    printf("z = (v * x6) = %d\n", z);
    sem_post(&sem_f); // Mo khoa de phep tinh (f) thuc hien
    return NULL;
}

// Ham tinh y = w * y
void *compute_e(void *arg) {
    sem_wait(&sem_e); // Cho w duoc tinh
    sem_wait(&sem_e); // Cho y duoc tinh
    y = w * y;
    printf("y = (w * y) = %d\n", y);
    sem_post(&sem_g); // Mo khoa de phep tinh (g) thuc hien
    return NULL;
}

// Ham tinh z = w * z
void *compute_f(void *arg) {
    sem_wait(&sem_f); // Cho w duoc tinh
    sem_wait(&sem_f); // Cho z duoc tinh
    z = w * z;
    printf("z = (w * z) = %d\n", z);
    sem_post(&sem_g); // Mo khoa de phep tinh (g) thuc hien
    return NULL;
}

// Ham tinh ans = y + z
void *compute_g(void *arg) {
    sem_wait(&sem_g); // Cho y duoc tinh
    sem_wait(&sem_g); // Cho z duoc tinh
    ans = y + z;
    printf("ans = %d (y + z)\n", ans);
    return NULL;
}

int main() {
    pthread_t t_w, t_v, t_y, t_z, t_e, t_f, t_g;

    // In ra cac bien dau vao
    printf("x1 = %d, x2 = %d, x3 = %d, x4 = %d, x5 = %d, x6 = %d\n", x1, x2, x3, x4, x5, x6);

    // Khoi tao semaphore
    sem_init(&sem_v, 0, 0);
    sem_init(&sem_y, 0, 0);
    sem_init(&sem_z, 0, 0);
    sem_init(&sem_e, 0, 0);
    sem_init(&sem_f, 0, 0);
    sem_init(&sem_g, 0, 0);

    // Tao cac thread
    pthread_create(&t_w, NULL, compute_w, NULL);
    pthread_create(&t_v, NULL, compute_v, NULL);
    pthread_create(&t_y, NULL, compute_y, NULL);
    pthread_create(&t_z, NULL, compute_z, NULL);
    pthread_create(&t_e, NULL, compute_e, NULL);
    pthread_create(&t_f, NULL, compute_f, NULL);
    pthread_create(&t_g, NULL, compute_g, NULL);

    // Cho cac thread ket thuc
    pthread_join(t_w, NULL);
    pthread_join(t_v, NULL);
    pthread_join(t_y, NULL);
    pthread_join(t_z, NULL);
    pthread_join(t_e, NULL);
    pthread_join(t_f, NULL);
    pthread_join(t_g, NULL);

    // Huy semaphore
    sem_destroy(&sem_v);
    sem_destroy(&sem_y);
    sem_destroy(&sem_z);
    sem_destroy(&sem_e);
    sem_destroy(&sem_f);
    sem_destroy(&sem_g);

    // In ket qua cuoi cung
    printf("Ket qua cuoi cung: y = %d, z = %d, ans = %d\n", y, z, ans);

    return 0;
}
