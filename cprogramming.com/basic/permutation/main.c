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
