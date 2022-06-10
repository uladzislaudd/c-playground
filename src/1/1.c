#include <stdlib.h>

typedef int STATUS;

enum {
	ERR_SUCCESS = 0,
	ERR_FAILURE,
	ERR_ARGS_INVALID,
	ERR_NO_MEMORY,
};

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
STATUS insert_next_to_list(list_t *item, int data) {
	struct list_s *new = NULL;

	if (item == NULL) {
		return ERR_ARGS_INVALID;
	}

	new = malloc(sizeof(list_t));
	if (new == NULL) {
		return ERR_NO_MEMORY;
	}

	new->next = item->next;
	new->data = data;
	item->next = new;

	return ERR_SUCCESS;
}

/* Removes an item following the one specificed as the argument. */
STATUS remove_next_from_list(list_t *item) {
	struct list_s *new_next = NULL, *to_delete = NULL;

	if (item == NULL) {
		return ERR_ARGS_INVALID;
	}

	to_delete = item->next;
	if (to_delete != NULL) {
		new_next = to_delete->next;
	}

	item->next = new_next;

	if (to_delete != NULL) {
		free(to_delete);
	}

	return ERR_SUCCESS;
}

/* Returns item data as text. */
char *item_data(const list_t *list)
{
	char buf[12];

	sprintf(buf, "%d", list->data);
	return buf;
}
