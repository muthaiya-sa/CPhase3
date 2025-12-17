#include <stdio.h>
#include <stdlib.h>
#include "booking.h"

/* STATIC TRAIN DATA */
static Train trains[] = {
    {1001, "Rajdhani Express", "Delhi", "Mumbai", 40},
    {1002, "Shatabdi Express", "Mumbai", "Chandigarh", 60},
    {1003, "Garib Rath", "Goa", "Chennai", 45},
    {1004, "Duronto Express", "Delhi", "Goa", 50},
    {1005, "Goa Express", "Chennai", "Delhi", 55}
};

static int train_count = 5;


/* STORAGE CLASS */
int global_ticket_counter = 0;

/* FILE FUNCTION */
void save_ticket(Ticket *t);
int find_train(int train_no) {
    for (int i = 0; i < train_count; i++) {
        if (trains[i].train_no == train_no)
            return i;
    }
    return -1;
}

void book_ticket() {
    Ticket *t = (Ticket *)malloc(sizeof(Ticket));
    int train_no, seats, index;

    if (!t) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter Train ID: ");
    scanf("%d", &train_no);

    index = find_train(train_no);

    if (index == -1) {
        printf("Invalid Train ID\n");
        free(t);
        return;
    }

    printf("Enter Number of Seats: ");
    scanf("%d", &seats);

    if (seats > trains[index].seats) {
        printf("Not enough seats available\n");
        free(t);
        return;
    }

    printf("Enter Name: ");
    scanf("%s", t->passenger.name);

    printf("Enter Age: ");
    scanf("%d", &t->passenger.age);

    trains[index].seats -= seats;

    t->ticket_id = ++global_ticket_counter;
    t->train_no = train_no;
    t->seats_booked = seats;
    t->status = CONFIRMED;

    save_ticket(t);

    printf("BOOKING CONFIRMED\n");
    printf("Ticket ID: %d\n", t->ticket_id);
    printf("Train ID: %d\n", train_no);
    printf("Seats Booked: %d\n", seats);

    free(t);
}

void view_trains() {
    int i;

    printf("\nAVAILABLE TRAINS\n");
    printf("-------------------------------------------------------------\n");
    printf("Train No | Train Name         | From        | To          | Seats\n");
    printf("-------------------------------------------------------------\n");

    for (i = 0; i < train_count; i++) {
        printf("%7d | %-18s | %-11s | %-11s | %d\n",
               trains[i].train_no,
               trains[i].name,
               trains[i].from,
               trains[i].to,
               trains[i].seats);
    }

    printf("-------------------------------------------------------------\n");
}
