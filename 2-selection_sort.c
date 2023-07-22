#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order using
 * the Selection sort algorithm.
 *
 * @array: Pointer to the array to sort.
 * @size: Size of the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, k;
	int temp, flag;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		temp = array[i];
		flag = 0;

		/* Find the index of the minimum element in the unsorted part of the array */
		for (j = i; j < size; j++)
		{
			if (array[j] < temp)
			{
				k = j;
				temp = array[j];
				flag = 1;
			}
		}

		/* Swap the minimum element with the first element of the unsorted part */
		if (flag == 1)
		{
			array[k] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
