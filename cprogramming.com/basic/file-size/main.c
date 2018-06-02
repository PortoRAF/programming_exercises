#include <stdio.h>
#include <stdlib.h>

static FILE *open_file (char *file, char *mode)
{
	FILE *fp = fopen(file, mode);

	if (fp == NULL)
	{
		perror("Unable to open file");
		exit(EXIT_FAILURE);
	}
	
	return fp;		
}

int main (int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		FILE *file = open_file(argv[1], "r");
		
		char c;
		int count = 0;

		while ((c = fgetc(file)) != EOF)
		{
			count++;
		}

		printf("File size: %d bytes\n", count);

		fclose(file);
	}
}
