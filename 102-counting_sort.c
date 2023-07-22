#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *count_arr, *output;
	int k = 0; /* k is the largest number in the array */
	size_t i, j;

	if (array == NULL || size <= 1)
		return;

	/* Find the largest number in the array */
	for (i = 0; i < size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}

	count_arr = malloc((k + 1) * sizeof(int));
	output = malloc(size * sizeof(int));
	if (count_arr == NULL || output == NULL)
	{
		free(count_arr);
		free(output);
		return;
	}

	/* Initialize count_arr with zeros */
	for (i = 0; i <= (size_t)k; i++)
		count_arr[i] = 0;

	/* Count the occurrences of each number in the array */
	for (i = 0; i < size; i++)
		count_arr[array[i]]++;

	/* Accumulate the count to get the correct positions */
	for (i = 1; i <= (size_t)k; i++)
		count_arr[i] += count_arr[i - 1];

	/* Build the output array using count_arr */
	for (j = size - 1; (int)j >= 0; j--)
	{
		output[count_arr[array[j]] - 1] = array[j];
		count_arr[array[j]]--;
	}

	/* Copy the sorted elements back to the original array */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	/* Print the counting array */
	print_array(count_arr, k + 1);

	free(count_arr);
	free(output);
}
