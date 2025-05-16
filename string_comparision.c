#include <stdio.h>

int strcomp(const char *str1, const char *str2);

int main()
{
	char n1[6] = "bilal";
	char n2[6] = "bilal";
	char n3[7] = "helloo";

	if (strcomp(n1, n2) == 0)
		printf("The strings are same\n");

	if (strcomp(n1, n3) < 0)
		printf("The string2 is greater than string1\n");

	if (strcomp(n3, n1) > 0)
		printf("The string1 is greater than string2\n");

	return 0;
}

int strcomp(const char *str1, const char *str2)
{
	while (*str1 && *str1 == *str2) {
		str1++;
		str2++;
	}

	return *str1 - *str2;
}
