#include "deck.h"
<<<<<<< HEAD
/**
 * aux_num_fun - turn into integer card value
 * @head_tmp1: pointer to the list
 * Return: integer rep
 **/
int aux_num_fun(deck_node_t *head_tmp1)
{
	int aux_num, j;
	int num[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
	char val[13] = {'A', '2', '3', '4', '5', '6', '7',
		'8', '9', '1', 'J', 'Q', 'K'};

	for (j = 0; j < 13; j++)
	{
		if (head_tmp1->card->value[0] == val[j])
			aux_num = num[j];
	}

	return (aux_num);
}
/**
 * num_sort - sorts a doubly linked list of integers, 4 stages
 * @list: pointer to the list head
 * Return: no return
 **/
void num_sort(deck_node_t **list)
{
	deck_node_t *head_tmp1, *head_tmp2, *aux1, *aux2;
	int flag = 0, i, aux_num1, aux_num2;
	unsigned int k;

	head_tmp1 = *list;
	head_tmp2 = *list;
	for (i = 0; i < 4; i++)
	{ k =  head_tmp1->card->kind;
		while (head_tmp1->next && head_tmp1->next->card->kind == k)
		{
			aux_num1 = aux_num_fun(head_tmp1);
			aux_num2 = aux_num_fun(head_tmp1->next);
			flag = 0;
			head_tmp2 = head_tmp1;
			while (head_tmp2 && head_tmp2->card->kind == k && aux_num1 > aux_num2)
			{
				aux1 = head_tmp2;
				aux2 = head_tmp2->next;
				aux1->next = aux2->next;
				if (aux2->next)
					aux2->next->prev = aux1;
				aux2->prev = aux1->prev;
				aux2->next = aux1;
				aux1->prev = aux2;
				if (aux2->prev)
					aux2->prev->next = aux2;
				head_tmp2 = aux2->prev;
				if (!aux2->prev)
					*list = aux2;
				flag = 1;
				if (!head_tmp2)
					break;
				aux_num1 = aux_num_fun(head_tmp2);
				aux_num2 = aux_num_fun(head_tmp2->next);
			}
			if (flag == 0)
				head_tmp1 = head_tmp1->next;
		}
		head_tmp1 = head_tmp1->next;
	}
}
/**
 * kind_sort - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort ailgorithm
 * @list: pointer to the list head
 * Return: no return
 **/
void kind_sort(deck_node_t **list)
{
	deck_node_t *head_tmp1, *head_tmp2, *aux1, *aux2;
	int flag;

	if (list)
	{
		head_tmp1 = *list;
		head_tmp2 = *list;
		while (list && head_tmp1->next)
		{
			if (head_tmp1->next)
			{
				flag = 0;
				head_tmp2 = head_tmp1;
				while (head_tmp2 && head_tmp2->card->kind > head_tmp2->next->card->kind)
				{
					aux1 = head_tmp2;
					aux2 = head_tmp2->next;
					aux1->next = aux2->next;
					if (aux2->next)
						aux2->next->prev = aux1;
					if (aux2)
					{
						aux2->prev = aux1->prev;
						aux2->next = aux1;
					}
					if (aux1)
						aux1->prev = aux2;
					if (aux2->prev)
						aux2->prev->next = aux2;
					head_tmp2 = aux2->prev;
					if (!aux2->prev)
						*list = aux2;
					flag = 1;
				}
			}
			if (flag == 0)
				head_tmp1 = head_tmp1->next;
		}
	}
}
/**
 * sort_deck - sorts a deck of cards
 * @deck: ponter to the deck
 * Return: no return
 *
 **/
void sort_deck(deck_node_t **deck)
{
	if (deck)
	{
		kind_sort(deck);
		num_sort(deck);
	}
}
=======
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
* get_val - gets value of a card from it's string value
* @str:  value of the card
*
* Return: relative value of the card (0 through 12)
*/
int get_val(const char *str)
{
	int i;
	char *array[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9",
			"10", "Jack", "Queen", "King"};

	for (i = 0; i < 13; i++)
	{
		if (strcmp(str, array[i]) == 0)
		{
			return (i);
		}
	}
	exit(1);
}

/**
* swap_node - swaps a node with
* @list: double pointer
* @node: node to be swaped
*
* Return: void
*/
void swap_node(deck_node_t **list, deck_node_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

/**
* sort_deck - sorts a linked list deck of cards
* @deck: double pointer to the deck to sort
*
* Return: void
*/
void sort_deck(deck_node_t **deck)
{
	char swapped = 1, c1, c2;
	deck_node_t *current;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;
	current = *deck;
	while (swapped != 0)
	{
		swapped = 0;
		while (current->next != NULL)
		{
			c1 = get_val(current->card->value) + 13 * current->card->kind;
			c2 = get_val(current->next->card->value) + 13 * current->next->card->kind;
			if (c1 > c2)
			{
				swap_node(deck, current);
				swapped = 1;
			}
			else
				current = current->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (current->prev != NULL)
		{
			c1 = get_val(current->card->value) + 13 * current->card->kind;
			c2 = get_val(current->prev->card->value) + 13 * current->prev->card->kind;
			if (c1 < c2)
			{
				swap_node(deck, current->prev);
				swapped = 1;
			}
			else
				current = current->prev;
		}
	}
}
>>>>>>> 8bf78a8a3c823a0d3568aa62b671911df92ef5ff
