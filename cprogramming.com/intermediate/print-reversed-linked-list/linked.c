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
	struct node *node = list->head;

	printf("{ ");

	while (node != NULL)
	{
		if (node != list->tail)
		{
			printf("%d, ", node->data);
		}
		else
		{
			printf("%d }\n", node->data);
		}

		node = node->next;
	}
}

void list_print_reverse (struct list *list)
{
	struct node *node = list->head;

	int data[list->size];
	int i = 0;
	while (node != NULL)
	{
		data[i++] = node->data;
		node = node->next;
	}

	printf ("{ ");
	while (i-- > 1)
	{
		printf("%d, ", data[i]);
	}
	printf("%d }\n", data[i]);
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
