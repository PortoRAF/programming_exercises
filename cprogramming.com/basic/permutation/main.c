#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**********************
 *
 * Function declared for learning purposes
 * It will not be used in this program
 *

static FILE *open_file (FILE *filename, char *mode)
{
	FILE *fp = fopen(filename, mode);

	if (fp == NULL)
	{
		printf("Unable to open file");
		exit(EXIT_FAILURE);
	}
	
	return fp;
}

*/

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

void permute (char *arr, int start, int end)
{
	if (start == (end-1))
	{
		printf("%s\n", arr);
	}
	else
	{
		int i;
		for (i = start; i < end; i++)
		{
			swap( (arr+start) , (arr+i) );
			permute(arr, start+1, end);
			swap( (arr+start), (arr+i) );
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
