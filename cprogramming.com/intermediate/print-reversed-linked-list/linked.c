#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

struct list *list_create (void)
{
	struct list *list = malloc(sizeof(struct list));

	list->head = NULL;
	list->tail = NULL;
	list->size = 0;

	return list;
}

void list_destroy (struct list *list)
{
	struct node *current = list->head;
	struct node *next;

	while (current != NULL)
	{
		next = current->next;		
		free(current);
		current = next;
	}

	free(list);
}

void list_print (struct list *list)
{
	struct node *current = list->head;

	printf("{ ");

	while (current != NULL)
	{
		if (current != list->tail)
		{
			printf("%d, ", current->data);
		}
		else
		{
			printf("%d }", current->data);
		}

		current = current->next;
	}
}

void list_print_reverse (struct list *list)
{

}

void node_insert (struct list *list, int data)
{
	struct node *node = malloc(sizeof(struct node));

	node->data = data;
	node->next = NULL;

	if (list->size == 0)
	{
		list->head = node;
		list->tail = node;
	}
	else
	{
		list->tail->next = node;
		list->tail = node;
	}

	list->size++;
}
