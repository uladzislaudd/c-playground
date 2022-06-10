#include <stdlib.h>

typedef struct list_s
{
    struct list_s *next; /* NULL for the last item in a list */
    int data;
} list_t;

/* Counts the number of items in a list. */
size_t count_list_items(const list_t *head)
{
	size_t rv = 0;
	const list_t *i = head;

	while (i != NULL) {
		i = i->next;
		rv++;
	}

	return rv;	
}

/* Inserts a new list item after the one specified as the argument. */
void insert_next_to_list(list_t *item, int data) {
	(item->next = malloc(sizeof(list_t)))->next = item->next;
	item->next->data = data;
}

/* Removes an item following the one specificed as the argument. */
void remove_next_from_list(list_t *item) {
    if (item->next) {
        free(item->next);
        item->next = item->next->next;
    }
}

/* Returns item data as text. */
char *item_data(const list_t *list)
{
	char buf[12];

	sprintf(buf, "%d", list->data);
	return buf;
}
