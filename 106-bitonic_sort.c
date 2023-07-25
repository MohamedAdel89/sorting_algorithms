#include "sort.h"
<<<<<<< HEAD
void compare_swap_down(int *array_init, int *array, size_t size_init, size_t size, int *flag)
{
	int n;
	size_t i;
	(void)array_init;

	//printf("compare_down\n");
	if (flag[0] == 0)
	{
		for (i = 0; i < size/2 ; i++)
		{
			if (array[0] < array[size - 1])
			{
				n = array[0];
				array[0] = array[size - 1];
				array[size - 1] = n;
				printf("Result [%lu/%lu] (DOWN):\n", size, size_init);
				print_array(array, size);
			}
		}
	}
}
void compare_swap_up(int *array_init, int *array, size_t size_init, size_t size, int *flag)
{
	int n;
	size_t i;
	(void)array_init;

	//printf("size up:%lu\n", size);
	//printf("array[0] up:%d\n", array[0]);
	//printf("array[size-1] up:%d\n", array[size-1]);
	//printf("compare_up\n");
	if (flag[0] == 0)
	{
		for (i = 0; i < size/2 ; i++)
		{
		if (array[0] > array[size - 1])
		{
			n = array[0];
			array[0] = array[size - 1];
			array[size - 1] = n;
			printf("Result [%lu/%lu] (UP):\n", size, size_init);
			print_array(array, size);
		}
		}
	}
}
void bitonic_deep_down(int *array_init, int *array, size_t size_init, size_t size, int *flag)
{
	(void)array;

	//printf("deep_down_pre, size:%lu\n", size);
	if (size < 2)
	{
		flag[0] = 0;
		return;
	}
	//printf("deep_down:i=%lu\n", i);
	printf("Merging [%lu/%lu] (DOWN):\n", size, size_init);
	print_array(array, size);
	bitonic_deep_up(array_init, array, size_init, size / 2, flag);
	compare_swap_up(array_init, array, size_init, size, flag);
	//flag[0] = 0;
	bitonic_deep_down(array_init, array + (size/2), size_init, size / 2, flag);
	//flag[0] = 1;
	compare_swap_down(array_init, array, size_init, size, flag);
	//compare_swap(array, 0, i);
	//printf("despues de swap\n");
	//print_array(array, size);
}
void bitonic_deep_up(int *array_init, int *array, size_t size_init, size_t size, int *flag)
{
	(void)array;

	//printf("deep_up_pre, size:%lu\n", size);
	if (size < 2)
	{
		flag[0] = 0;
		return;
	}
	//printf("deep_up:i=%lu\n", i);
	printf("Merging [%lu/%lu] (UP):\n", size, size_init);
	print_array(array, size);
	bitonic_deep_up(array_init, array, size_init, size / 2, flag);
	compare_swap_up(array_init, array, size_init, size, flag);
	bitonic_deep_down(array_init, array + (size/2), size_init, size / 2, flag);
	compare_swap_down(array_init, array, size_init, size, flag);
	//flag[0] = 1;
	//compare_swap(array, 0, i);
	//printf("despues de swap\n");
	//print_array(array, size);
}
/**
 *
 *
 *
 *
 **/
void bitonic_sort(int *array, size_t size)
{
	size_t size_init = size;
	int *array_init = array;
	int *flag;
	int aux = {0};

	flag = &aux;
	if (array)
	{
		bitonic_deep_up(array_init, array, size_init, size, flag);
	}	
=======
#include <stdio.h>
/**
 * swap - change two values in ascending or descending order
 * @arr: array
 * @item1: item one
 * @item2: item two
 * @order: 1: ascending order, 0 descending order
 */
void swap(int arr[], int item1, int item2, int order)
{
	int temp;

	if (order == (arr[item1] > arr[item2]))
	{
		temp = arr[item1];
		arr[item1] = arr[item2];
		arr[item2] = temp;
	}
}
/**
 * merge - sort bitonic sequences recursively in both orders
 * @arr: array
 * @low: first element
 * @nelemnt: elements number
 * @order: 1: ascending order, 0 descending order
 */
void merge(int arr[], int low, int nelemnt, int order)
{
	int mid, i;

	if (nelemnt > 1)
	{
		mid = nelemnt / 2;
		for (i = low; i < low + mid; i++)
			swap(arr, i, i + mid, order);
		merge(arr, low, mid, order);
		merge(arr, low + mid, mid, order);
	}
}
/**
 * bitonicsort - bitonic sort algorithm implementation
 * @arr: array
 * @low: first element
 * @nelemnt: number of elements
 * @order: 1: ascending order, 0 descending order
 * @size: array lenght
 */
void bitonicsort(int arr[], int low, int nelemnt, int order, int size)
{
	int mid;

	if (nelemnt > 1)
	{
		if (order >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		mid = nelemnt / 2;
		bitonicsort(arr, low, mid, 1, size);
		bitonicsort(arr, low + mid, mid, 0, size);
		merge(arr, low, nelemnt, order);
		if (order <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		if (order >= 1)
		{
			printf("Result [%i/%i] (UP):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
	}
}
/**
 * bitonic_sort - prepare the terrain to bitonic sort algorithm
 * @array: array
 * @size: array lenght
 */
void bitonic_sort(int *array, size_t size)
{
	int order = 1;

	if (!array || size < 2)
		return;
	bitonicsort(array, 0, size, order, size);
>>>>>>> 8bf78a8a3c823a0d3568aa62b671911df92ef5ff
}
