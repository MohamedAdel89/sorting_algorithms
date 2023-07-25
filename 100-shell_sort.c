#include "sort.h"
<<<<<<< HEAD
/**
 * shell_sort -  sorts an array of integers in
 * ascending order using the Shell sort algorithm,
 * using the Knuth sequence
 * @array: pointer to array
 * @size: size of the array
 **/
void shell_sort(int *array, size_t size)
{
	size_t kunth[1000], k = 0, j = 0, i;
	int n, j2;

	if (!array)
		return;
	while (j * 3 + 1 < size)
	{
		kunth[k] = j * 3 + 1;
		j = kunth[k++];
	}
	for (i = 0; i < k; i++)
	{
		for (j = 0; j < size; j++)
		{
			if ((j + kunth[k - i - 1]) > size - 1)
				break;
			j2 = j;
			while (array[j2] > array[j2 + kunth[k - i - 1]])
			{
				n = array[j2];
				array[j2] =  array[j2 + kunth[k - i - 1]];
				array[j2 + kunth[k - i - 1]] = n;
				j2 = j2 - kunth[k - i - 1];
				if (j2 < 0)
					break;
			}
		}
		print_array(array, size);
=======

/**
*swap - the positions of two elements into an array
*@array: array
*@item1: array element
*@item2: array element
*/
void swap(int *array, int item1, int item2)
{

	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}
/**
 * shell_sort - function that sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @size: size of the array
 * @array: list with numbers
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, index = 0;

	if (array == NULL || size < 2)
		return;
	while (gap < size / 3)
		gap = 3 * gap + 1;
	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
			for (index = i; index >= gap &&
			 (array[index] < array[index - gap]); index -= gap)
				swap(array, index, index - gap);
		print_array(array, size);
		gap /= 3;
>>>>>>> 8bf78a8a3c823a0d3568aa62b671911df92ef5ff
	}
}
