<<<<<<< HEAD
#include "sort.h"
=======
#include <stdio.h>
#include "sort.h"

>>>>>>> 8bf78a8a3c823a0d3568aa62b671911df92ef5ff
/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
<<<<<<< HEAD
	int i;

	i = 0;
	while (list)
	{
		if (i > 0)
			printf(", ");
		printf("%d", list->n);
		++i;
		list = list->next;
	}
	printf("\n");
=======
    int i;

    i = 0;
    while (list)
    {
        if (i > 0)
            printf(", ");
        printf("%d", list->n);
        ++i;
        list = list->next;
    }
    printf("\n");
>>>>>>> 8bf78a8a3c823a0d3568aa62b671911df92ef5ff
}
