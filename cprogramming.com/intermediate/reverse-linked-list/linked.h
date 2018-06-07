//typedef struct node node_t;
//typedef struct list list_t;

struct node
{
	int data;
	struct node *next;
};

struct list
{
	struct node *head;
	struct node *tail;
	int size;
};

struct list *list_create (void);

void list_destroy (struct list *list);

void list_print (struct list *list);

void list_print_reverse (struct list *list);

void list_reverse (struct list *list);

void node_insert (struct list *list, int data);
