#include <stdio.h>
#include <time.h>

int main ()
{
	srand( (unsigned)time(NULL) );
	unsigned int number = rand() % 100;
	int guess = -1;
	unsigned int number_try = 8;
	char buf[4];

	while (guess != number && number_try--) {
		puts("Pick a number between 0 and 99");
		fgets(buf, 4, stdin);
		guess = strtol(buf, NULL, 10);
		puts("");

		if (guess == number) {
			puts("Congratulations! You found the number!");
			printf("Number of tries: %d\n\n", 8-number_try);
		
		} else if (guess < number) {
			puts("Sorry, you guessed too low. Try again!");
			printf("Number of remaining tries: %d\n\n", number_try);

		} else { // (guess > number)
			puts("Sorry, you guessed too high. Try again!");
			printf("Number of remaining tries: %d\n\n", number_try);
		}

	}

	return 0;
}
