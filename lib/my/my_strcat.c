/*
** EPITECH PROJECT, 2024
** my_strcat.c
** File description:
** my_strcat
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int len = my_strlen(dest);

    for (; i < src[i]; i++)
        dest[len + i] = src[i];
    dest[len + i] = '\0';
    return dest;
}
