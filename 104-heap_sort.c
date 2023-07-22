#include <stddef.h>
#include <stdint.h>
#include "sort.h"

#define PARENT(i) (((i) - 1) / 2)
#define LEFT(i) (2 * (i) + 1)
#define RIGHT(i) (2 * (i) + 2)

/**
 * sift_down - Sift down a node in the heap to maintain the max-heap property.
 * @array: The array containing the heap.
 * @size: The total size of the array.
 * @index: The index of the current node in the heap.
 * @end: The index of the last node in the heap to examine.
 */
void sift_down(int *array, size_t size, size_t index, size_t end)
{
	size_t largest, left, right;

	do {
		left = LEFT(index);
		right = RIGHT(index);
		largest = index;

		if (right <= end && array[right] > array[index])
			largest = right;
		if (array[left] > array[largest])
			largest = left;

		if (index == largest)
			return;

		/* Swap elements to maintain the max-heap property */
		int tmp = array[index];
		array[index] = array[largest];
		array[largest] = tmp;

		print_array(array, size);

		index = largest;
	} while (LEFT(index) <= end);
}

/**
 * heap_sort - Sorts an array of integers in ascending order using the Heap sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	size_t node, sorted;

	if (array == NULL || size < 2)
		return;

	/* Build the max-heap from the array */
	for (node = PARENT(size - 1); node != (size_t)(-1); node--)
		sift_down(array, size, node, size - 1);

	/* Sort the array in ascending order using the max-heap */
	for (sorted = size - 1; sorted > 0; sorted--)
	{
		/* Swap the first (largest) element with the last element */
		int tmp = array[0];
		array[0] = array[sorted];
		array[sorted] = tmp;

		print_array(array, size);

		/* Rebuild the max-heap for the remaining elements */
		sift_down(array, size, 0, sorted - 1);
	}
}
