<<<<<<< HEAD
=======
#include <stdio.h>
#include <stdlib.h>
>>>>>>> 8bf78a8a3c823a0d3568aa62b671911df92ef5ff
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
<<<<<<< HEAD
	int array[] = {5, -3, -5, -5, -3};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	selection_sort(array, n);
	printf("\n");
	print_array(array, n);
=======
	int array1[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	int array2[] = {2};
	size_t n = sizeof(array1) / sizeof(array1[0]);

	print_array(array1, n);
	printf("\n");
	selection_sort(array1, n);
	printf("\n");
	print_array(array1, n);

	selection_sort(array2, 1);
	printf("\n");
	print_array(array2, 1);
>>>>>>> 8bf78a8a3c823a0d3568aa62b671911df92ef5ff
	return (0);
}
