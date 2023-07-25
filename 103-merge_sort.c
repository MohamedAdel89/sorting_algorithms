#include "sort.h"
<<<<<<< HEAD
/**
 * merge - merges l and r arrays into original array
 * @array: pointer to array
 * @size: size of the array
 * @l: pointer to left array
 * @r: pointer to right array
 **/
void merge(int *array, int *l, int *r, size_t size)
{
	int i = 0, j = 0, k = 0;
	int size_l, size_r;

	size_l = size / 2;
	size_r = size - size_l;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(l, size_l);
	printf("[right]: ");
	print_array(r, size_r);

	while (i < size_l && j < size_r)
	{
		if (l[i] < r[j])
			array[k++] = l[i++];
		else
			array[k++] = r[j++];
	}

	while (i < size_l)
		array[k++] = l[i++];

	while (j < size_r)
		array[k++] = r[j++];
	printf("[Done]: ");
	print_array(array, size);
}
/**
 * merge_sort - sorts an array of integers in ascending order using
 * the Merge sort algorithm
 * @array: pointer to array
 * @size: size of the array
 **/
void merge_sort(int *array, size_t size)
{
	size_t mid = 0, i;
	int left[1000];
	int right[1000];

	if (!array)
		return;

	if (size < 2)
		return;

	mid = size / 2;
	/*left = (int*)malloc(sizeof(int) * mid);*/
	/*right = (int*)malloc(sizeof(int) * (size - mid));*/

	for (i = 0; i < mid; i++)
		left[i] = array[i];

	for (i = mid; i < size; i++)
		right[i - mid] = array[i];

	merge_sort(left, mid);
	merge_sort(right, size - mid);
	merge(array, left, right, size);
=======
#include <stdlib.h>
#include <stdio.h>

/**
* TDMerge - sorts and merges the sub arrays
* @start: starting index
* @middle: end index
* @end: end index
* @dest: destination for the data
* @source: source of the data
*
* Return: void
*/
void TDMerge(size_t start, size_t middle, size_t end, int *dest, int *source)
{
	size_t i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(source + start, middle - start);
	printf("[right]: ");
	print_array(source + middle, end - middle);
	i = start;
	j = middle;
	for (k = start; k < end; k++)
	{
		if (i < middle && (j >= end || source[i] <= source[j]))
		{
			dest[k] = source[i];
			i++;
		}
		else
		{
			dest[k] = source[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(dest + start, end - start);
}

/**
* TDSplitMerge - recursively splits the array, merge and sort
* @start: starting index (inclusive)
* @end: end index (exclusive)
* @array: the array to sort
* @clone: a clone of the array
*/
void TDSplitMerge(size_t start, size_t end, int *array, int *clone)
{
	size_t middle;

	if (end - start < 2)
		return;
	middle = (start + end) / 2;
	TDSplitMerge(start, middle, array, clone);
	TDSplitMerge(middle, end, array, clone);
	TDMerge(start, middle, end, array, clone);
	for (middle = start; middle < end; middle++)
		clone[middle] = array[middle];
}

/**
* merge_sort - sorts an array of integers
* Merge sort algorithm
* @array: array to sort
* @size: size of the array
*
* Return: void
*/
void merge_sort(int *array, size_t size)
{
	size_t i;
	int *clone;

	if (array == NULL || size < 2)
		return;
	clone = malloc(sizeof(int) * size);
	if (clone == NULL)
		return;
	for (i = 0; i < size; i++)
		clone[i] = array[i];
	TDSplitMerge(0, size, array, clone);
	free(clone);
>>>>>>> 8bf78a8a3c823a0d3568aa62b671911df92ef5ff
}
