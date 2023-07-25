<<<<<<< HEAD
#include "sort.h"
=======
#include <stdlib.h>
#include <stdio.h>

>>>>>>> 8bf78a8a3c823a0d3568aa62b671911df92ef5ff
/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
<<<<<<< HEAD
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
=======
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
>>>>>>> 8bf78a8a3c823a0d3568aa62b671911df92ef5ff
}
