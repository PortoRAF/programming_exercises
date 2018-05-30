#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NUM_DIGITS 1000000

bool isAllNines (char *input, int *size)
{
	int i;

	for (i = 0; i < *size; i++) {
		int ia = input[i] - '0'; //Convert char to int
		if (ia != 9) {
			return false;
		}
	}
	
	return true;
}

char *substituteAllNines (int *size)
{
	if (*size == MAX_NUM_DIGITS) {
		return "0";
	}
	
	char *str = malloc(*size+2);
		
	int i;
	
	for (i = 0; i < (*size+2); i++) {
		if (i==0 || i==*size) {
			str[i] = '1';
		} else if (i==(*size+1)) {
			str[i] = '\0';
		} else {
			str[i] = '0';
		}
	}
		
	return str;
}

char *incrementMid (char input[], int *mid, int *odd)
{
	int i;
	
	if (input[*mid-1+*odd] == '9') {
		for (i = 0; i < *mid; i++) {
			input[*mid-1-i+*odd] = '0';
			if (input[*mid-2-i+*odd] != '9') {
				input[*mid-2-i+*odd]++;
				break;
			}
		}
	} else {
		input[*mid-1+*odd]++;
	}

	return input;
}

char *palin (char input[])
{
	int i;
	int size = (int)strlen(input);
	bool nines = isAllNines(input, &size);
	
	if (nines) {
		return substituteAllNines(&size);
	}

	if (size == 1) {
		input[0]++;
		return input;
	}
	
	if (size == 2) {
		if (input[0] == input[1]) {
			input[0]++;
		}
	}

	int mid = size / 2;
	int odd = size % 2;

	/* If the two central values are equal, we need to check the next pair and so forth
	   to see if an increment is necessary */
	if (input[mid-1] == input[mid+odd]) {
		for (i = 0; i < mid; i++) { 
			if (input[mid-1-i] < input[mid+i+odd]) { //If the left side is smaller than increment middle
				input = incrementMid(input, &mid, &odd);
				break;
			} else if (input[mid-1-i] > input[mid+i+odd]) {
				break;
			}


			if (i == mid-1) { //If all values are equal (already a palindrome)
				input = incrementMid(input, &mid, &odd);
			}
		}
		

		
	} else if (input[mid-1] < input[mid+odd]) {
		input = incrementMid(input, &mid, &odd);
	}

	/* When left side of string is already sorted, copy its content to right side */
	for (i = 0; i < mid; i++) {
		input[mid+i+odd] = input[mid-1-i];
	}

	return input;
}

int main ()
{
	int t, i;

	scanf("%d", &t);

	if (t <= 0) {
		return 0;
	}

	char *inputs[t];
	for (i = 0; i < t; i++) {
		inputs[i] = malloc(MAX_NUM_DIGITS * sizeof(char));
	}

	for (i = 0; i < t; i++) {
		scanf("%s", inputs[i]);
		if ((int)strlen(inputs[i]) > MAX_NUM_DIGITS) {
			return 0;
		}
	}

	for (i = 0; i < t; i++) {
		printf("%s\n", palin(inputs[i]));
	}

	return 0;
}
