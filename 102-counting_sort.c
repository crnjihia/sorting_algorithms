#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: the array
 * @size: the size of the array
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	unsigned long i;
	int j, max = 0;
	int *count_array, *sorted_array;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];

	count_array = calloc(max + 1, sizeof(int));
	if (!count_array)
		return;

	for (i = 0; i < size; i++)
		count_array[array[i]] += 1;

	for (j = 1; j < max + 1; j++)
		count_array[j] += count_array[j - 1];

	print_array(count_array, max + 1);

	sorted_array = malloc(size * sizeof(int));
	if (!sorted_array)
	{
		free(count_array);
		return;
	}
	for (j = size - 1; j >= 0; j--)
	{
		i = count_array[array[j]];
		sorted_array[i - 1] = array[j];
		count_array[array[j]] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = sorted_array[i];
	free(count_array);
	free(sorted_array);
}
