CC = gcc
CFLAGS = -Wall -Wextra -Werror -ggdb -pedantic

revstr: Reverse_String.c
	$(CC) $(CFLAGS) -o revstr Reverse_String.c
