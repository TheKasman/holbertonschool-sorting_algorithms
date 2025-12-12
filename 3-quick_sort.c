#include "sort.h"

/**
 * quick_sort - uses quick sort (splits the array up using a pivot and go)
 * @array: the array
 * @size: the sizeof the array
 */

void quick_sort(int *array, size_t size)
{
	int pivot, temp;
	size_t i, j, left, right;
	static int *original_array = NULL;
	static size_t original_size = 0;

	if (!original_array)
	{
		original_array = array;
		original_size = size;
	}

	/*base case!*/
	if (size <= 1)
		return;

	pivot = array[size / 2];

	i = 0;
	for (j = 0; j < size; j++)
	{
		if (array[j] < pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			print_array(original_array, original_size);
		}
	}
	left = i;
	right = size - i;

	quick_sort(array, left);
	quick_sort(array + i, right);
}
