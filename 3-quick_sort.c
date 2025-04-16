#include "sort.h"

/**
 * swap - swaps two elements in an array
 * @a: first int
 * @b: second int
 */
void swap(int *a, int *b)
{
int tmp = *a;
*a = *b;
*b = tmp;
}

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: array of integers
 * @low: start index
 * @high: end index
 * @size: size of array (for printing)
 * Return: pivot index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1, j;

for (j = low; j < high; j++)
{
if (array[j] < pivot)
{
i++;
if (i != j)
{
swap(&array[i], &array[j]);
print_array(array, size);
}
}
}
if (i + 1 != high)
{
swap(&array[i + 1], &array[high]);
print_array(array, size);
}
return (i + 1);
}

/**
 * quicksort_recursive - helper function for quick sort
 * @array: array of integers
 * @low: starting index
 * @high: ending index
 * @size: array size
 */
void quicksort_recursive(int *array, int low, int high, size_t size)
{
if (low < high)
{
int pi = lomuto_partition(array, low, high, size);

quicksort_recursive(array, low, pi - 1, size);
quicksort_recursive(array, pi + 1, high, size);
}
}

/**
 * quick_sort - quick sort with Lomuto partition
 * @array: array of integers
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
if (!array || size < 2)
return;
quicksort_recursive(array, 0, size - 1, size);
}
