#include <stdio.h>
#include "booking.h"

/* FUNCTION POINTER */
typedef void (*MenuFunc)();

int main() {
    int choice;

    MenuFunc menu[] = {
        NULL,
        view_trains,
        book_ticket,
        view_tickets
    };

    while (1) {
        printf("\n1. Available Trains");
        printf("\n2. To Book Ticket");
        printf("\n3. Booked Tickets");
        printf("\n4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            case 2:
            case 3:
                menu[choice]();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}

