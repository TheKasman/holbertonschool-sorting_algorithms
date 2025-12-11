#include "sort.h"

/**
 * insertion_sort_list - Insertion sort on a doubly linked list
 * @list: the doubly linked list... WHY
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *currentNode, *temp, *nextNode;

	if (!list || !(*list))
		return;

	currentNode = (*list)->next;

	while (currentNode != NULL)
	{
		nextNode = currentNode->next;
		temp = currentNode->prev;

		/*the insertion spot is ......?*/
		while (temp != NULL && currentNode->n < temp->n)
			temp = temp->prev;

		/*stitching*/
		/*end of the sort to the rest of the list*/
		if (currentNode->prev != NULL)
			currentNode->prev->next = currentNode->next;
		/*the rest of the list to the end of the sort*/
		if (currentNode->next != NULL)
			currentNode->next->prev = currentNode->prev;

		/*puts the current node to the head*/
		if (temp == NULL)
		{
			currentNode->prev = NULL;
			currentNode->next = *list;
			(*list)->prev = currentNode;
			*list = currentNode;
			print_list(*list);
		}
		/*the current node goes to a different place*/
		else
		{
			currentNode->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = currentNode;
			temp->next = currentNode;
			currentNode->prev = temp;
			print_list(*list);
		}
		currentNode = nextNode;
	}

}
