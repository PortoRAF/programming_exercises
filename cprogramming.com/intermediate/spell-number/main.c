#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void spell_num (int num, int r)
{
	int i;
	for (i = 100; i > 0; i /= 10)
	{
		if (num / i != 0)
		{
		if (i == 10)
		{
			switch (num / i)
			{
				case(1): 
				{
					switch (num)
					{
						case(10): printf("ten "); break;
						case(11): printf("eleven "); break;
						case(12): printf("twelve "); break;
						case(13): printf("thirteen "); break;
						case(14): printf("fourteen "); break;
						case(15): printf("fifteen "); break;
						case(16): printf("sixteen "); break;
						case(17): printf("seventeen "); break;
						case(18): printf("eighteen "); break;
						case(19): printf("nineteen "); break;
						default: break;
					}
					num = 0;
					break;
				}
				case(2): printf("twenty "); break;
				case(3): printf("thirty "); break;
				case(4): printf("forty "); break;
				case(5): printf("fifty "); break;
				case(6): printf("sixty "); break;
				case(7): printf("seventy "); break;
				case(8): printf("eighty "); break;
				case(9): printf("ninety "); break;
				default: break;
			}
		}
		else
		{
			switch (num / i)
			{
				case(1): printf("one "); break;
				case(2): printf("two "); break;
				case(3): printf("three "); break;
				case(4): printf("four "); break;
				case(5): printf("five "); break;
				case(6): printf("six "); break;
				case(7): printf("seven "); break;
				case(8): printf("eight "); break;
				case(9): printf("nine "); break;
				default: break;
			}
			if (i == 100)
			{
				printf("hundred ");
			}
		}
		num = num % i;
		}
	}

	switch (r)
	{
		case(0): printf("billion "); break;
		case(1): printf("million "); break;
		case(2): printf("thousand "); break;
		default: break;
	}
}

int main (int argc, char *argv[])
{
/*
	if (argc != 2)
	{
		("usage: %s number\n", argv[0]);
		exit(EXIT_FAILURE);
	}
*/
	int num;
	printf("Please insert a number between %d and %d: ", INT_MIN, INT_MAX);
	scanf("%d", &num);

	if (num >> 31) // MSB = 1 : negative number
	{
		/* Two's complement */
//		num ^= -1; //Invert all bits
//		num += 1;  //Add 1
		num *= -1;
		printf("minus ");
	}

	int i;
	int m;
	int r = 0;
	for (i = 1000000000; i > 0; i /= 1000)
	{
		m = num / i;

		if (m != 0)
		{
			/* print numbers */
//			printf("%d\n", m);
			spell_num(m, r);
			num = num % i; // Remove upper values
		}

		r++;
//		printf("%d\n", m);
	}

	printf("\n");
	
/*
	int num_len = strlen(argv[1]);
	char num[num_len+1][]; thousand

	int i;
	int j = 0;
	for (i = (strlen(argv[1])-1); i >= 0; i--)
	{
		if (j % 2 != 0)
		{
			
		}
	}
*/
	return 0;
}
