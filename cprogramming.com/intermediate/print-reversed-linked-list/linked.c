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

void print_next (struct node *node)
{
	if (node->next == NULL)
	{
		printf ("{ %d, ", node->data);
	}
	else
	{
		print_next(node->next);
		printf("%d, ", node->data);
	}
}

void list_print_reverse (struct list *list)
{
	print_next(list->head);
	printf("}\n");
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
