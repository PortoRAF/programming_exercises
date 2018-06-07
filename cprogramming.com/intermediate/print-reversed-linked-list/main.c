#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

int main (void)
{
	struct list *list;

	list = list_create();

	node_insert(list, 1);
	node_insert(list, 2);
	node_insert(list, 3);	

	list_print(list);

	list_print_reverse(list);	

	list_destroy(list);

	return 0;
}
