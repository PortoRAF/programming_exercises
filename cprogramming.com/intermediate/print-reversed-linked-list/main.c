#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

int main (void)
{
	struct list *list;

	list = list_create();

	list_destroy(list);

	return 0;
}
