#include <stdio.h>

int check_limit (char *input, int value, int low, int high)
{
	if (value < low) {
		printf("INVALID INPUT! %s temperature below limit!\n", input);
		return 0;
	} else if (value > high) {
		printf("INVALID INPUT! %s temperature above limit!\n", input);
		return 0;
	} else {
		return 1;
	}
}

int main (void)
{
	int temp_C_low;
	int temp_C_high;
	int temp_C_step;

	/*Take initial temperature in Celsius*/
	printf("Please type in a lower limit (0 <= limit < 500): ");
	scanf("%d", &temp_C_low);

	if (!check_limit("Lower", temp_C_low, 0, 499)) return 0;
	
	/*Take final temperature in Celsius*/
	printf("Please type in a higher limit (10 < limit <= 500): ");
	scanf("%d", &temp_C_high);

	if (!check_limit("Higher", temp_C_high, 11, 500)) return 0;
	
	/*Take step size*/
	printf("Please type in a step (0 < step <= 50): ");
	scanf("%d", &temp_C_step);

	if (!check_limit("Step", temp_C_step, 1, 50)) return 0;

	/*Check if step is smaller than temperature difference*/
	if (temp_C_high - temp_C_low < temp_C_step) {
		printf("INVALID INPUT! Step size is greater than temperature difference\n");
		return 0;

	}

	printf("\nCelsius\t\tFahrenheit");
	printf("\n-------\t\t----------\n");

	int i;
	for (i = temp_C_low; i <= temp_C_high; i += temp_C_step) {
		printf("%3d.000\t\t%06.3f\n", i, (float)i * 9.0/5.0 + 32 );
	}

	return 0;
}
