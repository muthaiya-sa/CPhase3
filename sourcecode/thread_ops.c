#include <stdio.h>
#include <pthread.h>

void* check_seat(void *arg) {
    printf("Seats Available\n");
    pthread_exit(NULL);
}
