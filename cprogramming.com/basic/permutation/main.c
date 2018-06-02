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

int main (int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("usage: %s string\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	else
	{		
		int in_len = strlen(argv[1]);
		char input[in_len+1];

		int i;

		for (i = 0; i < in_len; i++)
		{
			input[i] = argv[1][i];
		}

		printf("%s\n", input);
	}

	return 0;
}
