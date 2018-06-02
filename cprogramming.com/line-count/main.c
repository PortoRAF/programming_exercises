#include <stdio.h>

int main (int argc, char *argv[])
{
	if (argc != 2) //program expects 2 arguments
	{
		printf("usage: %s filename\n", argv[0]);
	}
	else
	{
		/*
		* argv[0] : program name
		* argv[1] : filename
		*/

		FILE *file = fopen(argv[1], "r");

		if (file == 0) //fopen will return a null pointer on failure
		{
			printf("Could not open file.\n");
		}
		else
		{
			char c;
			int count = 0;
			
			while ((c = fgetc(file)) != EOF)
			{
				if (c == '\n')
				{
					count++;
				}
			}
		
			printf("File has %d lines.\n", count);
		
			fclose(file);
		}
	}

	return 0;
}
