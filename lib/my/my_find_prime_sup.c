/*
** EPITECH PROJECT, 2024
** my_find_prime_sup.c
** File description:
** my_find_prime_sup.c
*/

#include "my.h"

int my_find_prime_sup(int n)
{
    int i = n;
    int is_prime = 0;

    while (i < 2147483647) {
        is_prime = my_is_prime(i);
        if (is_prime == 1)
            return i;
        i++;
    }
    return 0;
}
