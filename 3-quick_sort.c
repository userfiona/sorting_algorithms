#include <stdio.h>

void print_array(int *array, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d", array[i]);
        if (i < size - 1)
        {
            printf(", ");
        }
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int *array, size_t size)
{
    int swapped;
    for (size_t i = 0; i < size - 1; i++)
    {
        swapped = 0;
        for (size_t j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
                swapped = 1;
            }
        }
        if (!swapped)
        {
            // If no elements were swapped in the inner loop, the array is already sorted
            break;
        }
        printf("After pass %zu: ", i + 1);
        print_array(array, size);
    }
}

int main(void)
{
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Original array: ");
    print_array(array, size);

    bubble_sort(array, size);

    printf("Sorted array: ");
    print_array(array, size);

    return 0;
}
