#include <stdio.h>

int main()
{
	char *s1;
	s1 = "hello";
	char *s2 = (char *)s1;
	s2[0] = 'x';
	printf("%s\n", s2);
}
