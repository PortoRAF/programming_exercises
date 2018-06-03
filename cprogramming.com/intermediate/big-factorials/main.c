/******************************************
 *    *** FACTORIAL TRAILING ZEROS ***
 *-----------------------------------------
 * Program requests user for a positive integer and returns
 * its factorial and the number of trailing zeros.
 * 
 * The challenge is dealing with very big numbers.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int factorate (int factorial[], int d)
{
	int carry = 0;
	int store = 0;
	int f_len = 1;
	
	factorial[0] = 1;
	
	int i;
	int j;
	for (i = 1; i <= d; i++)
	{
		carry = 0;
		for (j = 0; j < f_len; j++)
		{
			store = factorial[j] * i + carry;
			factorial[j] = store % 10;
			carry = store / 10;
		}
		while (carry)
		{
			factorial[j] = carry % 10;
			carry /= 10;
			j++;
			f_len++;
		}
	}

	return f_len;
}

int main (void)
{
	int n;
	printf("Please insert a number greater than zero: ");
	scanf("%d", &n);

	if (n <= 0)
	{
		printf("Invalid input!\n");
		exit(EXIT_FAILURE);
	}

	int factorial[5120];
	
	int f_len = 1;
	f_len = factorate(factorial, n);

	int count = 0;
	while (factorial[count] == 0)
	{
		count++;
	}

	int i;

	printf("\nFactorial of %d is ", n);

	for (i = (f_len-1); i >= 0; i--)
	{
		printf("%d", factorial[i]);
	}

	printf("\n\n");
	printf("Number of trailing zeros: %d\n", count);

	return 0;
}
