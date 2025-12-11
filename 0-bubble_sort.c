#include "sort.h"

/**
 * bubble_sort - oh no it's bubble sort.....
 * @array: the array we're looking at
 * @size: the size of the array?
 */

void bubble_sort(int *array, size_t size)
{
	size_t innerLoop = 0, outerLoop = 0;
	int temp = 0;

	/*loop 1 - do it all again! */
	for (outerLoop = 0; outerLoop < size - 1; outerLoop++)
	{
	/*loop 2 - look at each element and swap spots if a is smaller than b */
		for (innerLoop = 0; innerLoop <= size - outerLoop - 1; innerLoop++)
		{
			if (array[innerLoop] > array[innerLoop + 1])
			{
				temp = array[innerLoop];
				array[innerLoop] = array[innerLoop + 1];
				array[innerLoop + 1] = temp;
			}
			print_array(array, size);
		}
	}
}
