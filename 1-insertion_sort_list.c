#include "sort.h"

/**
 * insertion_sort_list - Insertion sort on a doubly linked list
 * @list: the doubly linked list... WHY
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *currentNode, *nextNode;

	if (!list || !(*list) || !(*list)->next)
		return;

	currentNode = (*list)->next;
	while (currentNode)
	{
		nextNode = currentNode->next;
		while (currentNode->prev &&
				currentNode->n < currentNode->prev->n)
		{
			/* Swap currentNode with previous node */
			listint_t *prev = currentNode->prev;
			listint_t *next = currentNode->next;

			/* Stitch prev->prev to currentNode */
			if (prev->prev)
				prev->prev->next = currentNode;
			currentNode->prev = prev->prev;

			/* Stitch currentNode to prev */
			currentNode->next = prev;
			prev->prev = currentNode;

			/* Stitch prev to next */
			prev->next = next;
			if (next)
				next->prev = prev;

			/* Update head if needed */
			if (!currentNode->prev)
				*list = currentNode;

			/* Print after every single swap */
			print_list(*list);
		}
		currentNode = nextNode;
	}
}
