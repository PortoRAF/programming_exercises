#include <stdio.h>

int main()
{
	char firstName[20];
	char client[20];
	int numberOfOrders;

	printf("What is your name? \n");
	scanf("%s", firstName);

	printf("What is the name of your client? \n");
	scanf("%s", client);

	printf("How many orders does he/she have do far?\n");
	scanf("%d", &numberOfOrders);

	printf("%s is %s's client and has %d orders.\n", client, firstName, numberOfOrders);

	return 0;
}
