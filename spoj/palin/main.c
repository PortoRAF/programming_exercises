#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUM_DIGITS 1000000

int main ()
{
	char cases[3];
	int t;

	fgets(cases, 3, stdin);
	t = strtol(cases, NULL, 10);

	if (t <= 0) {
		return 0;
	}

	char inputs[t][MAX_NUM_DIGITS];
	long long k[t];
	int i;
	
	for (i = 0; i < t; i++) {
		fgets(inputs[i], MAX_NUM_DIGITS, stdin);
		k[i] = strtoll(inputs[i], NULL, 10);
		if (k[i] <= 0 || k[i] > powl(10,MAX_NUM_DIGITS)) {

		}
	}

	for (i = 0; i < t; i++) {
		printf("%lld\n", k[i]);
	}

	return 0;
}
