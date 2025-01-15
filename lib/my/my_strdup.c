/*
** EPITECH PROJECT, 2024
** dgfhtghjy
** File description:
** ghghghgh
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *res = malloc(sizeof(char) * len);

    my_strcpy(res, src);
    return res;
}
