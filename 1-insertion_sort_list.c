#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list using insertion sort
 * @list: double pointer to head of list
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current, *tmp;

if (!list || !*list || !(*list)->next)
return;

current = (*list)->next;
while (current)
{
tmp = current;
current = current->next;
while (tmp->prev && tmp->n < tmp->prev->n)
{
/* Swap tmp and tmp->prev */
tmp->prev->next = tmp->next;
if (tmp->next)
tmp->next->prev = tmp->prev;

tmp->next = tmp->prev;
tmp->prev = tmp->prev->prev;

if (tmp->prev)
tmp->prev->next = tmp;
else
*list = tmp;

tmp->next->prev = tmp;

print_list(*list);
}
}
}
