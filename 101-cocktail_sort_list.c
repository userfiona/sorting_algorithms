#include "sort.h"

/**
 * dll_adj_swap - Swaps two adjacent nodes of a doubly linked list.
 * @list: A pointer to the doubly linked list to be sorted.
 * @left: The node closer to the head, right->prev.
 * @right: The node closer to the tail, left->next.
 */
void dll_adj_swap(listint_t **list, listint_t *left, listint_t *right)
{
	listint_t *swap;

	if (left->prev)
		left->prev->next = right;
	else
		*list = right;

	if (right->next)
		right->next->prev = left;

	right->prev = left->prev;
	left->prev = right;
	swap = right;
	left->next = right->next;
	swap->next = left;

	print_list(*list);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                      order using the Cocktail shaker sort algorithm.
 * @list: A pointer to the doubly linked list to be sorted.
 */
void cocktail_sort_list(listint_t **list)
{
	bool swapped_f, swapped_b;
	int shake_range = 1000000, checks;
	listint_t *temp;

	if (!list || !(*list) || !(*list)->next)
		return;

	temp = *list;
	do {
		swapped_f = swapped_b = false;
		for (checks = 0; temp->next && checks < shake_range; checks++)
		{
			if (temp->next->n < temp->n)
			{
				dll_adj_swap(list, temp, temp->next);
				swapped_f = true;
			}
			else
				temp = temp->next;
		}

		if (!temp->next)  /* First loop, measuring list */
			shake_range = checks;

		if (swapped_f)
			temp = temp->prev;

		shake_range--;

		for (checks = 0; temp->prev && checks < shake_range; checks++)
		{
			if (temp->n < temp->prev->n)
			{
				dll_adj_swap(list, temp->prev, temp);
				swapped_b = true;
			}
			else
				temp = temp->prev;
		}

		if (swapped_b)
			temp = temp->next;
	} while (swapped_f || swapped_b);
}
