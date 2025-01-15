/*
** EPITECH PROJECT, 2024
** my_swap
** File description:
** my_swap.c
*/

void my_swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}
