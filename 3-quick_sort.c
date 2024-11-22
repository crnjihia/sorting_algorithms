#include "sort.h"
/**
*swap - Exchanges the positions of two items within an array
*@array: Target array
*@item1: First element to be swapped
*@item2: Second element to be swapped
*/

void swap(int *array, ssize_t item1, ssize_t item2)
{
	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}
/**
 *lomuto_partition - Implements the Lomuto partitioning scheme
 *@array: Array to be partitioned
 *@first: Starting index of the partition
 *@last: Ending index of the partition
 *@size: Total number of elements in the array
 *Return: Index of the pivot element after partitioning
 */
int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
	int pivot = array[last];
	ssize_t current = first, finder;

	for (finder = first; finder < last; finder++)
	{
		if (array[finder] < pivot)
		{
			if (array[current] != array[finder])
			{
				swap(array, current, finder);
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[last])
	{
		swap(array, current, last);
		print_array(array, size);
	}
	return (current);
}
/**
 *qs - Recursive implementation of the quicksort algorithm
 *@array: Array to be sorted
 *@first: Starting index of the subarray
 *@last: Ending index of the subarray
 *@size: Total number of elements in the array
 */
void qs(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;


	if (first < last)
	{
		position = lomuto_partition(array, first, last, size);

		qs(array, first, position - 1, size);
		qs(array, position + 1, last, size);
	}
}
/**
 *quick_sort - Initiates the quicksort process on the given array
 *@array: Array to be sorted
 *@size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}
