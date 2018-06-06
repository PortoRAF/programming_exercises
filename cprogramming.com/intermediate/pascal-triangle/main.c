#include <stdio.h>

int find_pascal (int row, int pos)
{
	if (row == 0 || row == 1 || pos == 0)
	{
		return 1;
	}
	else if (pos == row)
	{
		return 1;
	}
	else
	{
		return (find_pascal(row-1, pos) + find_pascal(row-1, pos-1) );
	}
}

int main (void)
{
	int row;
	int pos;

	printf("\n================ PASCAL'S TRIANGLE ================\n");
	printf("Find the value for a given position in the triangle.\n\n");

	printf("Insert a row value: ");
	scanf("%d", &row);
	printf("Insert position in row: ");
	scanf("%d", &pos);

	if (row < 0 || pos < 0)
	{
		printf("\nERROR: Both values must be positive integers!\n\n");
		return 1;
	}

	if (pos > row)
	{
		printf("\nERROR: The position value must be equal or smaller than the row value.\n\n");
		return 1;
	}
	
	int res = find_pascal(row, pos);
	
	printf("\nSUCCESS! The value for the given position in Pascal's Triangle is: %d\n\n", res);

	return 0;
}
