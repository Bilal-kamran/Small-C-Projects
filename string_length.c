#include <stdio.h>

size_t str_len (const char *str);

int main()
{
	char name[] = "bilal kamran";
	printf("The value of string is: %s\n", name);
	printf("The length of the string is: %ld\n", str_len(name));

	return 0;
}

size_t str_len(const char *str) {
	size_t length = 0;
	int i = 0;

	while (*(str + i) != '\0') {
		length++;
		i++;
	}

	return length;
}
