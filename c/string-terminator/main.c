#include <stdio.h>
#include <string.h>

int main ()
{
	char name[13] = "Renato Porto";
	printf("My name is %s\n", name);

	name[0] = 'Z';
	printf("My name is %s\n", name);

	char food[] = "tuna";
	printf("The best food is %s\n", food);

	strcpy(food, "bacon");
	printf("The best food is %s\n", food);

	return 0;
}
