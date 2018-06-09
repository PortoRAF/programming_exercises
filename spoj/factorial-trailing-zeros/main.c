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
#define MAX_TESTS 100000
#define MAX_INPUT 1000000000

int main (void)
{
	int n;

	printf("Insert number: ");
	scanf("%d", &n);

	int result = 0;

	while (n > 0)
	{
		n /= 5;
		result += n;
	}
	
	printf("Z(n) = %d\n", result);

	return 0;
}
