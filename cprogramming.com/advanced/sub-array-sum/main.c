/***************************************************
/ Exercise: 
/ Given an array of integers, find the most efficient 
/ way to extract the subarray with the largest sum of
/ its elements. Because some elements of the array may
/ be negative, the problem can be challenging. An array 
/ of all negatives would result in a subarray of length
/ zero.
/ 
/ For example:
/
/ {1, 2, -5, 4, -3, 2} has maximum sum of a subarray of 4.
/
/ {1, 2, -5, 4, -1, 2} has maximum sum of a subarray of 5.
/
*/

#include <stdio.h>

int main (int argc, char *argv[])
{
	if (argc == 1)
	{
		printf("usage: %s num1 num2 num3 ...\n", argv[0]);
		return 1;
	}

	int num[10];
		
	int i;
	for (i = 0; i < (argc-1); i++)
	{
		num[i] = strtol(argv[i+1], NULL, 10);
	}
	
	/* Solution taken from cprogramming.com.
		It solves in O(n) but doesn't work
		for negative arrays */
	int sum = 0;
	int max = 0;
	for (i = 0; i < (argc-1); i++)
	{
		sum = sum + num[i];
		if (sum < 0)
		{
			sum = 0;
		}
		max = sum > max ? sum : max;
	}

	printf("The maximum subarray sum is %d\n", max);
	
/*	
	int j;
	int sum;
	int max = 0x80000001;
	int start = -1;
	int end = -1;
	for (i = 0; i < (argc-1); i++)
	{	
		sum = 0;
		for (j = i; j < (argc-1); j++)
		{
			sum = sum + num[j];
			if (sum > max)
			{
				max = sum;
				start = i;
				end = j;
			}
		}
	}

	printf("The subarray with the largest sum is:\n{ ");
	for (i = start; i <= end; i++)
	{
		printf("%d, ", num[i]);
	}
	printf ("}\n");
*/
	return 0;
}
