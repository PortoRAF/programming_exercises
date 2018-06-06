#include <stdio.h>
#include <stdlib.h>

int calc_str_len (char *str)
{
	int str_len = 0;
	
	while (str[str_len] != '\000')
	{
		str_len++;
	}

	return str_len;
}

int main (int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("usage: %s string substring\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	int first_str_len  = calc_str_len(argv[1]);
	int second_str_len = calc_str_len(argv[2]);

	if (second_str_len > first_str_len)
	{
		printf("Second string is larger than the first.\n");
		exit(EXIT_FAILURE);
	}



	return 0;
}
