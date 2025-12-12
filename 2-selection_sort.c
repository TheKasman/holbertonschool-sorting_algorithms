#include "sort.h"

/**
 * selection_sort - ... what it says on the tin
 * @array: the array
 * @size: the size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t inner, outer, index;
	int temp;

	/*ONCE MORE WITH FEELING!*/
	for (outer = 0; outer < size - 1; outer++)
	{
		index = outer;
		/*check every entity is smaller than index[outer]*/
		for (inner = outer + 1; inner < size; inner++)
		{
			if (array[inner] < array[index])
			{
				index = inner;
			}
		}
		/*NOW we do the swap~!*/
		if (index != outer)
		{
			temp = array[outer];
			array[outer] = array[index];
			array[index] = temp;
			print_array(array, size);
		}
	}
}
