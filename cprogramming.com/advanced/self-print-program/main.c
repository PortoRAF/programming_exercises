#include <stdio.h>

int main (void)
{
	char c;
	FILE *fp = fopen(__FILE__, "r");

	while (c != EOF)
	{
		c = fgetc(fp);
		printf("%c", c);
	}
	
	fclose(fp);

	return 0;
}
