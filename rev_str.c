#include <stdio.h>

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
    char buffer[6];

    printf("The string before reversal is: %s\n", string);

    revstr1(string, buffer, sizeof(string));

    printf("The string after reversal is: %s\n", buffer);

    return 0;
}

void revstr1(const char *str, char *output, size_t size) {
    size_t length = str_len(str);

    if (length + 1 > size) {
        fprintf(stderr, "ERROR: The passed size is invalid\n");
        return;
    }

    for (size_t i = 0, j = length - 1; i < length; i ++, j --) {
        output[i] = str[j];
    }

    output[length] = '\0';
}

int strcomp(const char *str1, const char *str2) {
    while (*str1 && *str1 == *str2) {
        str1 ++;
        str2 ++;
    }

    return *str1 - *str2;
}

size_t str_len(const char *str) {
    size_t length;
    int i = 0;

    while (strcomp(&str[i], "\0")) {
        length ++;
        i ++;
    }

    return length;
}
