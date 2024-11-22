#include "sort.h"
/**
 * selection_sort - Organizes an integer array in ascending order
 * utilizing the Selection sort method
 * @size: Length of the array
 * @array: Collection of numbers to be sorted
 */

void selection_sort(int *array, size_t size)
{
	size_t i, index;
	int tmp, swap, flag = 0;

	if (array == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		tmp = i;
		flag = 0;
		for (index = i + 1; index < size; index++)
		{
			if (array[tmp] > array[index])
			{
				tmp = index;
				flag += 1;
			}
		}
		swap = array[i];
		array[i] = array[tmp];
		array[tmp] = swap;
		if (flag != 0)
			print_array(array, size);
	}
}
