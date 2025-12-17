CC=gcc
CFLAGS=-Wall -pthread -Iinclude

OBJ=src/main.o src/booking.o src/file_ops.o src/thread_ops.o

train: $(OBJ)
	$(CC) $(CFLAGS) -o train $(OBJ)

clean:
	rm -f src/*.o train
