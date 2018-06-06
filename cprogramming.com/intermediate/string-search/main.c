#include <stdio.h>
#include <stdlib.h>

int calc_str_len (char *str)
{
	int str_len = 0;
	
	while (str[str_len] != '\000')
	{
		str_len++;
	}

	return str_len;
}

int compare_strings (char *str_orig, char *subset, int str_orig_len, int subset_len)
{
//	int is_subset = 0;
	int start_comparing = 0;
	int i;
	int j = 0;

	for (i = 0; i < str_orig_len; i++)
	{
		if (j < subset_len)
		{
			if (subset[j] == str_orig[i])
			{
				start_comparing = 1;
			}

			if (start_comparing)
			{
				j++;
			}
			else
			{
				j = 0;
			}
		
			start_comparing = 0;
		}
		else
		{
//			is_subset = 1;
			break;
		}
	}

	return j == subset_len;
}

int main (int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("usage: %s string substring\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	int first_str_len  = calc_str_len(argv[1]);
	int second_str_len = calc_str_len(argv[2]);

	if (second_str_len > first_str_len)
	{
		printf("Second string is larger than the first.\n");
		exit(EXIT_FAILURE);
	}

	int is_subset = compare_strings(argv[1], argv[2], first_str_len, second_str_len);

	if (is_subset)
	{
		printf("\"%s\" is a subset of \"%s\"\n", argv[2], argv[1]);
	}
	else
	{
		printf("String is not a subset.\n");
	}

	return 0;
}
