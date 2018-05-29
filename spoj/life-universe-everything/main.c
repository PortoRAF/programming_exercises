#include <stdio.h>

int main()
{
	int question, life = 0;

	while(life != 1) {

		scanf("%d", &question);

		if (question != 42) {
			printf("%d\n", question);
		} else {
			life = 1;
		}
	}

	return 0;
}
