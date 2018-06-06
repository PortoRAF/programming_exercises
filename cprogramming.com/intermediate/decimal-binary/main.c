#include <stdio.h>
#include <stdlib.h>

#define INT_SIZE 32

int main (int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("usage: %s decimal\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	int dec = strtol(argv[1], NULL, 10);
	char bin[INT_SIZE];
	int is_neg = 0;

	if (dec < 0)
	{
		dec *= -1;
		is_neg = 1;
	}

	int bin_len = 0;
	while (dec != 0)
	{
		bin[bin_len++] = dec % 2;
		dec /= 2;
	}

	int i_print = bin_len;

	if(is_neg)
	{
		int i;
		int buf = 0;
		int carry = 1;
		for (i = 0; i < INT_SIZE; i++)
		{
			if (i >= bin_len)
			{
				bin[i] = 1;
			}
			else
			{
				buf = (bin[i] ^ 1) + carry;
				bin[i] = buf % 2;
				carry = buf / 2;
			}
		}

		i_print = INT_SIZE;
	}
	
	while (i_print-- > 0)
	{
		printf("%d", bin[i_print]);
	}

	printf("\n");

	return 0;
}
