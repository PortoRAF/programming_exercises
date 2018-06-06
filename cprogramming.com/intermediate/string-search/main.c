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

int set_index (int *char_compares, char token_pos[3], int *index_pos)
{
	int j  = *index_pos;

	if (*char_compares)
	{
		j++;
	}
	else if (token_pos[1])
	{
		; //do nothing
	}
	else if (token_pos[2])
	{
		j++;
	}
	else
	{
		j = token_pos[0];
	}

	return j;
}

int compare_strings (char *str_orig, char *subset, int str_orig_len, int subset_len)
{
//	int is_subset = 0;
	char token = '*';
//	int token_at_start = 0;
//	int token_at_mid = 0;
	char token_pos[3] = {0, 0, 0};
	int char_compares = 0;
	int i;
	int j = 0;

	for (i = 0; i < str_orig_len; i++)
	{
		if (j < subset_len)
		{
			if (subset[j] == str_orig[i])
			{
				char_compares = 1;
			}
			else if (subset[j] == token)
			{
//				id_token(&j, token_pos);
				if (j == 0)
				{
					token_pos[0] = 1;
				}
				else if (subset[j-1] != '\\')
				{
					if (j == (subset_len - 1))
					{
						j++;
						break;
					}
					else
					{
						token_pos[1] = 1;
						j++;
					}
				}
			}

			j = set_index(&char_compares, token_pos, &j);
		
			if (char_compares)
			{
				char_compares = 0;
				token_pos[1] = 0;
			}
		}
		else
		{
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
