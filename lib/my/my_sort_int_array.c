/*
** EPITECH PROJECT, 2024
** test.c
** File description:
** test.c
*/

#include "my.h"

void swap_numb(int *nb1, int *nb2)
{
    if (*nb1 > *nb2)
        my_swap(nb1, nb2);
}

void my_sort_int_array(int *array, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            swap_numb(&array[j], &array[j + 1]);
        }
    }
}
