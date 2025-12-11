#include "sort.h"

/**
 * bubble_sort - oh no it's bubble sort.....
 * @array: the array we're looking at
 * @size: the size of the array?
 */

void bubble_sort(int *array, size_t size)
{
	size_t inner = 0, outer = 0;
	int temp = 0;

	/*loop 1 - do it all again! */
	for (outer = 0; outer < size - 1; outer++)
	{
	/*loop 2 - look at each element and swap spots if a is smaller than b */
		for (inner = 0; inner < size - outer - 1; inner++)
		{
			if (array[inner] > array[inner + 1])
			{
				temp = array[inner];
				array[inner] = array[inner + 1];
				array[inner + 1] = temp;
			}
		}
		print_array(array, size);
	}
}
