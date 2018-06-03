#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**********************
 * PERMUTATION
 *-------------
 * Program takes one string as input and display all possible
 * permutations of its letters;
 *
 */

void swap (char *x, char *y)
{
	char tmp = *x;
	*x = *y;
	*y = tmp;
}

/*****************************
 * To execute the permutation, we need a loop within a loop for 
 * each letter of the string. For 'ABCD', take 'A' then loop through
 * 'AB' which give us 'ABCD' and 'ABDC'. Next loop is 'AC', where we
 * get 'ACBD' and 'ACDB'. When 'AB', 'AC', and 'AD' are done, take
 * 'B', then 'BA', 'BC', 'BD', and so on.
 *
 *------------------------------------------------------
 * Inputs are: array to be permuted, recursive loop depth, size of the array
 *
 * The outer loop will put all array elements on the first position
 * Next loop will put the remaining elements in the second position
 * Following loop will take remaining elements to the third position
 * And so as necessary.
 *
 */

void permute (char *arr, int place, int end)
{
	if (place == (end-1))
	{
		printf("%s\n", arr);
	}
	else
	{
		int next_char;
		for (next_char = place; next_char < end; next_char++)
		{
			swap( (arr+place) , (arr+next_char) );
			permute(arr, place+1, end);
			swap( (arr+place), (arr+next_char) );
		}
	}
}

int main (int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("usage: %s string\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	else
	{		
		permute(argv[1], 0, strlen(argv[1]));
	}

	return 0;
}
