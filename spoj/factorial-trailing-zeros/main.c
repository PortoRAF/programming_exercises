/****************************************************************************
 * This function should first request from the user a number of test cases.
 * For each test case, it should return the number of trailing zeros of the
 * factorial of the input value "n!".
 *
 * Maximum number of test cases: 100000
 * Input value: 1 <= n <= 1000000000
 *
 *---------------------------------------------------------------------------
 * A simple way to solve this is to find which values that increase the number
 * of zeroes when multiplied. Multiples of 10 are certainly some of those values.
 * 5 * 2 = 10, so 5 also contributes.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_TESTS 100000
#define MAX_INPUT 1000000000

int calc_zeroes(n)
{
	int result = 0;

	while (n > 0)
	{
		n /= 5;
		result += n;
	}

	return result;
}

int main (void)
{
	int test_case;
	
	int len_max = 128; // Arbitrary value to initialize array
	int current_size = len_max;

	char *input = malloc(len_max);
	
	char c;
	int i = 0;
	while ( (c = getchar()) != '\n')
	{
		input[i++] = c;
	}

	input[i] = '\0';
	test_case = strtol(input, &input, 10);

	if (test_case > MAX_TESTS || test_case < 1)
	{
		return 1;
	}

	if (input != NULL) // Check if memory was allocated
	{
		int c = NULL;
		int i = 0;
		int ret = 0;
		while ( ret < test_case && c != EOF )
		{
			c = getchar();
			input[i++] = (char)c;

			if (i == current_size)
			{
				current_size = len_max + i;
				input = realloc(input, current_size);
			}

			if (input[i-1] == '\n') ret++;
/*			
			if (i == 1)
			{
				test_case = strtol(input, &input, 10);
				if (test_case > MAX_TESTS) break;
			}
*/
		}
		
		input[i] = '\0'; // Make array into string

//		printf("%s\n", input);

//		char *str;
//		test_case = strtol(input, &input, 10);i

		for (i = 0; i < test_case; i++)
		{
			printf("%d\n", calc_zeroes(strtol(input, &input, 10)));
		}
	}
	else
	{
		return(1);
	}

	int result = 0;
/*
	while (n > 0)
	{
		n /= 5;
		result += n;
	}
	
	printf("Z(n) = %d\n", result);
*/
	return 0;
}
