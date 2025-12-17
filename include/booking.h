#ifndef BOOKING_H
#define BOOKING_H

/* ENUM */
typedef enum {
    BOOK = 1,
    VIEW,
    EXIT
} MenuOption;

/* ENUM */
typedef enum {
    CONFIRMED,
    CANCELLED
} TicketStatus;

/* STRUCT */
typedef struct {
    char name[20];
    int age;
} Passenger;

/* STRUCT */
typedef struct {
    int ticket_id;
    int train_no;
    int seats_booked;
    Passenger passenger;
    TicketStatus status;
} Ticket;

/* STRUCT FOR TRAIN */
typedef struct {
    int train_no;
    char name[30];
    char from[20];
    char to[20];
    int seats;
} Train;

/* UNION */
typedef union {
    int upi_id;
    long card_no;
} Payment;

/* EXTERN */
extern int global_ticket_counter;

/* FUNCTION DECLARATIONS */
void book_ticket();
void view_tickets();
void view_trains();   // ⭐ THIS WAS MISSING OR NOT SEEN

#endif

