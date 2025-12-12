#include "sort.h"

/**
* lomuto_partition - the lomuto partition that was mentinoed
* @array: the array
* @low: starting index
* @high: the end index
* @size: the size of the array
* Return: returns index of pivot after partition
*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j, tmp;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j]) /* avoid redundant swap */
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high]) /* final pivot swap */
	{
		tmp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
* quicksort_rec - Recursive quicksort
* @array: Array of integers
* @low: Starting index
* @high: Ending index
* @size: Size of array
*/

void quicksort_rec(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int p = lomuto_partition(array, low, high, size);

		quicksort_rec(array, low, p - 1, size);
		quicksort_rec(array, p + 1, high, size);
	}
}

/**
* quick_sort - Sorts an array of integers using Quick sort
* @array: Array of integers
* @size: Size of array
*/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicksort_rec(array, 0, (int)size - 1, size);
}
