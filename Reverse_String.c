#include <stdio.h>
#include <string.h>

/*
 * This function takes in a constant pointer to the passed argument,
 * it also requires the user to pass a buffer to store the string,
 * it also requires the size of the passed string.
 * */
void revstr1(const char *str, char *output, size_t size);

/*
 * This function below takes a constant pointer to the passed argument,
 * it then returns a reference pointer to a static buffer created by the
 * function to store the reversed string, it's vulnerable to many things.
 * */
char *revstr2(const char *str);

// Other nessecary functions as I am avoiding library function for learning.
int strcomp(const char *str1, const char *str2);
size_t str_len(const char *str);

int main() {
	char string[6] = "hello";
	char buffer[7];

	printf("The string before reversal is: %s\n", string);

	revstr1(string, buffer, sizeof(string));

	printf("The string after reversal is: %s\n", buffer);

	//    printf("The string before reversal via fn2 is: %s\n", string);
	//
	//    char *p = revstr2(string);
	//
	//    printf("The string after reversal via fn2 is: %p\n", *p);

	return 0;
}

void revstr1(const char *str, char *output, size_t size) {
	size_t length = strlen(str);

	if(length + 1 > size) {
		fprintf(stderr, "ERROR: The passed size is invalid\n");
		return;
	}

	if(length != 0) {
		for(size_t i = 0, j = length - 1; i < length; i++, j--) {
			output[i] = str[j];
		}
	} else {
		fprintf(stderr, "ERROR: The string passed is empty");
		return;
	}

	output[length] = '\0';
}

char *revstr2(const char *str) {
	static char *buffer;
	size_t length = str_len(str);

	if (length > 0) {
		for(size_t i = length - 1, j = 0; i <= length; i--) {
			buffer[j] = str[i];
		}
	} else {
		fprintf(stderr, "ERROR: The string passed is empty");
	}

	return buffer;
}

int strcomp(const char *str1, const char *str2) {
	while(*str1 && *str1 == *str2) {
		str1++;
		str2++;
	}

	return *str1 - *str2;
}

size_t str_len(const char str) {
	size_t length = 0;
	int i = 0;

	while(strcomp(&str[i], '\0')) {
		length++;
		i++;
	}

	return length;
}
