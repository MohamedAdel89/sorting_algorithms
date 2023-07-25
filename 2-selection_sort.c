#include "sort.h"
/**
<<<<<<< HEAD
 * selection_sort - sorts an array of integers in ascending order using
 * the Selection sort algorithm
 * @array: pointer to array
 * @size: size of the array
 **/
void selection_sort(int *array, size_t size)
{
	size_t i, j, n, k;
	int aux, flag;

	if (array)
	{
		for (i = 0; i < size; i++)
		{
			aux = array[i];
			flag = 0;
			for (j = i; j < size ; j++)
			{
				if (array[j] < aux)
				{
					k = j;
					aux = array[j];
					flag = 1;
				}
			}
			if (flag == 1)
			{
				n = array[i];
				array[i] = array[k];
				array[k] = n;
				print_array(array, size);
			}
		}
=======
 * selection_sort - function that sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @size: size of the array
 * @array: list with numbers
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
>>>>>>> 8bf78a8a3c823a0d3568aa62b671911df92ef5ff
	}
}
