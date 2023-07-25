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
	int array[0];
=======
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
>>>>>>> 8bf78a8a3c823a0d3568aa62b671911df92ef5ff
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	bubble_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
