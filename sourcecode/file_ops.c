#include <stdio.h>
#include "booking.h"

void save_ticket(Ticket *t) {
    FILE *fp = fopen("data/tickets.dat", "ab");
    fwrite(t, sizeof(Ticket), 1, fp);
    fclose(fp);
}

void view_tickets() {
    FILE *fp = fopen("data/tickets.dat", "rb");
    Ticket t;

    if (!fp) {
        printf("No tickets found\n");
        return;
    }

    while (fread(&t, sizeof(Ticket), 1, fp)) {
        printf("Ticket ID:%d Train:%d Name:%s Age:%d Seats:%d\n",
       t.ticket_id,
       t.train_no,
       t.passenger.name,
       t.passenger.age,
       t.seats_booked);

    }

    fclose(fp);
}
