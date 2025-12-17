CC = gcc
CFLAGS = -Wall -pthread -Iinclude

OBJ = sourcecode/main.o sourcecode/booking.o sourcecode/file_ops.o sourcecode/thread_ops.o

train: $(OBJ)
	$(CC) $(CFLAGS) -o train $(OBJ)

sourcecode/%.o: sourcecode/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f sourcecode/*.o train

