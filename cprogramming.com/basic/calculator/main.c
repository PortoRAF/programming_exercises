#include <stdio.h>
#include <stdlib.h>

float multiply (int x, int y)
{
	return x * y;
}

float divide (int x, int y)
{
	return x / y;
}

float add (int x, int y)
{
	return x + y;
}

float subtract (int x , int y)
{
	return x - y;
}

int main (void)
{
	char *op = malloc(sizeof(op));
//	char buf;
	int x, y;
	float result;

	while (*op != 'e') {
		puts("What operation would you like to perform:\nadd(+), subtract(-), multiply(*), divide(/), or [e]xit?");
		scanf("%s", op);
//		buf = getchar();
		
//		if (*op != 'e') {
		switch(*op)
		{
			case '+':
			case '-':
			case '*':
			case '/':
			
			printf("\nEnter the value of 'x': ");
			scanf("%d", &x);

			printf("Enter the value of 'y': ");
			scanf("%d", &y);
		
			switch(*op)
			{
				case '+': result = add(x, y);	   break;
				case '-': result = subtract(x, y); break;
				case '*': result = multiply(x, y); break;
				case '/': result = divide(x, y);   break;
				default : ;
			}
	
			printf("\nOperation result %.2f\n\n", result);
		}
	}

	return 0;
}
