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

/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
    listint_t *list;
    listint_t *node;
    int *tmp;

    list = NULL;
    while (size--)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        tmp = (int *)&node->n;
        *tmp = array[size];
        node->next = list;
        node->prev = NULL;
        list = node;
        if (list->next)
            list->next->prev = list;
    }
    return (list);
}


/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    listint_t *list;
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    list = create_listint(array, n);
    if (!list)
        return (1);
    print_list(list);
    printf("\n");
    insertion_sort_list(&list);
    printf("\n");
    print_list(list);
    return (0);
}
