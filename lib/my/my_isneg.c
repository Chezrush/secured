/*
** EPITECH PROJECT, 2024
** my_print_alpha
** File description:
** my_print_alpha.c
*/

#include <unistd.h>
#include "my.h"

int my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    else
        my_putchar('P');
    return 0;
}
