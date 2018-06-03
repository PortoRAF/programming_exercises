#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

const char *num_to_text[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", \
							"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", \
							"eighteen", "nineteen" };

const char *tens_to_text[] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

const char *powers_to_text[] = { "", "thousand", "million", "billion" };

void add_space(char *str)
{
	str = strcat(str, " ");
}

void append_hundred (int n, char *str)
{
	strcat(str, num_to_text[n]);
	add_space(str);
	strcat(str, "hundred");
	add_space(str);
}

char *spell_num (int num, int pwr)
{
	char *new_str = malloc(256);

	if (num/100)
	{
		append_hundred(num/100, new_str);
		num = num % 100;
	}

	if (num >= 20)
	{
		strcat(new_str, tens_to_text[num/10]);
		add_space(new_str);
		strcat(new_str, num_to_text[num%10]);
		add_space(new_str);
	}
	else
	{
		strcat(new_str, num_to_text[num]);
		add_space(new_str);
	}
	
	strcat(new_str, powers_to_text[pwr]);
	add_space(new_str);

	return new_str;
}

char *prepend_neg (char *str)
{
	char *new_str = malloc(256);
	strcat(new_str, "minus");
	add_space(new_str);
	strcat(new_str, str);
	
	return new_str;
}

int main (void)
{
	int num;
	printf("Please insert a number between %d and %d: ", INT_MIN, INT_MAX);
	scanf("%d", &num);

	int is_neg = 0;
	if (num < 0) 
	{
		is_neg = 1;
		num *= -1;
	}

	char *str = malloc(256);	
	int m;
	int pwr = 0;
	while (num > 0)
	{
		m = num % 1000;

		if (m != 0)
		{
			str = strcat(spell_num(m, pwr), str);
		}

		num /= 1000;
		pwr++;
	}

	if (is_neg)
	{
		str = prepend_neg(str);
	}

	printf("%s\n", str);

	free(str);	

	return 0;
}
