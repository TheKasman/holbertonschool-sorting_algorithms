#include "sort.h"

/**
 * partition - helper function for quick sort to create partitions
 * @arr: the array
 * @n: array size
 * @orig: the original bounds of the array
 * @osize: the original size of the array
 * Return: returns
 */

static size_t partition(int *arr, size_t n, int *orig, size_t osize)
{
	int pivot, temp;
	size_t i = 0, j;

	pivot = arr[n - 1];

	for (j = 0; j < n - 1; j++)
	{
		if (arr[j] < pivot)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			print_array(orig, osize);
		}
	}
	temp = arr[i];
	arr[i] = arr[n - 1];
	arr[n - 1] = temp;
	return (i);
}


/**
 * quick_sort - uses quick sort (splits the array up using a pivot and go)
 * @array: the array
 * @size: the sizeof the array
 */

void quick_sort(int *array, size_t size)
{
	size_t pivot;
	static int *original;
	static size_t orig_size;

	if (!original)
	{
		original = array;
		orig_size = size;
	}

	/*base case!*/
	if (size <= 1)
		return;

	pivot = partition(array, size, original, orig_size);

	quick_sort(array, pivot);
	quick_sort(array + pivot + 1, size - pivot - 1);
}
