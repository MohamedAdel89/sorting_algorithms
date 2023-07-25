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
	int array[] = {100, 93, 40, 57, 14, 58, 85, 54, 31, 56, 46, 39, 15, 26, 78, 13};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	bitonic_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
