#include <stdio.h>

int main()
{
	int age1, age2, age3;
	
	age1 = 10;
	age2 = ++age1; //increment age1 and assign incremented value to age2
	age3 = age1++; //assign age1 value to age3 then increment age1

	printf("%d\n%d\n%d\n", age1, age2, age3);

	age1 = age1++;	
	printf("\n%d\n", age1);

	age1 = ++age1;	
	printf("\n%d\n", age1);

	return 0;
}
