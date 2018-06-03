#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/***********************************************
 *          *** FACTORIAL FUNCTION ***
 *----------------------------------------------
 * Given an user input, return its factorial 'n!'
 *
 */

int f (int n)
{
	if (n == 1)
	{
		return 1;
	}
	
	return n*(f(n-1));
}

int main (void)
{
	clock_t start, end;
	double cpu_time_used;
	start = clock();

	int n;
	printf("Please input a number greater than 0: ");
	scanf("%d", &n);

	if (n < 1)
	{
		printf("Invalid input!");
		exit(EXIT_FAILURE);
	}

	printf("Factorial of %d is %d\n", n, f(n));

	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

	printf("Elapsed time: %f\n", cpu_time_used);

	return 0;
}
