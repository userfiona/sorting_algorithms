#include "deck.h"

/**
 * aux_num_fun - Convert card value into an integer.
 * @head_tmp1: Pointer to the list.
 * Return: Integer representation of the card value.
 **/
int aux_num_fun(deck_node_t *head_tmp1)
{
    /* ... Function implementation ... */
}

/**
 * num_sort - Sort a doubly linked list of integers in 4 stages.
 * @list: Pointer to the list head.
 * Return: No return.
 **/
void num_sort(deck_node_t **list)
{
    /* ... Function implementation ... */
}

/**
 * kind_sort - Sort a doubly linked list of integers in ascending order
 *             using the Insertion sort algorithm.
 * @list: Pointer to the list head.
 * Return: No return.
 **/
void kind_sort(deck_node_t **list)
{
    /* ... Function implementation ... */
}

/**
 * sort_deck - Sorts a deck of cards.
 * @deck: Pointer to the deck.
 * Return: No return.
 **/
void sort_deck(deck_node_t **deck)
{
    if (deck)
    {
        kind_sort(deck);
        num_sort(deck);
    }
}
