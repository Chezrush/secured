/*
** EPITECH PROJECT, 2024
** my_str_upper.c
** File description:
** my_str_upper
*/

#include <stdio.h>
#include <stdlib.h>

char *my_str_upper(char *str)
{
    char c = 'a';

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            c = str[i] - ('a' - 'A');
            str[i] = c;
        }
    }
    return str;
}
