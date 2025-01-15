/*
** EPITECH PROJECT, 2024
** test.c
** File description:
** test.c
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return i;
}

char *my_revstr(char *str)
{
    int i = my_strlen(str);
    int j = 0;
    char tmp[i + 1];

    my_strcpy(tmp, str);
    for (; i >= 0; i--) {
        str[j] = tmp[i - 1];
        j++;
    }
    str[i] = '\0';
    return str;
}
