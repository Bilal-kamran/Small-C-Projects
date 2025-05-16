CC = gcc
CFLAGS = -Wall -Wextra -Werror -ggdb -pedantic

str-len: string_length.c
	$(CC) $(CFLAGS) -o str-len string_length.c
