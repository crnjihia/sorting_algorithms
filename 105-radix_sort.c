#include "sort.h"

/**
 * getMax - get maximum
 *
 * @array: array
 * @size: n
 *
 * Return: max
 */
int getMax(int *array, size_t size)
{
	int max;
	size_t i;

	max = *array;
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * countingSort - get maximum
 *
 * @arr: array
 * @n: size
 * @place: place
 *
 * Return: void
 */
void countingSort(int *arr, size_t n, int place)
{
	int *output, i, count[10] = { 0 };
	size_t j;

	output = malloc(sizeof(int) * n);
	if (output == NULL)
		return;
	for (j = 0; j < n; j++)
		count[(arr[j] / place) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (j = 0; j < n; j++)
	{
		output[count[(arr[n - 1 - j] / place) % 10] - 1] = arr[n - 1 - j];
		count[(arr[n - 1 - j] / place) % 10]--;
	}
	for (j = 0; j < n; j++)
		arr[j] = output[j];
	free(output);
	print_array(arr, n);
}

/**
 * radix_sort - sorts an array of integers in ascending order using
 * @array: an array of integers
 * @size: size of the array
 *
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int max, place;

	if (size > 1)
	{
		max = getMax(array, size);

		for (place = 1; (max / place) > 0; place *= 10)
		{
			countingSort(array, size, place);
		}
	}
}
