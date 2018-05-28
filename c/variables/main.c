#include <stdio.h>

int main()
{
	int age;
	int currentYear;
	int birthYear;

	currentYear = 2018;
	birthYear = 1983;
	age = currentYear - birthYear;

	printf("This coder is %d years old.\n", age);
	
	return 0;
}
