#include "sort.h"
<<<<<<< HEAD
/**
 * bubble_sort - sorts an array of integers in ascending order using
 * the Bubble sort algorithm
 * @array: pointer to array
 * @size: size of the array
 **/
void bubble_sort(int *array, size_t size)
{
	size_t i, j, n;

	for (i = 0; i < size; i++)
	{
		for (j = 1; j < size - i; j++)
		{
			if (array[j - 1] > array[j])
			{
				n = array[j];
				array[j] = array[j - 1];
				array[j - 1] = n;
=======

/**
  * bubble_sort - A function for bubble sorting.
  * @array: The array to sort.
  * @size: THe length of the aaray.
  * Return: Nothing.
  */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	int aux = 0;

	if (array == NULL || size == 0)
		return;
	for (; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				aux = array[j + 1];
				array[j + 1] = array[j];
				array[j] = aux;
>>>>>>> 8bf78a8a3c823a0d3568aa62b671911df92ef5ff
				print_array(array, size);
			}
		}
	}
}
