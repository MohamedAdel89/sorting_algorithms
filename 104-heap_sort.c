#include "sort.h"
<<<<<<< HEAD
/**
 * check_tree - swiftdown check
 * @array: pointer to array
 * @size: size of the pointer
 * @size_init: original size of the array
 * @i: index as a root of the tree
 *
**/
void check_tree(int *array, size_t size_init, size_t size, size_t i)
{

	int n, branch1, branch2;
	size_t br1, br2;

	br1 = i * 2 + 1;
	br2 = br1 + 1;
	branch1 = array[br1];
	branch2 = array[br2];
	if (((br1 < size) && (br2 < size) &&
		(branch1 >= branch2 && branch1 > array[i]))
		|| ((br1 == size - 1) && branch1 > array[i]))
	{
		n = array[i];
		array[i] = branch1;
		array[br1] = n;
		print_array(array, size_init);
	}
	else if ((br1 < size) && (br2 < size) &&
		(branch2 > branch1 && branch2 > array[i]))
	{
		n = array[i];
		array[i] = branch2;
		array[br2] = n;
		print_array(array, size_init);
	}
	if (br1 < size - 1)
		check_tree(array, size_init, size, br1);
	if (br2 < size - 1)
		check_tree(array, size_init, size, br2);
}
/**
 * heap_sort - sorts an array of integers
 * in ascending order using the Heap
 * sort algorithm
 * @array: pointer to array
 * @size: size of the pointer
 *
**/
void heap_sort(int *array, size_t size)
{
	size_t i, size_init = size;
	int n;

	if (!array)
		return;
	for (i = 0; i < size / 2 ; i++)
	{
		check_tree(array, size_init, size, size / 2 - 1 - i);
	}
	for (i = 0; i < size_init - 1; i++)
	{
		n = array[0];
		array[0] = array[size - 1 - i];
		array[size - 1 - i] = n;
		print_array(array, size_init);
		check_tree(array, size_init, size - i - 1, 0);
	}

=======

/**
* sift_down - fixes a heap
* @array: the heap to be fixed
* @root: root of heap
* @end: ;ast index of the heap
* @size: size of the array
*/
void sift_down(int *array, size_t root, size_t end, size_t size)
{
	size_t left, right, swap;
	int temp;

	while ((left = (2 * root) + 1) <= end)
	{
		swap = root;
		right = left + 1;
		if (array[swap] < array[left])
			swap = left;
		if (right <= end && array[swap] < array[right])
			swap = right;
		if (swap == root)
			return;
		temp = array[root];
		array[root] = array[swap];
		array[swap] = temp;
		print_array(array, size);
		root = swap;
	}
}

/**
* make_heap - makes a heap from an unsorted array
* @array: array to turn into a heap
* @size: size of the array
*
* Return: void
*/
void make_heap(int *array, size_t size)
{
	size_t parent;

	for (parent = ((size - 1) - 1) / 2; 1; parent--)
	{
		sift_down(array, parent, size - 1, size);
		if (parent == 0)
			break;
	}
}

/**
* heap_sort - sorts an array of ints in ascending order w/ the Heap sort algo
* @array: array to sort
* @size: size of the array
*
* Return: void
*/
void heap_sort(int *array, size_t size)
{
	size_t end;
	int temp;

	if (array == NULL || size < 2)
		return;
	make_heap(array, size);
	end = size - 1;
	while (end > 0)
	{
		temp = array[end];
		array[end] = array[0];
		array[0] = temp;
		print_array(array, size);
		end--;
		sift_down(array, 0, end, size);
	}
>>>>>>> 8bf78a8a3c823a0d3568aa62b671911df92ef5ff
}
